#My Shell Code Style

* if
* while
* for
* case
* read
* .
* source
* >
* function
* set/unset
* comment
* examples

##'if' statement

```
if [ condition ]
then
	statement
	if [ condition ];then
		statement
	fi
else
	statement
fi
```

* in outermost layer if statement,'then' in the second line
* inner if statement ,'then' and 'if' in the same line

##'while' statement

```
while condition
do
	statement
	if [ condition ];then
		statement
	if
done
```

##'for' statement

```
for sth in list
do
	statement
	for sth in list;do
		statement
	done
	if [ condition ];then
		statement2
	fi
done
```

##'case' statement

```
case $VAR
in
	regex)
		statement1
		break
		;;
	regex2)
		statement2
		break
		;;
	*)
		statement
esac
```

##comment


##examples

**example1**

user input and react corespondently



