//
//  main.cpp
//  42_maxSubArray
//
//  Created by tommywwang on 2021/6/11.
//

#include <iostream>
#include <vector>

using namespace std;
/*
 https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 连续子数组最大和
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max = nums[0];
        int sum = 0;
        for (int i: nums) {
            if (sum < 0) {
                sum = i;
            } else {
                sum += i;
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
