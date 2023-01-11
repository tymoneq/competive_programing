g++ test_1.cpp -o t1.e
g++ test_2.cpp -o t2.e
g++ -std=c++17 gen.cpp -o g.e
for((i=1;i<500;i++))
do
    echo $i > ziarno
    ./g.e < ziarno > testy/f$i.in
    ./t1.e < testy/f$i.in > testy/1.out
    ./t2.e < testy/f$i.in > test/2.out
   

done