#!/bin/bash

while true; do
    read -p "Enter the monthly salary (or -1 to end): " salary
    
    if [ "$salary" -eq -1 ]; then
        echo "bye!"
        break
    fi
    
    read -p "Enter the age: " age
    
    # Determine contribution rates based on age
    if [ $age -lt 60 ]; then
        employee_rate=0.20
        employer_rate=0.17
    else
        employee_rate=0.075
        employer_rate=0.09
    fi
    
    # Calculate contributions with 2 decimal places
    employee_contribution=$(echo "scale=2; $salary * $employee_rate" | bc)
    employer_contribution=$(echo "scale=2; $salary * $employer_rate" | bc)
    total_contribution=$(echo "scale=2; $employee_contribution + $employer_contribution" | bc)
    
    echo "The employee's contribution is: \$$employee_contribution"
    echo "The employer's contribution is: \$$employer_contribution"
    echo "The total contribution is: \$$total_contribution"
done
