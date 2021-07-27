//
//  main.cpp
//  NC33_mergeTwoLists
//
//  Created by tommywwang on 2021/7/27.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
};

// NC33 合并有序链表
// https://www.nowcoder.com/practice/a479a3f0c4554867b35356e0d57cf03d?tpId=188&&tqId=38642&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 创建新头结点辅助。对比两个链表，将小的设置为辅助头结点的next。最后直接向不为null的节点设置为next
class Solution {
public:
    /**
     *
     * @param l1 ListNode类
     * @param l2 ListNode类
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        ListNode *newHead = new ListNode();
        ListNode *tempHead = newHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tempHead->next = l1;
                l1 = l1->next;
            } else {
                tempHead->next = l2;
                l2 = l2->next;
            }
            tempHead = tempHead->next;
        }
        if (l1) {
            tempHead->next = l1;
        }
        if (l2) {
            tempHead->next = l2;
        }
        return newHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *node1 = new ListNode();
    ListNode *node2 = new ListNode();
    node1->val = 2;
    node2->val = 1;
    Solution sol;
    sol.mergeTwoLists(node1, node2);
    return 0;
}
