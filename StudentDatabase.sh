#!/bin/bash

while true; do
    # Display the menu
    echo "Student Database Menu:"
    echo "1. Create a database"
    echo "2. Insert a record"
    echo "3. View the database"
    echo "4. Delete a record"
    echo "5. Modify a record"
    echo "6. Display a record of particular student"
    echo "7. Exit"

    # Read the user's choice
    read choice

    # Execute the chosen option
    case $choice in
        1)
            echo "Creating a new database..."
            echo "Enter the name of the database file (without the extension):"
            read db_file
            touch "$db_file.txt"
            echo "Database created successfully."
            ;;
        2)
            # Prompt the user to enter the record data
            echo "Enter the student details:"
            echo -n "Name: "
            read name
            echo -n "Roll number: "
            read rollno
            echo -n "Marks1: "
            read marks1
            echo -n "Marks2: "
            read marks2
            echo -n "Marks3: "
            read marks3

            # Append the record data to the database file
            echo "$name|$rollno|$marks1|$marks2|$marks3" >> "$db_file.txt"
            echo "Record added successfully."
            ;;
        3)
            echo "Student Database:"
            echo "Name | Roll No | Marks 1 | Marks 2 | Marks 3"
            echo "--------------------------------------------"
            cat "$db_file.txt" | awk -F "|" '{printf "%-10s | %-7s | %-8s | %-8s | %-8s\n", $1, $2, $3, $4, $5}'
            ;;

        4)
            # Prompt the user to enter the roll number of the record to delete
            echo "Enter the roll number of the record to delete:"
            read rollno

            # Delete the record with the given roll number from the database file
            sed -i "/$rollno/d" "$db_file.txt"
            echo "Record deleted successfully."
            ;;
        5)
            # Prompt the user to enter the roll number of the record to modify
            echo "Enter the roll number of the record to modify:"
            read rollno

            # Find the record with the given roll number in the database file
            record=$(grep "^.*|$rollno|" "$db_file.txt")

            # Check if the record exists
            if [ -n "$record" ]; then
                # Prompt the user to enter the new record data
                echo "Enter the new student details:"
                echo -n "Name: "
                read name
                echo -n "Marks1: "
                read marks1
                echo -n "Marks2: "
                read marks2
                echo -n "Marks3: "
                read marks3

                # Replace the old record with the new record in the database file
                sed -i "s/^.*|$rollno|.*$/$name|$rollno|$marks1|$marks2|$marks3/" "$db_file.txt"
                echo "Record modified successfully."
            else
                echo "Record not found."
            fi
            ;;
        6)
            # Prompt the user to enter the roll number of the record to display
            echo "Enter the roll number of the record to display:"
            read rollno

            # Find the record with the given roll number in the database file
            record=$(grep "^.*|$rollno|" "$db_file.txt")

            # Check if the record exists
            if [ -n "$record" ]; then
                echo "Student Record:"
                echo "$record"
            else
                echo "Record not found."
            fi
            ;;
        7)
            echo "Exiting..."
            exit 0
            ;;
    esac 
done
