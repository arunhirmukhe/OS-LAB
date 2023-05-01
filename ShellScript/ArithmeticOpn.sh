#!/bin/bash

# Loop until the user chooses to exit
while true
do
    # Prompt the user to start the program
    echo "Do you want to start the program? (yes/no)"
    read answer

    # Check if the user wants to exit
    if [ "$answer" = "no" ]
    then
        break
    fi

    # Display the menu and prompt the user to choose an operation
    echo "Choose an operation:"
    echo "1. Add"
    echo "2. Subtract"
    echo "3. Multiply"
    echo "4. Divide"
    read choice

    # Prompt the user to enter two numbers
    echo "Enter two numbers:"
    read num1 num2

    # Perform the chosen operation
    case $choice in
        1)
            result=$(expr $num1 + $num2)
            echo "The sum is: $result"
            ;;
        2)
            result=$(expr $num1 - $num2)
            echo "The difference is: $result"
            ;;
        3)
            result=$(expr $num1 \* $num2)
            echo "The product is: $result"
            ;;
        4)
            result=$(expr $num1 / $num2)
            echo "The quotient is: $result"
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done
