g++ g.cpp -o g.e
g++ -O3 -static komp.cpp -std=c++17 -o k.e
g++ komputerbrut.cpp -o kb.e

for((i=1;i>0;i++))
do
echo $i > ziarno

./g.e < ziarno > f.in
./k.e <f.in > wzor.out
./kb.e < f.in > brut.out

if diff -b wzor.out brut.out > /dev/null
then 
echo $i
else
echo $i
break
fi

done 