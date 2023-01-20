#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void rec_parenthesis(vector<string> &res, string &s, int n, int open_parenthesis, int closed_parenthesis) {
    if (open_parenthesis == n && closed_parenthesis == n) {
        res.push_back(s);
    } else {
        if (open_parenthesis < n) {
            // try opening a new parenthesis
            s.append("(");
            rec_parenthesis(res, s, n, open_parenthesis + 1, closed_parenthesis);
            s.pop_back();
        }

        // try closing a parenthesis (if possible)
        if (open_parenthesis - closed_parenthesis > 0) {
            s.append(")");
            rec_parenthesis(res, s, n, open_parenthesis, closed_parenthesis + 1);
            s.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s;

    rec_parenthesis(res, s, n, 0, 0);
    
    return res;
}

// ()
// (()), ()()

// "()((()))","((()))()","(()(()))","()(())()","((())())","(())()()","((()()))","()(()())","(()())()","(()()())"
// "((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()"
int main(int argc, char** argv) {
    vector<string> res = generateParenthesis(atoi(argv[1]));

    for (string s : res)
        cout << s << endl;

    return 0;
}