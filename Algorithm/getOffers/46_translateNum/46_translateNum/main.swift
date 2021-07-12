//
//  main.swift
//  46_translateNum
//
//  Created by wangwei on 2021/6/22.
//

import Foundation

/*
 剑指 Offer 46. 把数字翻译成字符串
 https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 动态规划：nums[i]为数字前i个字符组成的string中最多的翻译方法
 判断当前数字和前一位组合是否在10到25范围内。若是则类似爬楼梯，可以选当前数组或者当前数组和前一个数组组合在一起变为一个字母。即nums[i] = nums[i-1] + nums[i-2]。不在范围内相当于在之前的基础上加了一个字母，翻译方法种类不变，即nums[i] = nums[i-1]
 */

class Solution {
    func translateNum(_ num: Int) -> Int {
        let string = String(num)
//        var nums = Array.init(repeating: 0, count: string.count + 1)
//        nums[0] = 1
//        nums[1] = 1
        var a = 1
        var b = 1
        for index in 2...string.count {
            let start = string.startIndex
            let startIndex = string.index(start, offsetBy: index - 2)
            let endIndex = string.index(start, offsetBy: index - 1)
            let subString = string[startIndex...endIndex]
            let num = Int(subString)!
            if num >= 10 && num <= 25 {
//                nums[index] = nums[index - 1] + nums[index - 2]
                let tem = a
                a = a + b
                b = tem
            } else {
//                nums[index] = nums[index - 1]
                b = a
                
            }
        }
//        return nums[string.count]
        return a
    }
}

let num = 12258
let sol = Solution()
print(sol.translateNum(num))
