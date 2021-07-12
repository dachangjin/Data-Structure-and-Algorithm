//
//  main.swift
//  06_reversePrint
//
//  Created by wangwei on 2021/5/20.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
    
    public init(_ val: Int, _ next: ListNode?) {
        self.val = val
        self.next = next
    }
}

class Solution {
    func reversePrint(_ head: ListNode?) -> [Int] {
        var vals = [Int]()
        addNodeVal(head, &vals)
        return vals
    }
    
    func addNodeVal(_ node: ListNode? ,_ vals: inout [Int]) {
        if node != nil {
            addNodeVal(node!.next, &vals)
            vals.append(node!.val)
        }
    }
}

var head = ListNode(1, ListNode(2, ListNode(3, nil)))
let sol = Solution()
print(sol.reversePrint(nil))
