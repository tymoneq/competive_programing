g++ -std=c++17 RoomAlocation.cpp -o r.e
g++ gen.cpp -o g.e
for((i=1 ; i>0;i++))
do
echo $i
echo $i > ziarno
    ./g.e < ziarno > f.out
    time ./r.e <f.out > R.out
    
done
