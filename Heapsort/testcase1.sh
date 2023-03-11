#!/bin/sh
a=$1
gcc HeapSort.c -o HeapSort 
./HeapSort << EOF
$1
EOF
