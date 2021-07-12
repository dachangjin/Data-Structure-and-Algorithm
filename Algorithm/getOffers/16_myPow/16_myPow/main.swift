//
//  main.swift
//  16_myPow
//
//  Created by wangwei on 2021/6/7.
//

import Foundation

class Solution {
    func myPow(_ x: Double, _ n: Int) -> Double {
        if n == 0 {
            return 1
        }
        if n == 1 {
            return x
        }
        if x == 0 {
            return 0
        }
        if n == -1 {
            return 1 / x
        }
        var num = n
        if n < 0 {
            num = -n
        }
        var result = myPow(x, num >> 1)
        result *= result
        if num & 1 == 1 {
            result *= x
        }
        if n < 0 {
            return 1 / result
        }
        return result
    }
}

let sol = Solution()
print(sol.myPow(0.00001
                ,2147483647))
