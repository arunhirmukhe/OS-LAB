#!/bin/bash

# Prompt the user to enter three numbers
echo "Enter three numbers:"
read num1
read num2
read num3

# Initialize the largest and smallest variables
largest=$num1
smallest=$num1

# Find the largest number
if [ $num2 -gt $largest ]
then
    largest=$num2
fi

if [ $num3 -gt $largest ]
then
    largest=$num3
fi

# Find the smallest number
if [ $num2 -lt $smallest ]
then
    smallest=$num2
fi

if [ $num3 -lt $smallest ]
then
    smallest=$num3
fi

# Display the results
echo "Largest number is: $largest"
echo "Smallest number is: $smallest"
