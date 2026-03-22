#! /bin/bash

h=$(date +%H)
if [ $h -lt 12 ]; then
    echo "Good Morning!"
elif [ $h -lt 18 ]; then
    echo "Good Afternoon!"
else
    echo "Good Evening!"
fi