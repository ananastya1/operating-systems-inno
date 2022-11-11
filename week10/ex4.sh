mkdir tmp
cd tmp/
> file1
> file2
cd ..
ln -f tmp/file1 tmp/link1
gcc ex4.c -o ex4
./ex4