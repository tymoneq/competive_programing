g++ -std=c++17 tamingtheHerd.cpp -o t.e

for((i=2 ; i<10;i++))
do
    ./t.e < $i.in > t.out
    if diff -b t.out $i.out > /dev/null
    then
       echo -ne "\e[1;32m$i\e[0m       \r"
    else
        echo -ne "\e[1;31m$i\e[0m\n"

    fi

done
