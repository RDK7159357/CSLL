#!/bin/bash
echo "Enter start time (HH:MM):"
read start_time
echo "Users logged in after $start_time:"
# Filters the 4th column (time) of the 'who' command
who | awk -v t="$start_time" '$5>t {print $1, $5}'
