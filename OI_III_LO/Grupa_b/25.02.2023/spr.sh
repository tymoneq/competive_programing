g++ parkur.cpp -std=c++17 -Wshadow -Wall -o p.e -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
g++ parkourbrut.cpp -o pb.e -std=c++17
g++ gen.cpp -o g.e

for((i=1;i>0;i++))
do

echo $i> ziarno
./g.e < ziarno > f.in
./p.e < f.in > wzor.out
./pb.e < f.in > brut.out

if diff -b wzor.out brut.out > /dev/null
then 
echo $i
else
echo $i
break
fi
done