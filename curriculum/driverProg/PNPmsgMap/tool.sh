#!/usr/bin/env bash

# demo.sh : makefile-like function shell script

###############################################################################
# set global variables

SRC=`pwd`
LIB="${SRC}/lib"


###############################################################################
# prompt infoes

[[ $# -ge 2 ]] && echo 'Too many parameters '

[[ $# -eq 1 ]] || {
echo 'Input commands like below:'
echo '  * "./tool.sh --doc"    :check documentation'
echo '  * "./tool.sh --lib"    :compile src file under ./lib folder to ./lib/libfei.so'
echo '  * "./tool.sh --main"   :compile main.c to ./appMain'
echo '  * "./tool.sh --clean"  :delete all generated ELF files'
}


###############################################################################
# functions

function compile_main() {
	gcc -o appMain ${SRC}/main.c -lpthread -ldl
}

function compile_lib() {
	libfiles=`ls ${LIB}/*.c`
	gcc ${libfiles} -shared -fPIC -o ${LIB}/libfei.so 
}

function clean() {
	rm -rf appMain ./lib/libfei.so
}

function doc() {
	firefox 
}


################################################################################

case $1 in
	"--main")
		compile_main
		;;
	"--lib")
		compile_lib
		;;
	"--clean")
		clean
		;;
	"--doc")
		doc
		;;
	*)
		echo "Input ERROR!"
esac

