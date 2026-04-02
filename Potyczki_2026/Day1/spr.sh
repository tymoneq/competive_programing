g++ -O3 -static -std=c++20 -o wzor.e B.cpp
#g++ -O3 -static -std=c++20 -o brut.e brut.cpp
# g++ -O3 -static -std=c++20 -o gen.e gen.cpp

for((i=1 ; i>0;i++))
do
# echo $i

    ./wzor.e < kon_tests/large/kon$i.in > wzor.out

    if diff -b kon_tests/large/kon$i.out wzor.out > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi
    
done