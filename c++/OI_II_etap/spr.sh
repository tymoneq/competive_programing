g++ milk_pumping.cpp -o m.e

for((i=1;i<=10;i++))
do
    ./m.e < $i.in > r.txt
    if diff -b r.txt $i.out > /dev/null
    then 
        echo -ne "\e[1;32m$i\e[0m       \r"
    else
        echo -ne "\e[1;31m$i\e[0m\n"
        break
    fi

done