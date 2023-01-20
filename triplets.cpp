#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

bool is_pair_absent(vector<vector<int>> &res, int n0, int n1) {
    for (vector<int>& v : res) {
        if (
            (v[0] == n0 && v[1] == n1) ||
            (v[0] == n1 && v[1] == n0) ||
            (v[1] == n0 && v[2] == n1) ||
            (v[1] == n1 && v[2] == n0) ||
            (v[0] == n0 && v[2] == n1) ||
            (v[0] == n1 && v[2] == n0)
        )

            return false;
    }

    return true;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int i = 0, j = 1, k = 2;

    do {
        do {
            if (is_pair_absent(res, nums[i], nums[j])) {
                do {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> v {nums[i], nums[j], nums[k]};
                        res.push_back(v);
                        break;
                    }

                    k++;
                } while(k < nums.size());
            }

            j++;
            k = j+1;
        } while(j < nums.size() - 1);

        i++;
        j = i+1;
        k = j+1;
    } while(i < nums.size() - 2);

    return res;
}

vector<vector<int>> threeSum_v2(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sorted_nums(nums);

    sort(sorted_nums.begin(), sorted_nums.end());

    int i = 0;

    do {
        int sx = i+1, dx = nums.size() - 1;

        while (sx < dx) {
            int current_sum = sorted_nums[i] + sorted_nums[sx] + sorted_nums[dx];

            if (current_sum < 0) {
                do {
                    sx++;
                } while(sorted_nums[sx] == sorted_nums[sx-1] && sx < dx);
            } else if (current_sum > 0) {
                do {
                    dx--;
                } while(sorted_nums[dx] == sorted_nums[dx+1] && sx < dx);
            } else {
                res.push_back({sorted_nums[i], sorted_nums[sx], sorted_nums[dx]});

                do {
                    sx++;
                } while(sorted_nums[sx] == sorted_nums[sx-1] && sx < dx);

                do {
                    dx--;
                } while(sorted_nums[dx] == sorted_nums[dx+1] && sx < dx);
            }
        }

        do {
            i++;
        } while(sorted_nums[i] == sorted_nums[i-1] && i < nums.size() - 2);
        
    } while(i < nums.size() - 2);

    return res;
}

// [-4, -1, -1, 0, 1, 2]

vector<int> nums {
    //0,0,0,0
    -2,0,0,2,2
};

int main(int argc, char** argv) {
    vector<vector<int>> res = threeSum_v2(nums);

    for (vector<int> v : res)
        cout << "[" << v[0] << ", " << v[1] << ", " <<  v[2] << "]" << endl;

    return 0;
}