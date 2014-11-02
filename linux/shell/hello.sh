#!/bin/sh

echo "is it morning? Please answer yes or no"
read timeofday

if test "$timeofday" = "yes"
then 
  echo "Good morning !"
elif test "$timeofday" = "no"
then  
  echo "Good afternoon!"
else
  echo "you should input yes or no!"
  exit 1
fi

exit 0
