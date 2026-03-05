#!/bin/bash

inputL=("Uno duo tres" "From Russia with love" "Aida Pushkin, aida (menya zastavili ubrat 2nd chast citaty)")

while true; do

	for input in "${inputL[@]}"; do
	echo "-----------------"
	echo "input : $input"
	outp=$(wordcounter "$input")
	echo "output : $outp"
	echo "-----------------"
	sleep 1.0
	done

done
