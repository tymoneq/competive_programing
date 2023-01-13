g++ test5.cpp -o t.e
g++ -std=c++17 gen.cpp -o g.e
for((i=1;i<40;i++))
do
    echo $i > ziarno
    ./g.e < ziarno > $i.in
    ./t.e < $i.in > $i.out
    
   

done