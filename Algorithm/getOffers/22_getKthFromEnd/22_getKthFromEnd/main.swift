//
//  main.swift
//  22_getKthFromEnd
//
//  Created by tommywwang on 2021/6/8.
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
 
// 1->2->3->4->5, 和 k = 2.
class Solution {
    func getKthFromEnd(_ head: ListNode?, _ k: Int) -> ListNode? {
        if head == nil || k == 0 {
            return nil
        }
        var fast = head
        var slow = head
        var num = k
        while num > 0 && fast != nil {
            fast = fast?.next
            num -= 1
        }
        if num > 0 && fast == nil {
            // k超出链表长度
            return nil
        }
        while fast != nil {
            slow = slow?.next
            fast = fast?.next
        }
        return slow
    }
}

