//
//  main.cpp
//  NC42_permuteUnique
//
//  Created by tommywwang on 2021/7/28.
//

#include <iostream>
#include <vector>

using namespace std;

// NC42 有重复项数字的所有排列
// https://www.nowcoder.com/practice/a43a2b986ef34843ac4fdd9159b69863?tpId=188&&tqId=38618&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 全排列去重。使用数组添加已经排过的数组，来去重
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> results;
        if (num.size() == 0) return results;
        dfs(results, num, 0);
        return results;
    }
    
    void dfs(vector<vector<int>> &results, vector<int> &num, int index)
    {
        if (index == num.size()) {
            results.push_back(num);
            return;
        }
        // 使用array来保存当前已经排过的数字
        vector<int> array;
        for (int i = index; i < num.size(); i ++) {
            bool contain = false;
            for (int val : array) {
                if (val == num[i]) {
                    contain = true;
                }
            }
            if (contain) continue;
            array.push_back(num[i]);
            swap(num[i], num[index]);
            dfs(results, num, index + 1);
            swap(num[i], num[index]);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<int> num = {1,2,3};
    sol.permuteUnique(num);
    return 0;
}
