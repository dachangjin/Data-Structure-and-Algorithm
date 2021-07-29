//
//  main.cpp
//  78_subsets
//
//  Created by wangwei on 2021/7/28.
//

#include <iostream>
#include <vector>

using namespace std;

// 78. 子集
// https://leetcode-cn.com/problems/subsets/
//
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(results, result, nums, 0);
        return results;
    }

    void dfs(vector<vector<int>> &results, vector<int> result, vector<int> &nums, int start) {
        // 无条件加入结果数组中
        results.push_back(result);
        for (int i = start; i < nums.size(); i ++) {
            result.push_back(nums[i]);
            // 从下一个开始选择，i+1
            dfs(results, result, nums, i + 1);
            result.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
