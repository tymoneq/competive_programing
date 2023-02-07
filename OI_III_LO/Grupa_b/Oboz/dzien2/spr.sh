g++ prembrut.cpp -o pb.e
g++ per.cpp -std=c++17 -Wshadow -Wall -o p.e    
g++ gen.cpp -o g.e
for((i=1; i>0 ;i++))
do
    echo $i > ziarno
    ./g.e < ziarno > t.in
    ./pb.e < t.in > brut.out
    ./p.e < t.in > wzor.out
    if diff -b brut.out wzor.out > /dev/null
    then 
        echo -ne "\e[1;32m$i\e[0m       \r"
    else
        echo -ne "\e[1;31m$i\e[0m\n"
        break
    fi
done