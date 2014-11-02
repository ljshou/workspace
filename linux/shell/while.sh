#!/bin/sh
echo "Enter Password"
read trythis
while [ "$trythis" != "secret" ]; do
  echo "Sorry, try again"
  read trythis
done
echo "Congrats, password correct"
exit 0 #成功
