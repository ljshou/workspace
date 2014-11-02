#!/bin/sh
echo "Is it morning? Please input yes or no?"
read timeofday
case $timeofday in
  yes | y | Yes | YES) 
	echo "Good morning"
	echo "Up bright and early in the morning"
	;; #双分号
  [nN]*) 
	echo "Good afternoon"
	;; 
  *) 
	echo "Sorry, answer not recognized"
	exit 1
	;; 
esac
exit 0
