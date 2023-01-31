## Implementation of Quicksort - Lomuto & Hoare Schemes

#### To run program - Lomuto

```console
user@home:~$ make
g++ -c quicksort.cpp
g++ -o QuickSort quicksort.o
user@home:~$ ./QuickSort
```
### To run program - Hoare
```console
user@home:~$ ./QuickSort -h
```
#### To run program - STL
```console
user@home:~$ ./QuickSort -s
```

#### To run tests

```console
user@home:~$ chmod +x sortTests.sh
user@home:~$ ./sortTests.sh
```

#### To show graph & fastest times
When prompted from ```./sortTests.sh```
```console
Delete time files? [y/n] n
```

```console
user@home:~$ python3 bigOGraph.py
```
