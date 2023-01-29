#!/usr/bin/env bash

g++ poc.cpp -o poc.exe
g++ spraw.cpp -o spraw.exe
g++ popr.cpp -o popr.e
rm res.txt
for i in {0..1000};
do 
echo $i
time ./poc.exe < poc$i.in > wynik.txt
command time -f "%M kb" ./poc.exe < poc$i.in > wynik.txt
./spraw.exe poc$i.out >> res.txt

done

./popr.e > popr.txt