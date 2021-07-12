//
//  main.swift
//  24_reverseList
//
//  Created by wangwei on 2021/6/8.
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
    func reverseList(_ head: ListNode?) -> ListNode? {
        if head == nil {
            return head
        }
        var newHead: ListNode? = nil
        var tempHead = head
        while tempHead != nil {
            let tempNext = tempHead?.next
            tempHead?.next = newHead
            newHead = tempHead
            tempHead = tempNext
        }
        return newHead
    }
}
