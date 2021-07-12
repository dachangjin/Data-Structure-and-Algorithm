//
//  main.swift
//  03_findRepeatNumber
//
//  Created by tommywwang on 2021/5/19.
//

import Foundation

class Solution {
    func findRepeatNumber(_ nums: [Int]) -> Int {
        var tempNums = nums
        var hasTagZero = false
        for index in 0..<tempNums.count {
            let num = abs(tempNums[index])
            if tempNums[num] > 0 {
                // 改变对应num为负
                tempNums[num] = -tempNums[num]
            } else if hasTagZero && tempNums[num] == 0 {
                // 0取反还是为0,需要特殊处理
                return num
            } else if tempNums[num] < 0 {
                // 为负说明之前已经修改过，则为重复的数
                return num
            }
            if num == 0 {
                hasTagZero = true
            }
        }
        return -1
    }
}

var sol = Solution()
print(sol.findRepeatNumber([0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]))
