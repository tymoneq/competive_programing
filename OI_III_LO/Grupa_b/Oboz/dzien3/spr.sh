g++ fajerwerkibrut.cpp -o fb.e
g++ faj.cpp -o f.e
g++ gen.cpp -o g.e

for((i=1;i>0;i++))
do
echo $i > ziarno
./g.e < ziarno > f.in
 ./fb.e < f.in > brut.out 


        echo -ne "\e[1;32m$i\e[0m       \r"
    

done

