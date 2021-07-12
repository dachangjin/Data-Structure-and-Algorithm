//
//  main.swift
//  18_deleteNode
//
//  Created by wangwei on 2021/6/7.
//

import Foundation


public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func deleteNode(_ head: ListNode?, _ val: Int) -> ListNode? {
        if head == nil {
            return head
        }
        if head?.val == val {
            return head?.next
        }
        var newHead = head
        while newHead?.next != nil {
            if newHead?.next?.val == val {
                newHead?.next = newHead?.next?.next
                return head
            }
            newHead = newHead?.next
        }
        return head
    }
}
