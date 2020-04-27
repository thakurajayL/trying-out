#!/bin/bash
if [ $# -lt  1 ]; then
	echo You have not entered argument
	echo exiting program now
	exit
fi
echo THANK YOU FOR ARGUMENT...
echo name of ur filr is $0 #0th argument is name of the shell script
echo Total number of arguments are $#
i=0
while [ $i -le $# ]
do
echo Argument $i #not printing args..Just printing number  
i=`expr $i + 1`
done
