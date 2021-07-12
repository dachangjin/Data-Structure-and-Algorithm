//
//  main.swift
//  13_movingCount
//
//  Created by wangwei on 2021/5/21.
//

import Foundation

// 机器人的运动范围。深度优先搜索
// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
class Solution {
    func movingCount(_ m: Int, _ n: Int, _ k: Int) -> Int {
        if m == 0 || n == 0 {
            return 0
        }
        var maxCount = 0
        var cap: [[Bool]] = Array(repeating: Array(repeating: false, count: n), count: m)
        dfs(&cap,
            &maxCount,
            m,
            n,
            0,
            0,
            k)
        return maxCount
    }
    
    func dfs(_ cap: inout [[Bool]], _ maxCount: inout Int , _ m: Int, _ n: Int, _ currentM: Int, _ currentN: Int, _ k: Int) {
        if (currentM / 10 + currentM % 10 + currentN / 10 + currentN % 10) > k {
            return
        }
        if cap[currentM][currentN] {
            return
        }
        cap[currentM][currentN] = true
        maxCount += 1
        let direction = [(-1, 0), (1, 0), (0 , -1), (0, 1)]
        for (i, j) in direction {
            let row = currentM + i
            let col = currentN + j
            if row < 0 || row >= m || col < 0 || col >= n {
                continue
            }
            dfs(&cap,
                &maxCount,
                m,
                n,
                row,
                col,
                k)
        }
    }
}

let sol = Solution()
print(sol.movingCount(2, 3, 1))
