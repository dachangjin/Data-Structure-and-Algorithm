//
//  main.cpp
//  NC46combinationSum2
//
//  Created by wangwei on 2021/7/12.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        if (num.size() == 0) {
            return result;
        }
        sort(num.begin(), num.end());
        vector<int> array;
        
        dfs(result, array, num, 0, (int)num.size(), target);
        
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<int> &array, vector<int> &source, int start, int end, int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(array);
            return;
        }
        vector<int> contain;
        for (int i = start; i < end; i ++) {
            // 去重
            if (find(contain.begin(), contain.end(), source[i]) != contain.end()) {
                continue;
            }
            contain.push_back(source[i]);
            array.push_back(source[i]);
            dfs(result, array, source ,i + 1, end, target - source[i]);
            array.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<int> vec;
    vec.push_back(100);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(70);
    vec.push_back(60);
    vec.push_back(10);
    vec.push_back(50);
    sol.combinationSum2(vec, 80);
    return 0;
}
