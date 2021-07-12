//
//  main.cpp
//  NC105_search
//
//  Created by wangwei on 2021/7/12.
//

#include <iostream>
#include <vector>

using namespace std;

// NC105 二分查找-II
// 查找排序数组中第一个数
// 思路：用被查找数减去0.5。查找的时候注意中间值大于的情况，end应该等于mid，而不是mid-1

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        if (nums.size() == 0) return -1;
        int start = 0;
        int end = (int)nums.size() - 1;
        double tar = target - 0.5;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > tar) {
                end = mid;
            } else if (nums[mid] < tar) {
                start = mid + 1;
            }
        }
        return nums[start] == target ? start : -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    int index = sol.search(nums, 4);
    return 0;
}
