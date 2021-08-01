for((i = 2; ; ++i)); do
    echo $i
    ./gen $i > input.txt
    diff -w <(./a) <(./brute) || break
done