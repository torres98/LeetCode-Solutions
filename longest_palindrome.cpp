#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//V1

bool is_substring_palindrome(string &s, int i, int len) {
    int j = i + len - 1;

    for (int h = 0; h < len / 2; h++)
        if (s[i + h] != s[j - h])
            return false;

    return true;
}

// this is possibly doing useless checks, since each string is 
// checked from the beginning
string longestPalindromeV1(string s) {
    int starting_pos = 0, substr_len = 1;

    for (int i = 0; i < s.length(); i++) {
        for (int l = substr_len + 1; l <= s.length() - i; l++) {
            if (is_substring_palindrome(s, i, l)) {
                starting_pos = i;
                substr_len = l;
            }
        }
    }

    return s.substr(starting_pos, substr_len);
}

//V2

string longestPalindromeV2(string s) {
    int center = 0, radius = 0;

    for (int c = 0; c < s.length(); c++) {
        int r = 0;

        while(c - (r+1) >= 0 && c + (r+1) < s.length() && s[c-(r+1)] == s[c+(r+1)]) {
            r++;
        }

        if (r > radius) {
            center = c;
            radius = r;
        }
    }
    
    bool even = false;

    for (int c = 0; c < s.length()-1; c++) {
        int r = 0;

        while(c - r >= 0 && c + (r+1) < s.length() && s[c-r] == s[c+(r+1)]) {
            r++;
        }

        cout << r << endl;

        // 2*r > 2*radius+1
        if (r > radius) {
            even = true;

            cout << "even\n";

            center = c;
            radius = r;
        }
    }

    if (even)
        return s.substr(center - (radius-1), 2*radius);

    return s.substr(center-radius, 2*radius + 1);
}


string longestPalindromeV2_add(string s) {
    //add delimiters
    for (int i = s.length(); i >= 0; i--)
        s.insert(i, "|");

    // find longest palindrome substring
    int center = 0, radius = 0;

    for (int c = 0; c < s.length(); c++) {
        int r = 0;

        while(c - (r+1) >= 0 && c + (r+1) < s.length() && s[c-(r+1)] == s[c+(r+1)]) {
            r++;
        }

        if (r > radius) {
            center = c;
            radius = r;
        }
    }

    string longest_palindrome = s.substr(center-radius, 2*radius + 1);

    //remove delimeters
    longest_palindrome.erase(remove(longest_palindrome.begin(), longest_palindrome.end(), '|'), longest_palindrome.end());

    return longest_palindrome;
}

//

string longestPalindrome(string s) {
    vector<bool> row (s.length(), false);

    vector<vector<bool>> is_substring_palindrome (s.length(), row);

    int starting_pos = 0, substr_len = 1;

    for (int i = 0; i < s.length(); i++)
        is_substring_palindrome[i][i] = true;

    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] == s[i+1]) {
            is_substring_palindrome[i][i+1] = true;

            if (2 > substr_len) {
                starting_pos = i;
                substr_len = 2;
            }
        }

    for (int l = 1; l < s.length(); l++) {
        for (int i = 0; i < s.length() - l; i++) {
            if (s[i] == s[i+l] && is_substring_palindrome[i+1][i+l-1]) {
                is_substring_palindrome[i][i+l] = true;

                if (l+1 > substr_len) {
                    starting_pos = i;
                    substr_len = l+1;
                }
            }
        }
    }

    return s.substr(starting_pos, substr_len);
}

int main(int argc, char** argv) {
    string s (argv[1]);

    cout << longestPalindromeV2_add(s) << endl;
    return 0;
}
