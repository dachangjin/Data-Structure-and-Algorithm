//
//  main.cpp
//  39_majorityElement
//
//  Created by wangwei on 2021/6/9.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
 https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 数组中出现次数超过一半的数字
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = 0;
        int count = 0;
        for (int num: nums) {
            if (count == 0) {
                val = num;
            }
            if (val == num) {
                count ++;
            } else {
                count --;
            }
        }
        return val;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<int> val;
    val.push_back(3);
    val.push_back(2);
    val.push_back(1);
    val.push_back(-1);
    val.push_back(3);
    val.push_back(3);
    val.push_back(3);
    cout<<sol.majorityElement(val);
    return 0;
}
