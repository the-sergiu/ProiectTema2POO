#!/bin/bash

#------------------------------------------------------------------------------
# 
#   CHECKER Tema 2 POO, 2020-2021
#	    Ceva tema idk
#
#   Author: Niste prosti
#
#------------------------------------------------------------------------------

# Exec name
EXEC_NAME=TemaPOO

# Teste Normale
FILE_TEST_DATE_1="data/test%d/date.in"
FILE_TEST_INDEX="%d"
FILE_TEST_REF="ref/ref%d.out"
FILE_TEST_OUT="out/out%d.out"
NUM_TESTS=11

# Format: "x=a,y=b,z=c..."
# x, y, z are test indexes
# Each test with an index less or equal to x gets a points.
# Each test with an index less or equal to y gets b points.
POINTS_TEST="2=10,6=5,9=15,12=10,15=5"

# Total score
SCORE_TESTS=0

# Delimitor
DELIM="-------------------------------------------------------------"
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Points:
#
# TODO

points=0

function run_test {
	points=0
	msg=""
	color=$RED

	# Convert from Points string to array
	p_text=`echo $6 | tr ',' ' '`
	p_arr=($p_text)

	for x in "${p_arr[@]}";
	do
	        tidx=`echo $x | cut -d'=' -f1`
	        tpts=`echo $x | cut -d'=' -f2`
	
        	if (( $1 <= $tidx ));
        	then
			points=$tpts
        	        break
        	fi
	done

	# Okay, so this test will get $points if passed.
	./$EXEC_NAME $2 $3 $5 > /dev/null 2>&1 | cat
	
	diff -Z -q $3 $4 > /dev/null 2>&1
	if [ $? -eq 0 ];
	then
		msg="PASSED"
		color=$GREEN
	else
		msg="FAILED"
		color=$RED
		points=0
	fi

	printf "Test %2d ................................. ${color}%6s${NC} (+%2dp)\n" $i $msg $points
}

function run_tests {
	for i in `seq 1 1 $1`
	do
		printf -v file_cerinte $i
		printf -v file_date_1 $2 $i
		printf -v file_out $3 $i
		printf -v file_ref $4 $i
		run_test $i $file_date_1 $file_out $file_ref $file_cerinte $5
		
		SCORE_TESTS=$(($SCORE_TESTS+$points))
	done
}

function run_normal_tests {
	echo $DELIM
	echo "[TESTE]"
	run_tests $NUM_TESTS $FILE_TEST_DATE_1 $FILE_TEST_OUT $FILE_TEST_REF "$POINTS_TEST"

	echo
	printf "TOTAL ........................................... %3sp\n" $SCORE_TESTS 
	echo
}

function show_total {
	echo $DELIM
	echo "[NOTA FINALA]"
	
	echo
	printf "NOTA FINALA ..................................... %3sp/135p\n" $(($SCORE_TESTS))
	echo	
}

# Prepare output directory
rm -rf out/
mkdir out

# Build 
# make clean
make

# Run normal tests
echo $DELIM
echo "Executabil = '$EXEC_NAME'"

run_normal_tests
show_total

