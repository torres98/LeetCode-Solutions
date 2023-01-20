#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string convert(string s, int numRows) {
    string zigzag ("");
    int block_size;

    if (numRows == 1)
        block_size = 1;
    else    
        block_size = 2*numRows - 2;
    
    for (int i = 0; i < numRows; i++) {
        for (int block = 0; block < ceil((float) s.length() / block_size); block++) {
            if (block*block_size + i < s.length()) {
                //cout << "Adding " << s[block*block_size + i] << "(pos " << block*block_size + i << ") on line " << i << endl;
                zigzag += s[block*block_size + i];
            }

            if (i != 0 && (block+1)*block_size - i < s.length() && block*block_size + i != (block+1)*block_size - i) {
                //cout << "*Adding " << s[(block+1)*block_size - i] << "(pos " << (block+1)*block_size - i << ") on line " << i << endl;
                zigzag += s[(block+1)*block_size - i];
            }
        }
    }

    return zigzag;
}

int main(int argc, char** argv) {
    string s (argv[1]);

    cout << convert(s, atoi(argv[2])) << endl;
    return 0;
}