#!/bin/bash

incremento=250
inicio=0
fim=5000

for ((X = $inicio; X <= $fim; X += $incremento)); do
    ./gen $X $X 100 > ./t$X.in
done

for ((X = $inicio; X <= $fim; X += $incremento)); do
    echo -e "Teste $X\n" >> output.txt
    { time -p ../proj < ./t$X.in; } 2>&1 | grep real >> output.txt
    echo -e "\n" >> output.txt
done