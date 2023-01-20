#include <string>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> last_index_chars(256, -1);
    int i = 0, max_len = 0;

    for (int j = 0; j < s.length(); j++) {
        // if the current last char is already present
        // in the substring currently considered, move the
        // starting index right after its occurrence
        if (last_index_chars[s[j]] + 1 > i)
            i = last_index_chars[s[j]] + 1;
        else if (j - (i-1) > max_len)
            max_len = j - (i-1);

        // update last index of current last char
        last_index_chars[s[j]] = j;
    }

    return max_len;
}

int main(int argc, char** argv) {
    string s (argv[1]);

    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}

//abcadbcbb
// | |