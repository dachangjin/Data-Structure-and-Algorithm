//
//  main.swift
//  12_exist
//
//  Created by wangwei on 2021/5/20.
//

import Foundation

// 矩阵中的路径
// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
// 回溯
class Solution {
    func exist(_ board: [[Character]], _ word: String) -> Bool {
        if word.count == 0 {
            return true
        }
        let row = board.count - 1
        let col = board.first!.count - 1
        var success = false
        let chars = word.map {$0}
        
        for i in 0...row {
            for j in 0...col {
                var cap: [(Int, Int)] = Array()
                cap.append((i, j))
                if success {
                    return success
                }
                place(board,
                      &cap,
                      i,
                      j,
                      chars,
                      0,
                      row,
                      col,
                      &success)
            }
        }
        return success
    }
    func place(_ board: [[Character]], _ cap: inout [(Int, Int)], _ row: Int, _ col: Int, _ chars: [Character], _ index: Int, _ maxRow: Int, _ maxCol: Int, _ success: inout Bool) {
        if index == chars.count {
            success = true
            return
        }
        let direction = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        if row < 0 || row > maxRow || col < 0 || col > maxCol {
            return
        }
        if board[row][col] != chars[index] {
            return
        }
       
        for (i, j) in direction {
            if success {
                return
            }
            let e = (row + i, col + j)
            if cap.contains(where: { (i, j) -> Bool in
                return i == e.0 && j == e.1
            }) {
                continue
            }
            cap.append(e)
            place(board,
                  &cap,
                  row + i,
                  col + j,
                  chars,
                  index + 1,
                  maxRow,
                  maxCol,
                  &success)
            cap.removeLast()
        }
    }
}

let sol = Solution()
let chars: [[Character]] = [["a", "b"]]
print(sol.exist(chars, "ba"))
