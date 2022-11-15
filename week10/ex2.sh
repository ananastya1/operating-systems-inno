mkdir week01
cd week01
echo "Nastya" >> file.txt
cd ..
link week01/file.txt _ex2.txt
find ./ -inum "$(stat -c '%i' week01/file.txt)" > ./ex2.txt
find ./ -inum "$(stat -c '%i' week01/file.txt)" -exec rm {} \; >> ./ex2.txt