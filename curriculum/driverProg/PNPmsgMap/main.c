#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAXMSG 100
#define SONAME "libfei.so"

/******************************************************************************
 *                               type definition                              *
 *****************************************************************************/

typedef void (* MsgHandler) (void);

struct MessageMapEntry {
				char ch;
				MsgHandler handler;
};

struct stat statbuf;
struct stat curstat;

struct MessageMapEntry MessageMap[MAXMSG];


/*---------------------------------------------------------------------------*/
/*                        seekFuncInSo()                                     */
/*---------------------------------------------------------------------------*/
MsgHandler
seekFuncInSo(const char* file,
								void* funcname,
								int mode
) {
				/* TODO: everytime check handler address will load lib,low efficiency */
				void* handle = dlopen(file, mode);
				MsgHandler gothandler = (MsgHandler) dlsym(handle, (char*)funcname);
				if (NULL == gothandler) {
								printf("no such function in the lib\n");
								return 0;
				}
				dlclose(handle);
				return gothandler;
}


/*---------------------------------------------------------------------------*/
/*                             readTuple()                                   */
/*---------------------------------------------------------------------------*/

/**
 * Read a line (a tuple) in the configure file
 *
 * @param i *conf  : the opened configure file
 * @param o *Msg   : message char got
 * @param o *name  : the function name got frome the file line
 *
 * @return  0=end of file; 1=not end of file
 */

int readTuple(FILE* file, char* Msg, char* name) {
			char buf[60];
			fgets(buf, 60, file);
			if (sscanf(buf, "%c %s", Msg, name) < 0) {
							return 0;
			}
			
			return 0;
}

/******************************************************************************
 *                            conf2MsgMap()                                     *
 *****************************************************************************/

void
conf2MsgMap() {

	/**
	 * headmarks
	 * ====================================
	 * Four steps:
	 * 1] read conf file,read all match infos (all)
	 * 2] fill message in MsgMap.1
	 * 3] according to the string in conf file,find dynamic lib address 
	 * 		filled into MsgMap.2
   * 4] for every trumpe in conf file ,do above step 2] & 3}
	 */
	char linebuf[60];
	char gotMsg;
	char gotName[50];

	/**
 	 * readFlag = 0 : end of file
 	 * readFlag = 1 : not end of file
 	 */
	int readFlag;
	int i = 0;

	/* open configure file */
	FILE* openedconf = fopen("./MsgMap.conf","r");

	/* set global MsgMap Table */
	while ((readFlag = readTuple(openedconf, &gotMsg, gotName)) && i<MAXMSG) {
				MessageMap[i].ch = gotMsg;
				MessageMap[i].handler = seekFuncInSo(SONAME, (void*)gotName, RTLD_LAZY);
				i++;
	};

	if (readFlag) {
				printf("exceed max message limit\n");
	} else if (!readFlag) {
				MessageMap[i].ch = '0';
				MessageMap[i].handler = NULL;
	}

}


/******************************************************************************
 *                             threadProc()                                  *
 *****************************************************************************/

void threadProc() {
				while(1) {
								stat("./MsgMap.conf", &curstat);
								if (curstat.st_mtime != statbuf.st_mtime) {
												statbuf = curstat;
												conf2MsgMap();
								}
				sleep(5);
				}
}





/******************************************************************************
 *                                  main()                                    *
 *****************************************************************************/

int main() {
				pthread_t id;
				char ch;

				stat("./MsgMap.conf", &statbuf);
				/* create thread to manage dynamic lib and check conf file update */
				pthread_create(&id, NULL, (void *)threadProc, NULL);

				/* main process to handle user request */
				/* wait for source config file complete! */
				printf("Press a Key: \n");
				while((ch=getchar())!='x') {
						int i = 0;
						while(MessageMap[i].ch) {
										if (MessageMap[i].ch == ch) {
														MessageMap[i].handler();
														break;
										}
										i++;
						}
				};
				pthread_join(id, NULL);
				return 0;
}
