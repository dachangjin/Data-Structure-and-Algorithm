//
//  main.swift
//  17_printNumbers
//
//  Created by wangwei on 2021/6/7.
//

import Foundation

class Solution {
    func printNumbers(_ n: Int) -> [Int] {
        if n == 0 {
            return []
        }
        var num = 1
        for _ in 1...n {
            num *= 10
        }
        var results = [Int]()
        for index in 1..<num {
            results.append(index)
        }
        return results
    }
}

let sol = Solution()
print(sol.printNumbers(1))
