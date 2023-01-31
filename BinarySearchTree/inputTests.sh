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
    valgrind -s --leak-check=full ./BST < Tests/$1 > Tests/out$1
    echo -e $finish
    echo -e $diff_MSG
    diff -s Tests/out$1 Tests/res$1
    echo -e $finish $'\n'
}

#Build BST
echo -e ${GR}... Building Binary Search Tree ...${NC}$'\n'
make
echo -e $finish $'\n'

#Test for sample data
test Sample
#Test for 5k values 
test 5k
#Test for 10k values 
test 10k

echo Cleaning up ... ...
make --silent clean
rm Tests/out10k Tests/out5k Tests/outSample
echo -e $finish