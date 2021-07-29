//
//  main.cpp
//  90_ binary_search
//
//  Created by wangwei on 2021/7/28.
//

#include <iostream>
#include <vector>

using namespace std;

// 90. 子集 II
// https://leetcode-cn.com/problems/subsets-ii/
// 先排序，再使用数组去重
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        sort(nums.begin(), nums.end());
        dfs(results, result, nums, 0);
        return results;
    }

    void dfs(vector<vector<int>> &results, vector<int> &result, vector<int> &nums, int start) {
        results.push_back(result);
        vector <int> used;
        for (int i = start; i < nums.size(); i ++) {
            int val = nums[i];
            // if (find(used.begin(), used.end(), val) != used.end()) {
            //     continue;
            // }
            // 有序数组，使用二分查找
            if (binary_search(used.begin(), used.end(), val)) {
                continue;
            }
            used.push_back(val);
            result.push_back(val);
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
