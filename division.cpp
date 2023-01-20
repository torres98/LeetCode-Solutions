#include <climits>
#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    int res = 0;

    bool is_result_negative = (dividend < 0) ^ (divisor < 0);

    if (is_result_negative) {  
        long div = -(long) (divisor);

        if (dividend < 0) {
            if (dividend == INT_MIN && divisor == 1)
                return INT_MIN;

            while (dividend <= div) {
                dividend += divisor;
                res--;
            }
        } else {
            while (dividend >= div) {
                dividend += divisor;
                res--;
            }
        }
    } else {
        if (dividend < 0) {
            if (dividend == INT_MIN && divisor == -1)
                return INT_MAX;

            while (dividend <= divisor) {
                dividend -= divisor;
                res++;
            }
        } else {
            while (dividend >= divisor) {
                dividend -= divisor;
                res++;
            }
        }
    }

    return res;
}


int main(int argc, char** argv) {
    cout << divide(atoi(argv[1]), atoi(argv[2])) << endl;

    return 0;
}