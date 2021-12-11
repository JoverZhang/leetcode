#!/bin/bash

filename="$1"

mkdir -p ./build
gcc -o ./build/a.out $1 && ./build/a.out

