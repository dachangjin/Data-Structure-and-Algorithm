//
//  main.swift
//  04_findNumberIn2DArray
//
//  Created by tommywwang on 2021/5/19.
//
// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
import Foundation

// 根据数组特性，按位置排除，时间复杂度n+n
class Solution {
    func findNumberIn2DArray(_ matrix: [[Int]], _ target: Int) -> Bool {
        if matrix.count == 0 {
            return false
        }
        let row = matrix.count
        let col = matrix.first!.count
        var rowIndex = 0
        var colIndex = col - 1
        while rowIndex < row && colIndex >= 0 {
            let num = matrix[rowIndex][colIndex]
            if num > target {
                colIndex -= 1
            } else if num < target {
                rowIndex += 1
            } else {
                return true
            }
        }
        return false
    }
}

let matrix = [[20]
  ]
let sol = Solution()
print(sol.findNumberIn2DArray(matrix, 20))
