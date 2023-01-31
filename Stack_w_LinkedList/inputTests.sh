#!/bin/bash
WH='\033[1;37m' #White
GR='\033[1;32m' #Green
R='\033[0;31m' #Red
NC='\033[0m' #No Color
finish=${R}"done"${NC}
valgrind_MSG=${GR}"Running with valgrind -- "${NC}
diff_MSG=${GR}"Checking results -- diff"${NC}

function test {
    echo -e ${WH}... Beginning Test: $1 ...${NC}$'\n'
    echo -e $valgrind_MSG
    valgrind --leak-check=full ./StackLL < Tests/$1 > Tests/out$1
    echo -e $finish
    echo -e $diff_MSG
    diff -s Tests/out$1 Tests/res$1
    echo -e $finish $'\n'
}

#Build Stack
echo -e ${GR}... Building StackLL ...${NC}$'\n'
make
echo -e $finish $'\n'

#Test for 100 values
test 100
#Test for 1k values 
test 1k
#Test for 10k values 
test 10k

echo Cleaning up ... ...
make --silent clean
rm Tests/out100 Tests/out1k Tests/out10k
echo -e $finish