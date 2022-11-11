echo "Nastya" > _ex3.txt
chmod a-x _ex3.txt > ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=rwx _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt