#!/bin/bash

echo "Збираємо поточні обмеження..."
ulimit -a > limits.log 
cat limits.log 


stack_size=$(ulimit -s)
echo "Розмір стека: $stack_size KB"


max_files=$(ulimit -n)
echo "Максимальна кількість відкритих файлів: $max_files"


cpu_time=$(ulimit -t)
if [ "$cpu_time" != "unlimited" ]; then
    echo "Обмеження CPU-часу: $cpu_time секунд"
else
    echo "Обмеження CPU-часу: немає"
fi


test_stack_limit() {
    local i=$1
    echo "Глибина рекурсії: $i"
    test_stack_limit $((i+1))
}

echo "Тестуємо обмеження стека..."
test_stack_limit 1