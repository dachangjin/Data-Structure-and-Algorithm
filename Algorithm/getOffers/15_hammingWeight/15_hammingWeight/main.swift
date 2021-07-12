//
//  main.swift
//  15_hammingWeight
//
//  Created by tommywwang on 2021/6/7.
//

import Foundation

class Solution {
    func hammingWeight(_ n: Int) -> Int {
        var count = 0
        var num = n
        while num != 0 {
            if num & 1 == 1 {
                count += 1
            }
            num = num >> 1
        }
        return count
    }
}

let sol = Solution()
print(sol.hammingWeight(10))
