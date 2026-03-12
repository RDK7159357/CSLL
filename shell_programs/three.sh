NOWDATE=$(date +"%Y-%m-%d")
NOWTIME=$(date +"%T")
USERS=$(who | wc -l)
for u in $USERS; do
    echo "$NOWDATE"",""$NOWTIME - User: $u"
done