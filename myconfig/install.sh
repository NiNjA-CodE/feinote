#!/usr/bin/env bash

#install.sh:install my customed configuration

#backup original .vimrc config
if [[ -f ~/.vimrc || -h ~/.vimrc ]];then
	mv ~/.vimrc ~/.vimrc.orig
	echo "original .vimrc backed up!"
fi

if (cp ~/personalnote/myconfig/template/vimrc ~/.vimrc);then
	echo "updated to my customed config!"
fi


