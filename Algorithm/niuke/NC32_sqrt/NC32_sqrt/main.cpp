//
//  main.cpp
//  NC32_sqrt
//
//  Created by wangwei on 2021/7/14.
//

#include <iostream>

using namespace std;
// NC32 求平方根
// https://www.nowcoder.com/practice/09fbfb16140b40499951f55113f2166c?tpId=188&&tqId=38559&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 二分查找，注意精度问题
class Solution {
public:
    /**
     *
     * @param x int整型
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        long low = 0;
        long high = x;
        while (low <= high) {
            long mid = low + ((high - low) >> 1);
            if (mid * mid == x) {
                return (int)mid;
            } else if (mid * mid > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)high;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    int res = sol.sqrt(1518991037);
    cout << res;
    return 0;
}
