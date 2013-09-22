# bash conventional usage senario syntax 

1. Prompt to input
2. Another appoach to realize if else sentences
3. Detect system environment
4. Functions

##1. Prompt to input

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

you need not "[]" everytime,if a char and a string do the same action you can 
code like this:

```
#!/usr/bin/env bash

while true
do
	read -p "if in condition1,input 1/a/A/conditon1 
	if in condition2,input 2/b/B/condition2" RESP

	case $RESP in
	1|a|A|condition1)
		echo "condition1 selected correctly!"
		break
		;;
	2|b|B|condition2)
		echo "condition2 selected correctly!"
		break
		;;
	*)
		echo "input incorrectly,please input again!"
	esac
done
```

You can not use `"1|a|A|condition1")` (can not put regular expression in "")

You can not use `[1|a|A|condition1])` (can not put regular expression in ) enither

this piece of code can make user to input certain options untill input right, then bash
do some actions correspondently

##2. Another appoach to realize if else sentence

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

Another way to realize this:

```
( ls | grep -E "fei|lun" ) && {
		do action1
		do action2
		do action3
		...
}
```
Using brace!

```
[[ -f $HOME/.bash_profile || -h $HOME/.bash_profile ]] ||
	do action1 ||
	do action2 ||
	do action3 ||
	...
```

if commands in "()" or test condition not satisfied, do action1/action2/action3...

##3. Detect system environmet

Some software need to detect system enviroment,and then do different movement according
to different system environment conditions

There are some ways to detect environment,collecting below;

```
cat /ect/issue | grep -E "Ubuntu|Debian" &&
	do true_action ||
	do false_action
```




##4. Functions

function syntax like this:

```
function funcname() {
		sentence
}
```

You can write a serial actions into a function,and make the input of user as the 
parameter of the function, and using "while" "case" sentences for user_input-bash_action
like this:

```
function action1() {
		mydata=$1
		execute these codes when condition1
		process mydata using methold1
		do blablabla
}

function action2() {
		mydata=$1
		execute these codes when condition2
		process mydata using methold2
		do blablabla
}

function action3() {
		mydata=$1
		execute these codes when condition3
		process mydata using methold3
		do blablabla
}

while true
do
	# input how to do
	read -p "if you are in CONDITION1,please input 1 \n
			if you are in CONDITION2,please input 2 \n
			if you are in CONDITION3,please input 3" RESP

	# input what to do
	read -p "please input raw data you want to process!" USERDATA

	case $RESP in
	1|a|A|condition1)
		action1() $USERDATA
		break
		;;
	2|b|B|condition2)
		action2() $USERDATA
		break
		;;
	3|c|C|condition3)
		action3() $USERDATA
		break
		;;
	*)
		echo "input illegally,please input again!"
	esac
done
```
		
##5. 
