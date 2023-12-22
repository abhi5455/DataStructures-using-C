#!/bin/bash


for i in $(seq 1 $1);
do
	> "ex"$i"_algo.txt"
	> "ex"$i"_out.txt"
done
