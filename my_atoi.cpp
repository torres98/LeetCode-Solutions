#include <vector>
#include <cmath>
#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s) {
    if (s.length() == 0)
        return 0;
    
    int index = 0;

    while(s[index] == ' ') { index++; }

    bool is_negative = false;

    if (s[index] == '+') {
        index++;
    } else if (s[index] == '-') {
        is_negative = true;
        index++;
    }

    long result = 0;

    while (index < s.length() && '0' <= s[index] && s[index] <= '9') {
        result *= 10;
        result += s[index++] - '0';
        
        if (is_negative && -result < INT_MIN)
            return INT_MIN;
        else if (!is_negative && result > INT_MAX)
            return INT_MAX;
    }

    if (is_negative)
        return -result;
    
    return result;
}

int main(int argc, char** argv) {
    string s (argv[1]);

    cout << myAtoi(s) << endl;
    return 0;
}