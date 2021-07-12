//
//  main.swift
//  07_buildTree
//
//  Created by tommywwang on 2021/5/20.
//

import Foundation

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
         self.val = val
         self.left = nil
         self.right = nil
    }
}

// 重建二叉树
// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
// [3,9,20,15,7]
// [9,3,15,20,7]
class Solution {
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        if preorder.count == 0 || inorder.count == 0 || preorder.count != inorder.count {
            return nil
        }
        let val = preorder.first!
        let node = TreeNode(val)
        if preorder.count == 1 {
            return node
        }
        return self.buildNode(preorder, 0, preorder.count - 1, inorder, 0, inorder.count - 1)
    }
    
    func buildNode(_ preorder: [Int],
                   _ preStart: Int,
                   _ preEnd: Int,
                   _ inorder: [Int],
                   _ inStart: Int,
                   _ inEnd: Int) -> TreeNode? {
        if preStart >= preorder.count ||
            inStart >= inorder.count ||
            preStart > preEnd ||
            inStart > inEnd{
            return nil
        }
        let val = preorder[preStart]
        let node = TreeNode(val)
        if preStart == preEnd || inStart == inEnd {
            return node
        }
        var preCount = 0
        var inIndex = 0
        for index in inStart...inEnd {
            if val == inorder[index] {
                inIndex = index
                break
            }
            preCount += 1
        }
        node.left = buildNode(preorder, preStart + 1, preStart + preCount, inorder, inStart, inIndex - 1)
        node.right = buildNode(preorder, preStart + preCount + 1, preEnd, inorder, inIndex + 1, inEnd)
        return node
    }
}

let sol = Solution()
let node = sol.buildTree([], [])
print(node ?? "nil")
