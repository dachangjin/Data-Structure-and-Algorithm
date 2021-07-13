//
//  main.cpp
//  NC19_maxsumofSubarray
//
//  Created by tommywwang on 2021/7/13.
//

#include <iostream>
#include <vector>

using namespace std;
// NC19 子数组的最大累加和问题
// https://www.nowcoder.com/practice/554aa508dd5d4fefbf0f86e5fe953abd?tpId=188&&tqId=38594&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 动态规划简化
class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int>& arr) {
        int maxSum = 0;
        int sum = 0;
        for (int num : arr) {
            sum += num;
            if (sum < 0) {
                sum = 0;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
