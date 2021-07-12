//
//  main.swift
//  55_maxDepth
//
//  Created by tommywwang on 2021/6/23.
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
/*
 剑指 Offer 55 - I. 二叉树的深度
 https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
 方法一:递归
 方法二:二叉树层序遍历
 */
class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        return max(maxDepth(root!.left), maxDepth(root!.right)) + 1
    }
}

