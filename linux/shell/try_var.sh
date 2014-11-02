#!/bin/sh

salutation='Hello world'
echo $salutation
echo "the program $0 is now running"
echo "first parameter is $1"
echo "second parameter is $2"
echo "full parameters are $@"
echo "Please input a greeting"
read salutation
echo $salutation
exit 0
