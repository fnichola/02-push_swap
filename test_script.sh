#!/bin/bash
#ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..25).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)

start=1
end=5
test_times=100
let "nbr = $end - $start + 1"
echo "Testing with $nbr arguments..."
total=0
max=0
failed=0
for i in `seq 1 $test_times`
do
	ARG=`ruby -e "puts ($start..$end).to_a.shuffle.join(' ')"`
	count=$(./push_swap $(echo $ARG) | wc -l)
	checker_result=$(./push_swap $(echo $ARG) | ./checker_Mac $(echo $ARG))

	if [ "$checker_result" = "KO" ]
	then
		failed=1
	fi

	let total+=count
	echo "$i: $count" 
	echo $checker_result

	if [ $count -gt $max ]
	then
		let max=count
	fi
done
let average=total/test_times
echo "Average = $average"
echo "Max = $max"
if [ $failed = 1 ]
then
	echo "SORTING ERROR!!!"
fi
