#!/bin/bash

incremento=250
inicio=0
fim=1000

for ((X = $inicio; X <= $fim; X += $incremento)); do
    ./gen $X $X 100 > ./testes/in/t$X.in
done

for ((X = $inicio; X <= $fim; X += $incremento)); do
    hyperfine "../proj < ./testes/in/t$X.in" --export-json "./testes/out/t$X.json"
done

wait