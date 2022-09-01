date
sleep 3
mkdir ~/week1/f1
date
sleep 3
touch ~/week1/f1/root.txt
date
sleep 3
mkdir ~/week1/f2
date
sleep 3
touch ~/week1/f2/home.txt
date
sleep 3
ls  / --sort=time -r > ~/week1/f1/root.txt
ls ~ --sort=time -r > ~/week1/f2/home.txt
cat ~/week1/f1/root.txt ~/week1/f2/home.txt
ls ~/week1/f1
ls ~/week1/f2