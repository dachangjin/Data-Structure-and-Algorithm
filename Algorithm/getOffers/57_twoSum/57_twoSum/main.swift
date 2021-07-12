//
//  main.swift
//  57_twoSum
//
//  Created by wangwei on 2021/6/24.
//

import Foundation


/*
 https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 剑指 Offer 57. 和为s的两个数字
 双指针解法
 */
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        if nums.count == 0 {
            return nums
        }
        var results = [Int]()
        var preIndex = 0
        var suffIndex = nums.count - 1
        while preIndex != suffIndex {
            let result = nums[preIndex] + nums[suffIndex]
            if result == target {
                results.append(nums[preIndex])
                results.append(nums[suffIndex])
                return results
            } else if result > target {
                suffIndex -= 1
            } else {
                preIndex += 1
            }
        }
        return results
    }
}
