#! /bin/bash

echo -n "Enter the number of rows: "
read num

for((i=1;i<=num;i++))
 do
   for((j=1;j<=i;j++))
    do
      echo -n "*"
    done
    echo
 done 
