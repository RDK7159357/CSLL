read -p "Enter 3 values: " a b c
sum=$((a+b+c))
product=$((a*b*c))
echo "The sum is: $sum"
echo "The product is: $product"

# Find minimum using if conditions
if [ $a -lt $b ] && [ $a -lt $c ]; then
    min=$a
elif [ $b -lt $c ]; then
    min=$b
else
    min=$c
fi
echo "the min is : $min"

# Find maximum using if conditions
if [ $a -gt $b ] && [ $a -gt $c ]; then
    max=$a
elif [ $b -gt $c ]; then
    max=$b
else
    max=$c
fi
echo "the max is : $max"

