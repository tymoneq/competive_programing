#!/usr/bin/env bash

g++ wyp.cpp -o wyp.exe
g++ spraw.cpp -o spraw.exe

rm res.txt
for i in {0..4};
do 
echo $i
time ./wyp.exe < wyp$i.in > wynik.txt
./spraw.exe wyp$i.out >> res.txt

done