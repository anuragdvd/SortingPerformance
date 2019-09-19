#! /bin/bash

echo "Input type "
echo
echo "1 -> Array from keyboard"
echo "2 -> Random Array"
echo 
read -p 'Select any type of input : ' val
cd Sorce/
flag=0
case $val in 
    "1" )
        cc main.c
        ./a.out $val
        flag=`expr $flag + 0` ;;
    "2" )
        cc main.c
        ./a.out $val
        flag=`expr $flag + 1` ;;
    * )
        echo "Wrong Input" ;;
esac

if [ $flag -eq 1 ]
then
    python3 graph.py
fi