g++ -std=c++17 connectingTwoBarnsDijkstra.cpp -o c.e

for((i=5 ; i<=10;i++))
do
    ./c.e < $i.in > c$i.out
    if diff -b c$i.out $i.out > /dev/null
    then
       echo -ne "\e[1;32m$i\e[0m       \r"
    else
        echo -ne "\e[1;31m$i\e[0m\n"

    fi

done
