//
//  main.swift
//  05_replaceSpace
//
//  Created by wangwei on 2021/5/19.
//

import Foundation
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
// 正规做法是先计算空格数量得出字符串需要的长度，再从后往前覆盖即可
// 这里直接利用api完成
class Solution {
    func replaceSpace(_ s: String) -> String {
        return s.replacingOccurrences(of: " ", with: "%20")
    }
}

let sol = Solution()
print(sol.replaceSpace("We are happy."))
