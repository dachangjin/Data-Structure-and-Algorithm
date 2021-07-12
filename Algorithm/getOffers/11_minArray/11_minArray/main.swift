//
//  main.swift
//  11_minArray
//
//  Created by wangwei on 2021/5/20.
//

import Foundation

// 旋转数组的最小数字, 利用二分查找
// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
// [2, 0, 2, 2, 2]
class Solution {
    func minArray(_ numbers: [Int]) -> Int {
        if numbers.count == 0 {
            return -1
        }
        if numbers.count == 1 {
            return numbers.first!
        }
        return findMinInArray(numbers, 0, numbers.count - 1)
    }
    
    func findMinInArray(_ numbers: [Int],
                        _ start: Int,
                        _ end: Int) -> Int {
        if start == end {
            return numbers[start]
        }
        // 刚好找到的区间为顺序排列，返回第一个
        if numbers[start] < numbers[end] {
            return numbers[start]
        }
        let position = (start + end) / 2
        if numbers[position] > numbers[start] {
            // 在position后面查找
            return findMinInArray(numbers, position + 1, end)
        } else if numbers[position] < numbers[start] {
            // 在position前面查找
            return findMinInArray(numbers, start, position)
        } else {
            // [2,2,2,2,0,2] 或[2,0,2,2,2,2] 两边都可能出现最小值
            return min(findMinInArray(numbers, start, position), findMinInArray(numbers, position + 1, end))
        }
    }
}

let sol = Solution()
print(sol.minArray([4,5,6,7,0,1,2]))
