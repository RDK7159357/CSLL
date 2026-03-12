echo enter existing directory
read dir
echo enter new directory 
read ndir
if [ -d "$dir" ] && [ ! -d "$ndir" ]; then
    mv "$dir" "$ndir"
else
    echo "Either the source directory does not exist or the target directory already exists."
fi