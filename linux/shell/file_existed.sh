#!/bin/sh

# testing whether a file existed

file_name="hello.sh"
if [ -f $file_name ]
then
  echo "$file_name existed!"
else
  echo "$file_name not existed"
fi

exit 0
