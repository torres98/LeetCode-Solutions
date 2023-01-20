#include <string>
#include <iostream>

using namespace std;

int romanToInt(string s) {
    int result = 0;
    
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case 'I':
            if (i+1 < s.length() && (s[i+1] == 'V' || s[i+1] == 'X'))
                result--;
            else
                result++;

            break;
    
        case 'V':
            result += 5;
            break;

        case 'X':
            if (i+1 < s.length() && s[i+1] == 'L' || s[i+1] == 'C')
                result -= 10;
            else
                result += 10;

            break;

        case 'L':
            result += 50;
            break;
        
        case 'C':
            if (i+1 < s.length() && s[i+1] == 'D' || s[i+1] == 'M')
                result -= 100;
            else
                result += 100;

            break;

        case 'D':
            result += 500;
            break;
    
        case 'M':
            result += 1000;
            break;
        }
    }

    return result;
}


std::string intToRoman(int num) {
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* strings[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    std::string result ("");
    int index = 0;

    while (num != 0) {
        if (num >= values[index]) {
            num -= values[index];
            result.append(strings[index]);
        } else {
            index++;
        }
    }

    return result;
}

int main(int argc, char **argv) {
    /*std::string s (argv[1]);

    std::cout << romanToInt(s) << std::endl;*/

    std::cout << intToRoman(atoi(argv[1])) << std::endl;

    return 0;
}