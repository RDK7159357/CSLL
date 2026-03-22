#!/bin/bash
echo "Enter the word to remove:"
read word
echo "Enter filename:"
read fname

if [ -f "$fname" ]; then
    grep -v "$word" "$fname"
else
 echo "File does not exist."
fi 