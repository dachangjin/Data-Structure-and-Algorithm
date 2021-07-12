//
//  main.swift
//  45_minNumber
//
//  Created by tommywwang on 2021/6/21.
//

import Foundation


/*
 https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 把数组排成最小的数
 先将数组排序
 排序方式为a、b
 比较ab和ba结合后的大小
 然后在遍历数组为字符串即可
 */
class Solution {
    func minNumber(_ nums: [Int]) -> String {
        let results = nums.sorted { (num1, num2) -> Bool in
            let string1 = "\(num1)\(num2)"
            let string2 = "\(num2)\(num1)"
            return Int(string1)! > Int(string2)!
        }
        var result = "";
        for num in results.reversed() {
            result.append(String(num))
        }
        return result
    }
}

let sol = Solution()
let array = [0,0,3,30,34,5,9]
print(sol.minNumber(array))

