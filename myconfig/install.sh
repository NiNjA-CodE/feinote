#!/usr/bin/env bash

#install.sh:install my customed configuration

#install packages
#be sure you have install git before execute this script
#

which git &> /dev/null
if [[ $? != 0 ]]
then 
	echo "you havn't install git\n
	please install git before execute this script"
	#exit #needn't exit 'cause will install later 
fi

#detect environment and install packages
cat /etc/issue | grep -E "Ubuntu|Debian" &> /dev/null
if [[ $? == 0 ]]
then
	sudo apt-get install zsh\
			tmux\
			vim\
			ctags\
			git\
			g++
fi

cat /etc/issue | grep -E "Fedora|CentOS" &> /dev/null
if [[ $? == 0 ]]
then
	sudo yum install zsh\
			tmux\
			vim\
			ctags\
			git\
			g++
fi

#install oh-my-zsh ( a coustomed zsh configuration )
#

#if not exsit file ".oh-my-zsh",then git clone repo from github to ~/.oh-my-zsh
ls -a | grep ".oh-my-zsh " &> /dev/null || 
	git clone https://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh

if [[ -f ~/.zshrc || -h ~/.zshrc ]]
then
	echo ".zshrc conf file exsit!\n
	backing up it to ~/.zshrc.pre"
	mv ~/.zshrc ~/.zshrc.pre
fi

echo "Using the oh my zsh template file and adding it to ~/.zshrc"
cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc

echo "Copying your current PATH and adding it to the end of ~/.zshrc for you"
echo "export PATH=\$PATH:$PATH" >> ~/.zshrc

echo "changing your default shell to zsh!!!!!!!"
chsh -s `which zsh`
#chsh -s $(which zsh) #this line has the same impact

/usr/bin/env zsh
source ~/.zshrc

#backup original configs and set new conf files
#

#.vimrc
if [[ -f ~/.vimrc || -h ~/.vimrc ]];
then
	mv ~/.vimrc ~/.vimrc.orig
	echo "original .vimrc backed up!"
fi

if (cp ~/mynote/myconfig/template/vimrc ~/.vimrc);
then
	echo "vim updated to my customed config!"
fi

#.tmux.conf
if [[ -f ~/.tmux.conf || -h ~/.tmux.conf ]];
then
	mv ~/.tmux.conf ~/.tmux.conf.orig
	echo "original .tmux.conf backed up!"
fi

cp ~/mynote/myconfig/template/tmux.conf ~/.tmux.conf &&
	echo "tmux updated to my customed config!"
