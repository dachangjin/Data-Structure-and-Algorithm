//
//  main.swift
//  57_findContinuousSequence
//
//  Created by wangwei on 2021/6/24.
//

import Foundation

/*
 https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/submissions/
 剑指 Offer 57 - II. 和为s的连续正数序列
 采用滑动窗口阶梯解题
 初始窗口为[1,2]
 
 */

class Solution {
    func findContinuousSequence(_ target: Int) -> [[Int]] {
        var results = [[Int]]()
        if target <= 2 {
            return results
        }
        //初始窗口边界
        var preNum = 1
        var suffNum = 2
        var sum = preNum + suffNum
        while preNum < suffNum {
            if sum > target {
                // 窗口从左边界缩小
                sum -= preNum
                preNum += 1
            } else if sum < target {
                // 窗口从右边界扩大
                suffNum += 1
                sum += suffNum
            } else {
                let result = Array(preNum...suffNum)
                results.append(result)
                // 窗口从左边界缩小
                sum -= preNum
                preNum += 1
            }
        }
        return results
    }
}

let sol = Solution()
print(sol.findContinuousSequence(23))
