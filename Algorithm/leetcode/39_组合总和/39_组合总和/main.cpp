//
//  main.cpp
//  39_组合总和
//
//  Created by wangwei on 2021/7/28.
//

#include <iostream>
#include <vector>

using namespace std;

// 39. 组合总和
// https://leetcode-cn.com/problems/combination-sum/
//
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 先排序，从小数字开始选。
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> result;
        dfs(results, result, candidates, target, 0, 0);
        return results;
    }

    void dfs(vector<vector<int>> &results, vector<int> &result, vector<int>& candidates, int target, int sum, int start) {
        if (sum == target) {
            results.push_back(result);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            int val = candidates[i];
            // 大于的话就不用往后走了
            if (val + sum > target) {
                break;
            }
            result.push_back(val);
            // 从i开始，因为可以重复选择自己
            dfs(results, result, candidates, target, sum + val, i);
            result.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
