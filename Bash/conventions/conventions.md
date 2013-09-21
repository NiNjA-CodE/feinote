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



