//
//  main.swift
//  10_fib
//
//  Created by tommywwang on 2021/5/20.
//

import Foundation

class Solution {
    func fib(_ n: Int) -> Int {
        if n <= 1 {
            return n
        }
        var val = 0
        var first = 0
        var second = 1
        for _ in 2...n {
            val = (first + second) % 1000000007
            first = second
            second = val
        }
        return val
    }
    
    func numWays(_ n: Int) -> Int {
        if n == 0 {
            return 1
        }
        if n <= 2 {
            return n
        }
        var val = 0
        var first = 1
        var second = 2
        for _ in 3...n {
            val = (first + second) % 1000000007
            first = second
            second = val
        }
        return val
    }
}

let sol = Solution()
print(sol.fib(95))
print(sol.numWays(2))


