#!/bin/bash

# Prompt the user to enter a file name
echo "Enter a file name:"
read filename

# Check if the file exists
if [ ! -e "$filename" ]
then
    echo "$filename does not exist"
    exit 1
fi

# Check if the file is a directory
if [ -d "$filename" ]
then
    echo "$filename is a directory"
# Check if the file is a regular file
elif [ -f "$filename" ]
then
    echo "$filename is a file"
# If the file is not a directory or a regular file, report that it is something else
else
    echo "$filename is something else"
fi
