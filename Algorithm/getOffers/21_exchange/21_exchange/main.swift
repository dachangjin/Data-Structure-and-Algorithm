//
//  main.swift
//  21_exchange
//
//  Created by wangwei on 2021/6/8.
//

import Foundation

class Solution {
    func exchange(_ nums: [Int]) -> [Int] {
        if nums.count < 2 {
            return nums
        }
        var numbers = nums
        var fast = nums.count - 1
        var slow = 0
        while fast > slow {
            let fastVal = numbers[fast]
            let slowVal = numbers[slow]
            if fastVal & 1 == 1 && slowVal & 1 == 0 {
                numbers[fast] = numbers[slow]
                numbers[slow] = fastVal
                fast -= 1
                slow += 1
            }
            if fastVal & 1 == 0 {
                fast -= 1
            }
            if slowVal & 1 == 1 {
                slow += 1
            }
        }
        return numbers
    }
}

