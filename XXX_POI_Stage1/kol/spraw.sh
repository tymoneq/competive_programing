#!/usr/bin/env bash

g++ kol.cpp -o kol.exe
g++ spraw.cpp -o spraw.exe
i=0
while [ $i -le 99 ]
do 
./kol.exe < kol$i.in > wynik.txt
./spraw.exe < kol$i.out>> res.txt
((i++))
done