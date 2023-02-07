g++ prembrut.cpp -std=c++17 -O3 -o p.e
g++ g.cpp -o gE.e

for((i=1;i>0;i++))
do
echo $i> ziarno
    echo $i
    ./gE.e < ziarno > f.in
    time ./p.e < f.in > f.out;

done