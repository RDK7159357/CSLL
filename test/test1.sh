#! /bin/bash

echo "Enter Directory1 Name: "
read dir1
echo "Enter Directory2 Name: "
read dir2

if[ -d "$dir1"]; then
    if [ ! -d "$dir2" ]; then
        mkdir "$dir2"
        echo "Directory $dir2 created."
    fi
    mv "$dir1"/* "$dir2"/
    echo "Files moved from $dir1 to $dir2."
else
    echo "Directory $dir1 does not exist."
fi