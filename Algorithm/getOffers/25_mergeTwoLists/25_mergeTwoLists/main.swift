//
//  main.swift
//  25_mergeTwoLists
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
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        }
        if l2 == nil {
            return l1
        }
        let newHead: ListNode? = ListNode(0)
        var tempHead = newHead
        var temp1 = l1
        var temp2 = l2
        while temp1 != nil && temp2 != nil {
            if temp1!.val > temp2!.val {
                tempHead?.next = ListNode(temp2!.val)
                temp2 = temp2?.next
            } else {
                tempHead?.next = ListNode(temp1!.val)
                temp1 = temp1?.next
            }
            tempHead = tempHead?.next
        }
        if temp1 == nil {
            tempHead?.next = temp2
        }
        if temp2 == nil {
            tempHead?.next = temp1
        }
        return newHead?.next
    }
}
