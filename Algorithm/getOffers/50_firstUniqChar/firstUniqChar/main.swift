//
//  main.swift
//  firstUniqChar
//
//  Created by wangwei on 2021/6/23.
//

import Foundation
/*
 剑指 Offer 50. 第一个只出现一次的字符
 https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/submissions/
 可以使用数组存储个数节省空间。两次遍历字符串。
 */
class Solution {
    func firstUniqChar(_ s: String) -> Character {
        var dict: [String.Element: Int] = Dictionary()
        for char in s {
            let count = dict[char]
            dict[char] = (count ?? 0) + 1
        }
        for char in s {
            let count = dict[char]
            if count == 1 {
                return Character(extendedGraphemeClusterLiteral: char)
            }
        }
        return Character(" ")
    }
}

let sol = Solution()
print(sol.firstUniqChar("abaccdeff"))
