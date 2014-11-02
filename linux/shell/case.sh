#!/bin/sh
echo "Is it morning? Please input yes or no?"
read timeofday
case $timeofday in
  yes) echo "Good morning";; #双分号
  no) echo "Good afternoon";; 
  y) echo "Good morning";; 
  n) echo "Good afternoon";; 
  *) echo "Sorry, answer not recognized";; 
esac
exit 0
