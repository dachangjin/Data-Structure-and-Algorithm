//
//  main.cpp
//  NC96_isPail
//
//  Created by tommywwang on 2021/7/27.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
};

// NC96 判断一个链表是否为回文结构
// https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f?tpId=188&&tqId=38562&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 先找到中间点后面一个。然后反转以此点位头结点的链表。再对比原始头结点和反转后的链表

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast) {
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            } else {
                fast = fast->next;
            }
        }
        ListNode *newHead = this->reverseList(slow);
        while (newHead && head) {
            if (newHead->val != head->val) {
                return false;
            }
            newHead = newHead->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        while (head) {
            ListNode *next = head->next;
            
            head->next = newHead;
            newHead = head;
            
            head = next;
        }
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *node1 = new ListNode();
    node1->val = 1;
    ListNode *node2 = new ListNode();
    node2->val = 2;
    ListNode *node3 = new ListNode();
    node3->val = 2;
    ListNode *node4 = new ListNode();
    node4->val = 1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution sol;
    sol.isPail(node1);
    return 0;
}
