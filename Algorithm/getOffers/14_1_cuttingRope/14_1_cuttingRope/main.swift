//
//  main.swift
//  14_1_cuttingRope
//
//  Created by tommywwang on 2021/5/21.
//

import Foundation

class Solution {
    
    var cuttedLength = 0
    var max = 0
    var n = 0
    var pieces = [Int]()
    // dfs加回溯。超时了
    func cuttingRope1(_ n: Int) -> Int {
        max = 0
        self.n = n
        dfs()
        return max
    }
    
    func dfs() {
        if cuttedLength == self.n {
            var result = 0
            if self.pieces.count <= 1 {
                result = 0
            } else {
                result = 1
                for num in self.pieces {
                    result *= num
                }
            }
            if result > max {
                max = result
            }
            return
        }
        for num in 1...self.n - self.cuttedLength {
            self.pieces.append(num)
            self.cuttedLength += num
            dfs()
            self.pieces.removeLast()
            self.cuttedLength -= num
        }
    }
    
    
    // 动态规划，n为长度为n的
    func cuttingRope(_ n: Int) -> Int {
        if n == 2 {
            return 1
        }
        var results: [Int] = Array.init(repeating: 0, count: n + 1)
        results[0] = 0;
        results[1] = 1
        results[2] = 1
        // j为第一刀从哪开始剪，每段绳子至少先剪一刀，从1开始剪。
        for i in 3...n {
            for j in 1...(i/2) {
                // 剪一刀后绳子分为i-j和j。需要继续剪最大乘积就是results[i-j] * j，不需要继续剪就是(i - j) * j
                // 有可能剪一刀才是最大的，比如n为3时，i=3,j=1,最大就是2*1=2，而不是results[i-j] * j -> 1*1
                results[i] = Swift.max(results[i], Swift.max(results[i-j] * j, (i - j) * j))
            }
        }
        return results[n]
    }
}

let sol = Solution()
print(sol.cuttingRope1(20))
print(sol.cuttingRope(20))
