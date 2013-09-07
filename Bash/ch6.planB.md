#archive and compress

##archive command tar

**tar options**

* -c `create archive file`
* -C `specify the path of extraction directory`
* -f `specify target tar file name,must followed by .tar file`
* -v or -vv `verbose:get more info`
* -r `add new file to a .tar file`
* -A `join two .tar file, the final .tar file specified first`
* -x `exact file from a .tar file`
* -u `update if the file is newer than the one in .tar file`
* -t `see the files in .tar file`
* -d `diff a file in .tar file and the replicate outside`
* -j `bzip2 format`
* -z `gzip format`
* --exclude [pATTERN]
* --exclude-vcs
* --delete `delete file in .tar`

**often use of tar**

* tar -cvf fei.tar file1 file2 file3
* tar -rvf original.tar new_file
* tar -Avf fei.tar lun.tar
* tar -f fei.tar --delete file1 file3
* tar -tvf fei.tar
* tar -xf fei.tar
* tar -xf fei.tar -C /path/to/extraction_directory
* tar -xf fei.tar file1 file3

* tar -zxvf fei.tar.gz
* tar -zxvf fei.tar.gz -C /path/to/extraction_directory
* tar -jxvf fei.tar.bz2
* tar -jxvf fei.tar.bz2 -C /path/to/extraction_directory
* tar -axvf fei.tar.gz [ -C /path/to/extraction_directory ]
* tar -axvf fei.tar.bz2 [ -C /path/to/extraction_directory ]


##compress command**

**gzip**




**bzip2**














