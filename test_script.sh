#!/bin/bash
#ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)

total=0
max=0
failed=0
for i in `seq 1 100`
do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	count=$(./push_swap $(echo $ARG) | wc -l)
	checker_result=$(./push_swap $(echo $ARG) | ./checker_Mac $(echo $ARG))

	if [ "$checker_result" = "KO" ]
	then
		failed=1
	fi

	total=$(($total + $count))
	echo "$i: $count" 
	echo $checker_result

	if [ $count -gt $max ]
	then
		max=$count
	fi
done
average=$(($total/100))
echo "Average = $average"
echo "Max = $max"
if [ $failed = 1 ]
then
	echo "SORTING ERROR!!!"
fi
