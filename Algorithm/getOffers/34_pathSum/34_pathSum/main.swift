//
//  main.swift
//  34_pathSum
//
//  Created by wangwei on 2021/6/8.
//
// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
import Foundation


    
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() {
        self.val = 0
        self.left = nil
        self.right = nil
        
    }
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
 }
 
class Solution {
    var results = [[Int]]()
    func pathSum(_ root: TreeNode?, _ target: Int) -> [[Int]] {
        if root == nil {
            return results
        }
        var nums = [Int]()
        self.pathSub(root, target, &nums)
        return results
    }
    
    func pathSub(_ node: TreeNode?, _ target: Int, _ nums: inout [Int]) {
        if node == nil {
            return
        }
        nums.append(node!.val)
        if node!.val == target && node!.left == nil && node!.right == nil{
            results.append(nums)
        } else {
            pathSub(node!.left, target - node!.val, &nums)
            pathSub(node!.right, target - node!.val, &nums)
        }
        nums.removeLast()
    }
}

let root = TreeNode(1, TreeNode(-2, TreeNode(1, TreeNode(-1), nil), TreeNode(3)), TreeNode(-3, TreeNode(-2), nil))

let sol = Solution()
print(sol.pathSum(root, -1))
