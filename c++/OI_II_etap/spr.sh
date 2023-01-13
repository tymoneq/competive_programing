g++ -std=c++17 tamingtheHerd.cpp -o t.e
g++ -std=c++17 gen.cpp -o g.e
for((i=1;i>0;i++))
do
    echo $i > ziarno
    ./g.e < ziarno > f.in
    ./sb.e < f.in > brut.out
    ./s.e < f.in > wzor.out
    if diff -b brut.out wzor.out > /dev/null
    then 
        echo -ne "\e[1;32m$i\e[0m       \r"
    else
        echo -ne "\e[1;31m$i\e[0m\n"
        break
    fi

done