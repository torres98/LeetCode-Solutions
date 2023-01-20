#include <iostream>
#include <cmath>

//7230
int next(int n) {
    int allowed_digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int ndigits = 0;
    int current_digit = 0;

    do {
        current_digit = n % 10;
        n /= 10;
        ndigits++;

        allowed_digits[current_digit] = -1;
    } while (n != 0);

    //extract the first digit
    int first_digit = current_digit;

    while (allowed_digits[first_digit] == -1 && first_digit < 10) {
        first_digit++;
    }

    //extract the remaining digit
    int other_digit = 0;

    while (allowed_digits[other_digit] == -1 && other_digit < 10) {
        other_digit++;
    }
    
    int next_value = first_digit * pow(10, ndigits-1);

    for (int i = 0; i < ndigits-1; i++)
        next_value += other_digit * pow(10, i);

    if (next_value < 0)
        return -1;

    return next_value;
}

int main(int argc, char **argv) {
    std::cout << next(atoi(argv[1])) << std::endl;
    return 0;
}