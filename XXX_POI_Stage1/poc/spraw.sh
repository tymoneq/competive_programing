#!/usr/bin/env bash

g++ poc.cpp -o poc.exe
g++ spraw.cpp -o spraw.exe

rm res.txt
for i in {0..2};
do 
echo $i
time ./poc.exe < poc$i.in > wynik.txt
./spraw.exe poc$i.out >> res.txt

done