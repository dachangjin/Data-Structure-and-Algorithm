//
//  main.swift
//  56_singleNumbers
//
//  Created by wangwei on 2021/6/23.
//

import Foundation

/*
 https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 剑指 Offer 56 - I. 数组中数字出现的次数
 若一个数组只包含一个唯一值，其他的数的个数都是2的倍数。那么遍历数组异或就可得到此唯一值
 此题可以把数组分为两个数组分别包含one或two
 
 求两个唯一的数one，two。先遍历所有数组求异或。得到one^two。找到one^two第一个位为1的值。使用这个值将数组以one，two分开。然后分别遍数异或。最终得到one，two。
 */
class Solution {
    func singleNumbers(_ nums: [Int]) -> [Int] {
        var one = 0
        var two = 0
        var result = 0
        // 求出one^two
        for num in nums {
            result = result ^ num
        }
        // 求出one^two第一个位为1的数x
        var x = 1
        while x & result == 0 {
            x = x << 1
        }
        //使用x将nums分为两个数组分别求异或得到最终结果
        for num in nums {
            if num & x == 0 {
                one = one ^ num
            } else {
                two = two ^ num
            }
        }
        return [one, two]
    }
}

let sol = Solution()
let results = sol.singleNumbers([1,2,10,4,1,4,3,3])
print(results)

