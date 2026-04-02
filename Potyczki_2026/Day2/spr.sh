g++ -O3 -static -std=c++20 -o wzor.e B_chat.cpp
#g++ -O3 -static -std=c++20 -o brut.e brut.cpp
# g++ -O3 -static -std=c++20 -o gen.e gen.cpp

for((i=1 ; i>0;i++))
do

#formatted_num=$(printf "%03d" "$i")
# echo $i

    ./wzor.e < tests/$i.in > wzor.out

    if diff -b tests/$i.out wzor.out > /dev/null
    then
        echo -ne "\e[1;32m$i\e[0m\r"
    else
        echo -e "\e[1;31m$i\e[0m"
        break
    fi
    
done