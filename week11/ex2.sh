cd lofsdisk/
echo "Nastya" > file1
echo "Something" > file2
gcc ex2.c -o ex2.out
mkdir lib64
mkdir lib
cp /lib64/ld-linux-x86-64.so.2 lib64/
cp /lib/x86_64-linux-gnu/libc.so.6 lib/
sudo chroot . ./ex2.out > ex2.txt
echo "\n" >> ex2.txt
./ex2.out >> ex2.txt