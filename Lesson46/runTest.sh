#! /usr/bin/bash

touch difference.txt

diff output.txt expected.txt > difference.txt

if [[ -s difference.txt ]]
then
	echo "test failed"
else
	echo "test passed"
fi
