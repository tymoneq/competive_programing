g++ -O3 -static -std=c++20 -o wzor.e SocialDistancing.cpp
g++ -O3 -static -std=c++20 -o brut.e SocialDiistancngBrut.cpp
g++ -O3 -static -std=c++20 -o gen.e gen.cpp

for((i=1 ; i>0;i++))
do
# echo $i
echo $i > ziarno
    ./gen.e < ziarno > test.in
    ./brut.e < test.in > brut.out
    ./wzor.e < test.in > wzor.out

    if diff -b brut.out wzor.out > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi
    
done
