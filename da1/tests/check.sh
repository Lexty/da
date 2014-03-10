#!/bin/bash

G="\033[32m"
R="\033[31m"
N="\033[0m"

if [[ ! -f ./tests ]]; then
	make all
fi

./tests quiet

if [[ $? -eq 0 ]]; then
	echo -e "${G}All tests passed!${N}"
else
	echo -e "${R}Fail in tests!${N}"
fi

exit 0
