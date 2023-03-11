#!/bin/sh
gcc Stack.c -o Stack
./Stack << EOF
5
0 1 0 1 1
0 0 0 0 0
0 0 1 1 0
0 1 1 0 1
0 0 0 0 0
1
EOF
