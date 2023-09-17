#!/bin/bash

set -e

RED='\033[1;31m' # Red color
GREEN='\033[1;32m' # Green color
NC='\033[0m' # No color

if [[ $# -eq 0 ]] ; then
    echo -e "${RED}USAGE:${NC} ${GREEN}./build.sh${NC} <file[.cpp|.cc]>"
    exit 0
fi

g++ -Wall -Wextra -pedantic -ggdb -std=c++17 -o out $1 
