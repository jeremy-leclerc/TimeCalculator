#! bin/sh

#Script to list subdirectories within a given directory
#Must have 0-1 arguments, will produce error if # of arguments > 1
#If no argument is given script will execute on cwd

one=1
if [ $# -gt $one ] #check for too many args
then
	echo "ERROR: Too may arguments"
	exit 1
fi

if [ ! -d $1 ] #check for non-existent directory
then
	echo "ERROR: Directory does not exist"
	exit 1
else
	#execute command
	ls -l $1 | 
	egrep "^d" | 
	tr -s " " |
	cut -d " " -f 9 |
	rs
	exit $?
fi
