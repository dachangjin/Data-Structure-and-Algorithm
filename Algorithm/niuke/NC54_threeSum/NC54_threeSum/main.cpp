//
//  main.cpp
//  NC54_threeSum
//
//  Created by wangwei on 2021/7/30.
//

#include <iostream>
#include <vector>

using namespace std;

// NC54 数组中相加和为0的三元组
// https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711?tpId=194&&tqId=35786&rp=1&ru=/activity/oj&qru=/ta/job-code-high-client/question-ranking
// 先排序，然后遍历。使用双指针。
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // 先排序
        sort(num.begin(), num.end());
        vector<vector<int>> results;
        if (num.size() < 3) return results;
        for (int i = 0; i < num.size() - 1; i++) {
            // 排序后去重
            if (i == 0 || num[i] != num[i - 1]) {
                // 左右边界
                int left = i + 1;
                int right = (int)num.size() - 1;
                while (left < right) {
                    int val = num[i] + num[left] + num[right];
                    if (val < 0) {
                        left++;
                    } else if (val > 0) {
                        right--;
                    } else {
                        vector<int> result;
                        result.push_back(num[i]);
                        result.push_back(num[left]);
                        result.push_back(num[right]);
                        results.push_back(result);
                        // 左边界++直到不等于之前左边界的值为止，否则可能出现重复比如-2,0,0,2,2
                        while (left < right && num[left] == result[1]) left ++;
                    }
                }
            }
        }
        return results;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<int> nums = {-10,0,10,20,-10,-40};
    sol.threeSum(nums);
    return 0;
}
