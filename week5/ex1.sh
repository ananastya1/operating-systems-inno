gcc ~/week5/publisher.c -o publisher
gcc ~/week5/subscriber.c -o subscriber

n=$1
i=1

while [ $i -le $n ] ; do
  x-terminal-emulator -e ./subscriber $n $i &
  i=$((i+1))
done

x-terminal-emulator -e ./publisher $n