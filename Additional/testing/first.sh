#! /usr/bin/bash

touch b.txt

g++ test.cpp
./a.out>a.txt

diff a.txt b.txt > c.txt

if [[ -s c.txt ]]
then
	echo "test failed"
else
	echo "test passed"
fi
