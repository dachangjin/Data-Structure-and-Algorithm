//
//  main.cpp
//  NC53_removeNthFromEnd
//
//  Created by tommywwang on 2021/7/22.
//

#include <iostream>


struct ListNode {
    int val;
    struct ListNode *next;
};
 
// NC53 删除链表的倒数第n个节点
// https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=188&&tqId=38587&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 快慢指针，快指针走k步。使用创建新的辅助头结点，慢指针指向新的头结点。快慢指针一起走，快指针走到null，慢指针后面一个即为需要删掉的节点
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param n int整型
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newHead = new ListNode();
        newHead->next = head;
        ListNode *fast = head;
        while (n > 0 && fast) {
            fast = fast->next;
            n--;
        }
        ListNode *slow = newHead;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return newHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
