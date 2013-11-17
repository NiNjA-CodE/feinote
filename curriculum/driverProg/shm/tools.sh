#!/usr/bin/env bash

# =============================================================================
# 
# =============================================================================



# =============================================================================
# Functions
# =============================================================================

function prompt() {
	echo 'input following commands:'
	echo '========================='
	echo ' ./tools.sh -b [--bigfile] : create 1000M-bulked bigfile nameed "bigfile"'
	echo ' ./tools.sh -c [--compile] : compile all source file'
	echo ' ./tools.sh -t [--test]    : test and redirect info to file testReoprt '
	echo ' ./tools.sh -s [--stdio]   : process bigfile with standard io'
	echo ' ./tools.sh -m [--mmap]    : process bigfile with memory map'
}

function bigfile() {
	dd if=/dev/zero of=bigfile bs=1M count=1000
}

function compile() {
	gcc -o mmap mmap.c
	gcc -o stdio stdio.c --std=c99
}

function stdio() {
	echo 'stdio'

}

function mmap() {
	echo 'mmap'

}

function mktest() {
	echo 'This test will take some time, please wait patiently'

	> testReport
	./statistic.sh 2>&1 |tee -a testReport
}

# =============================================================================
# Logical
# =============================================================================

[[ $# -ge 2 ]] && {
	echo 'Too many parameters!'
}

case $1 in
	"-b"|"--bigfile")
		bigfile
		;;
	"-c"|"--compile")
		compile
		;;
	"-t"|"--test")
		mktest
		;;
	"-s"|"--stdio")
		stdio
		;;
	"-m"|"--mmap")
		mmap
		;;
	*)
		prompt
		;;
esac



