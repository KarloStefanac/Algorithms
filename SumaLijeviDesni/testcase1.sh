#!/bin/sh
gcc sumalijevidesni.c -o sumalijevidesni
./sumalijevidesni << EOF
12
18 2 20 30 22 16 4 100 12 200 11 44
EOF
