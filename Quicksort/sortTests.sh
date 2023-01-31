#!/bin/bash
WH='\033[1;37m' #White
GR='\033[1;32m' #Green
R='\033[0;31m' #Red
NC='\033[0m' #No Color
finish=${R}"DONE"${NC}

function sortTime () {
    temp=$1
    opt=${temp:0:1}
    
    echo -e "Running Sort(): $2 --"

    if [ "$opt" = "s" ] || [ "$opt" = "h" ]
    then
        /usr/bin/time -o $1time.txt -a -p ./QuickSort -$opt < Tests/$2 > Tests/out$2
    else
        /usr/bin/time -o $1time.txt -a -p ./QuickSort < Tests/$2 > Tests/out$2
    fi
}

function cleanHeader () {
    tail +2 Tests/out$1 > Tests/$2out$1
    rm Tests/out$1
}

function diffTests () {
    echo -e "Diff Test w/ Solution: $2 --"
    
    #If test is for stl
    if [ "$1" = "s" ]
    then
        diff -s Tests/$1out$2 Tests/res$2
    else
        diff -s Tests/$1out$2 Tests/res$2
        echo -e "Diff Test w/ STL Solution: $2 --"
        diff -s Tests/$1out$2 Tests/sout$2
    fi
}

function runQuickSort () {
    declare -a inputVals=("1k" "10k" "50k" "75k" "100k" "150k" "200k")
    length=${#inputVals[@]}

    #Get first char. from 'stl', 'hoare', 'lomuto'
    temp=$1
    option=${temp:0:1}

    echo -e ${WH}... BEGINNING TEST: $1 SORT ...${NC}$'\n'
    for (( i=0; i<length; i++ ))
    do
        echo -e ${GR}"--" "${inputVals[$i]}" "VALUES --"${NC}

        sortTime "$1" "${inputVals[$i]}"
    
        cleanHeader "${inputVals[$i]}" "$option"

        diffTests "$option" "${inputVals[$i]}"
        
        echo -e $finish
    done
}

function cleanUp () {
    #Prompt for output files
    read -p 'Delete output files? [y/n] ' opt1

    if [ "$opt1" = "y" ]
    then
        echo -e "Deleting output files"
        rm -rf Tests/s* Tests/h* Tests/l*
    elif [ "$opt1" = "n" ]
    then
        echo -e " "
    else
        echo -e "Invalid response"
    fi
    
    #Prompt for time files
    read -p 'Delete time files? [y/n] ' opt2

    if [ "$opt2" = "y" ]
    then
        echo -e "Deleting time files"
        rm -rf *.txt
    elif [ "$opt2" = "n" ]
    then
        echo -e " "
    else
        echo -e "Invalid response"        
    fi
}

#Build Quicksort
echo -e ${GR}... BUILDING QUICKSORT ...${NC}$'\n'
make
echo -e $finish $'\n'

#Run STL, Hoare, and Lomuto sorts
runQuickSort "stl"
runQuickSort "hoare"
runQuickSort "lomuto"

#Make clean and ask user about output/time files
echo -e ${GR}... CLEANING UP ...${NC}
make --silent clean
cleanUp
echo -e $finish