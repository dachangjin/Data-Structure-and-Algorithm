//
//  main.swift
//  14_2_cuttingRope
//
//  Created by tommywwang on 2021/6/11.
//

import Foundation

class Solution {
    // 没小段切为3可取最大值
    func cuttingRope(_ n: Int) -> Int {
        if n == 2 {
            return 1
        }
        if n == 3 {
            return 2
        }
        if n == 4 {
            return 4
        }
        var result = 1
        var num = n
        while num > 4 {
            result *= 3
            result %= 1000000007
            num -= 3
        }
        return (result * num) % 1000000007
    }
}
let sol = Solution()
print(sol.cuttingRope(10))
