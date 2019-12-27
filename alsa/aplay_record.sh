#!/bin/sh

dir=$(ls -l /mnt/record_repository |awk ' {print $NF}')

for i in $dir
do
 echo Now is playing: $i
 aplay /mnt/record_repository/$i
done 

