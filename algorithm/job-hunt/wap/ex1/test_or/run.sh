#!/bin/bash

for ((i=0; i<200; i++)); do
 ./shou2 < test$i.txt
done

#for file in $(ls test*.txt); do
#  ./shou2 < $file
#done

exit 0
