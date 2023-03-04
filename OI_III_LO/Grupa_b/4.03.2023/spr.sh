g++ transport.cpp -o t.e
g++ transportBrut.cpp -o tb.e
g++ gen.cpp -o g.e
for((i=1;i>0;i++))
do 
echo $i>ziarno
echo $i
./g.e < ziarno > f.in
time ./t.e < f.in> wzor.out


     

done
