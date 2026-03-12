TAX_RATE_ABOVE_20K=0.1
TAX_RATE_ABOVE_40K=0.2
TAX_RATE_ABOVE_60K=0.3

read -p "Enter your annual income: " income

if [ $income -le 20000 ]; then
    tax_rate=$TAX_RATE_ABOVE_20K
elif [ $income -le 40000 ]; then
    tax_rate=$TAX_RATE_ABOVE_40K
elif [ $income -le 60000 ]; then
    tax_rate=$TAX_RATE_ABOVE_60K
else
    tax_rate=0.4
fi

tax=$(echo "scale=2; $income * $tax_rate" | bc)
echo "Your tax is: $tax"