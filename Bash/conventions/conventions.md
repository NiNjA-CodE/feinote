# bash conventional usage senario syntax 

## prompt to input

```
while true
do
	read -p "prompt infomations to user for input [Y/N] " RESP
	case $RESP in
	[yY])
		do action1
		break
		;;
	[nN])
		do action2
		break
		;;
	*)
		echo "please choose y or n."
		;;
	esac
done
```

this piece of code can make user to input certain options untill input right, then bash
do some actions correspondently

## aother appoach to relize if else sentence

```
[ -w $HOME/.bash_profile ] &&
	do action1 ||
	do action2
```
if condition satisfied do action1, if not do action 2

```
( ls | grep -E "fei|lun" ) &&
	do action1 &&
	do action2 &&
	do action3 &&
	...
```
if commands in "()" executed correctly,do action1/action2/action3...
using this syntax because it is hard to exexute multiple command in one condition if
not using this syntax appoach

```
[[ -f $HOME/.bash_profile || -h $HOME/.bash_profile ]] ||
	do action1 ||
	do action2 ||
	do action3 ||
	...
```
if commands in "()" or test condition not satisfied, do action1/action2/action3...

## 

