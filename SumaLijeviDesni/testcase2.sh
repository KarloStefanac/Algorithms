#!/bin/sh
gcc sumalijevidesni.c -o sumalijevidesni
./sumalijevidesni << EOF
12
18 20 2 30 22 16 37 100 12 200 11 44
EOF
