#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> sorted_nums (nums);
    sort(sorted_nums.begin(), sorted_nums.end());

    vector<vector<int>> res;

    int i = 0;
    int n = sorted_nums.size();

    //iterate over i (from the left side)
    while (i < n - 3) {

        int j = n - 1;

        while (j > i + 2) {
            
            int sx = i+1, dx = j - 1;
            long int sum_part = (long int) (sorted_nums[i]) + sorted_nums[j];

            while (sx < dx) {
                
                long int current_sum = sum_part + sorted_nums[sx] + sorted_nums[dx];

                if (current_sum < target) {
                    do {
                        sx++;
                    } while (sx < dx && sorted_nums[sx] == sorted_nums[sx - 1]);
                } else if (current_sum > target) {
                    do {
                        dx--;
                    } while (sx < dx && sorted_nums[dx] == sorted_nums[dx + 1]);
                } else {
                    //add quadruplet
                    res.push_back({sorted_nums[i], sorted_nums[sx], sorted_nums[dx], sorted_nums[j]});

                    do {
                        sx++;
                    } while (sx < dx && sorted_nums[sx] == sorted_nums[sx - 1]);
                    
                    do {
                        dx--;
                    } while (sx < dx && sorted_nums[dx] == sorted_nums[dx + 1]);
                }
            }

            do {
                j--;
            } while(j > i + 2 && sorted_nums[j] == sorted_nums[j+1]);

        }

        do {
            i++;
        } while(i < n - 3 && sorted_nums[i] == sorted_nums[i-1]);

    }

    return res;
}

vector<int> nums = {
    -3,-1,0,2,4,5
};

int main(int argc, char** argv) {
    vector<vector<int>> res = fourSum(nums, 2);

    for (vector<int> v : res)
        cout << "[" << v[0] << ", " << v[1] << ", " <<  v[2] << ", " << v[3] << "]" << endl;

    return 0;
}