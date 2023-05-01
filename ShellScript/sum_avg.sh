#!/bin/bash

# Prompt the user to enter 5 numbers
echo "Enter five numbers:"
read num1 num2 num3 num4 num5

# Calculate the sum
sum=$(expr $num1 + $num2 + $num3 + $num4 + $num5)

# Calculate the average
avg=$(expr $sum / 5)

# Display the sum and average
echo "The sum of the numbers is: $sum"
echo "The average of the numbers is: $avg"
