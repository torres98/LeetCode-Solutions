#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>

#include <unordered_map>

using namespace std;

vector<vector<int>> twoSum(vector<int>& nums, int target) {

    vector<vector<int>> res;

    unordered_map<int, int> values_to_pos;

    for (int i = 0; i < nums.size(); i++)
        values_to_pos.insert({nums[i], i});

}

vector<int> nums = {
    -3,-1,0,2,4,5
};

int main(int argc, char** argv) {
    vector<vector<int>> res = twoSum(nums, 2);

    for (vector<int> v : res)
        cout << "[" << v[0] << ", " << v[1] << "]" << endl;

    return 0;
}