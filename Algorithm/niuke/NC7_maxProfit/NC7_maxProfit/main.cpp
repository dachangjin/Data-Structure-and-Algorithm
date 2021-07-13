//
//  main.cpp
//  NC7_maxProfit
//
//  Created by wangwei on 2021/7/13.
//

#include <iostream>
#include <vector>

using namespace std;

// NC7 买卖股票的最好时机
// https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec?tpId=188&&tqId=38556&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 记录当前最小值，使用当前值减去当前最小值获得利润。使用maxVal记录当前最大利润
class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        if (prices.size() == 0) {
            return 0;
        }
        int minVal = prices[0];
        int maxVal = 0;
        for (int val : prices) {
            minVal = min(minVal, val);
            maxVal = max(maxVal, val - minVal);
        }
        return maxVal;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
