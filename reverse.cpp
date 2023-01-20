#include <vector>
#include <cmath>
#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
    bool is_negative = x < 0;
    unsigned long result = 0;
    unsigned long abs_x = abs(x);

    do {
        result *= 10;
        result += abs_x % 10;

        abs_x /= 10;
    } while (abs_x != 0);
    
    if (result > INT_MAX)
        return 0;

    if (is_negative)
        return -result;

    return result;
}

int main(int argc, char** argv) {
    cout << reverse(atoi(argv[1])) << endl;
    return 0;
}