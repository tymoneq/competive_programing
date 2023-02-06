g++ zbiorbrut.cpp -o zb.e
g++ gen.cpp -o g.e
g++ zbior.cpp -o z.e
for((i =1 ;i>0;i++))
do
echo $i > ziarno
./g.e < ziarno > f.in
./zb.e <f.in > brut.out
./z.e < f.in> wzor.out
if diff -b brut.out wzor.out > /dev/null
then 
    echo $i
else
    echo $i
    break
    fi
done 
