echo enter directory
read dir

if [ -d "$dir" ]; then
    ls "$dir"/*.txt "$dir"/*.csv "$dir"/*.py 2>/dev/null
fi