#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle) {
    for (int i = 0; i <= (int) (haystack.size() - needle.size()); i++) {
        int j = i;

        while (j - i < needle.size() && haystack[j] == needle[j - i]) {
            j++;
        }

        if (j - i == needle.size())
            return i;
    }

    return -1;
}

int main(int argc, char** argv) {
    string haystack (argv[1]);
    string needle (argv[2]);

    cout << strStr(haystack, needle) << endl;

    return 0;
}