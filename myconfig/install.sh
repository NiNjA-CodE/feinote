#!/usr/bin/env bash

#install.sh:install my customed configuration

#install packages

cat /etc/issue | grep -E "Ubuntu|Debian" &> /dev/null
if [[ $? == 0 ]]
then
	sudo apt-get install zsh\
			tmux\
			vim\
			ctags\
			g++
fi


cat /etc/issue | grep -E "Fedora|CentOS" &> /dev/null
if [[ $? == 0 ]]
then
	sudo yum install zsh\
			tmux\
			vim\
			ctags\
			g++
fi


#backup original .vimrc config
if [[ -f ~/.vimrc || -h ~/.vimrc ]];then
	mv ~/.vimrc ~/.vimrc.orig
	echo "original .vimrc backed up!"
fi

if (cp ~/mynote/myconfig/template/vimrc ~/.vimrc);then
	echo "vim updated to my customed config!"
fi


#backup original .tmux.conf config
if [[ -f ~/.tmux.conf || -h ~/.tmux.conf ]];then
	mv ~/.tmux.conf ~/.tmux.conf.orig
	echo "original .tmux.conf backed up!"
fi

if (cp ~/mynote/myconfig/template/tmux.conf ~/.tmux.conf);then
	echo "tmux updated to my customed config!"
fi
