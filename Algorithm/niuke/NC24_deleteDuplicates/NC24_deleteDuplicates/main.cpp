//
//  main.cpp
//  NC24_deleteDuplicates
//
//  Created by wangwei on 2021/7/21.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int val) {
        this->val = val;
    }
};

// NC24 删除有序链表中重复的元素-II
// https://www.nowcoder.com/practice/71cef9f8b5564579bf7ed93fbe0b2024?tpId=188&&tqId=38568&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 创建新头结点辅助。获取next和next->next比较。
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *tempHead = new ListNode(head->val - 1);
        tempHead->next = head;
        ListNode *newHead = tempHead;
        while (newHead->next && newHead->next->next) {
            ListNode *next = newHead->next;
            ListNode *nextNext = next->next;
            if (next->val != nextNext->val) {
                newHead = next;
            } else {
                while (nextNext && next->val == nextNext->val) {
                    nextNext = nextNext->next;
                }
                newHead->next = nextNext;
            }
        }
        return tempHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
