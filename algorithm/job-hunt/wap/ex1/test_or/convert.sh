#!/bin/bash

for file in *.gif
do
  mv $file  ${file%%gif}txt
done
exit 0
