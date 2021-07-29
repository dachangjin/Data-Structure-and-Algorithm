//
//  main.cpp
//  40_combinationSum2
//
//  Created by wangwei on 2021/7/28.
//

#include <iostream>
#include <vector>

using namespace std;


// 40. 组合总和 II
// https://leetcode-cn.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        // 使用used数组来避免重复的情况
        vector<int> used;
        for (int i = start; i < candidates.size(); i++) {
            int val = candidates[i];
            bool isUsed = false;
            // contain判断
            for (int usedVal: used) {
                if (usedVal == val) {
                    isUsed = true;
                    break;
                }
            }
            if (isUsed) continue;
            used.push_back(val);
            if (val + sum > target) {
                break;
            }
            result.push_back(val);
            // 因为不能重复利用，所以使用i+1
            dfs(results, result, candidates, target, sum + val, i + 1);
            result.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
