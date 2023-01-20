#include <vector>
#include <cmath>
#include <iostream>
#include <climits>

using namespace std;

int maxArea(vector<int>& height) {
    int max_area = 0;
    
    for (int i = 0; i < height.size(); i++) {
        for (int j = i+1; j < height.size(); j++) {
            int current_area = (j-i) * min(height[i], height[j]);

            if (current_area > max_area)
                max_area = current_area;
        }
    }

    return max_area;  
}

// [1,8,6,2,5,4,8,3,7]
#define AREA(i, j) (j-i) * min(height[i], height[j])

int maxArea_v2(vector<int>& height) { 
    int sx = 0, dx = height.size() - 1;
    int i = sx, j = dx;
    int max_area = AREA(sx, dx);

    //first try moving the j pointer to the right
    while(i != j) {
        int current_area = AREA(i, j);

        if (current_area > max_area) {
            sx = i;
            dx = j;
            max_area = current_area;
        }

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return max_area;
}

int main(int argc, char** argv) {
    vector<int> height {1, 1, 2, 10, 200};

    cout << maxArea(height) << endl;
    return 0;
}