#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<char>> letters = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};

void phone_rec(vector<string> &res, string &s, string &digits, int index) {
    if (index == s.size()) {
        if (s.length() != 0)
            res.push_back(s);
        
    } else {
        char current_digit = digits[index];

        for (int j = 0; j < letters[current_digit - '2'].size(); j++) {
            s[index] = letters[current_digit - '2'][j];
            
            phone_rec(res, s, digits, index+1);
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;

    if (digits.length() != 0) {
        string s (digits);
        
        phone_rec(res, s, digits, 0);
    }

    return res;
}

int main(int argc, char** argv) {
    string s (argv[1]);

    vector<string> res = letterCombinations(s);

    for (string r: res)
        cout << r << endl;

    return 0;
}