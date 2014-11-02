#!/bin/sh
sed -i 's/\/\/ BEGIN/\/\*&/g' Unique.cpp
sed -i 's/\/\/ END CUT HERE/&\*\//g' Unique.cpp
