#!/bin/bash

# Тест 3: Специальные случаи (дефисы, апострофы, цифры)
echo "Тест 3: Специальные случаи"

# Строка с дефисами и апострофами
output1=$(echo "don't forget the 2nd test-case" | ../usr/bin/wordcounter)
expected1="Words in line: 5"

# Пустая строка
output2=$(echo "" | ../usr/bin/wordcounter)
expected2="Words in line: 0"

# Только пробелы и знаки препинания
output3=$(echo "   !!! ??? ,,,   " | ../usr/bin/wordcounter)
expected3="Words in line: 0"

if [ "$output1" == "$expected1" ] && [ "$output2" == "$expected2" ] && [ "$output3" == "$expected3" ]; then
    echo "Тест 3 пройден"
else
    echo "Тест 3 не пройден"
    exit 1
fi