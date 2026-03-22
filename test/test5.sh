#!/bin/bash
echo "Enter filename:"
read file
echo "Start line:"
read s
echo "End line:"
read e
if [ -f "$file" ]; then
    # range=$(($e - $s + 1))
    # # Logic: head gets up to the end line, tail gets the difference
    # head -n $e "$file" | tail -n $range

    sed -n "${s},${e}p" "$file"
else
    echo "File does not exist."
fi