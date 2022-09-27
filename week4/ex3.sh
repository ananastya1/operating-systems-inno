gcc ~/week4/ex3.c 
./a.out 3 &
echo "for n = 3: "
for i in 1 2 3
do
   pstree $$
   sleep 5
done
./a.out 5 &
echo "for n = 5: "
for i in 1 2 3 4 5
do
   pstree $$
   sleep 5
done