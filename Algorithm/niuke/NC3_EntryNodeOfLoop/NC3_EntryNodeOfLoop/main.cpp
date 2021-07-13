//
//  main.cpp
//  NC3_EntryNodeOfLoop
//
//  Created by wangwei on 2021/7/14.
//

#include <iostream>

// NC3 链表中环的入口结点
// https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=188&&tqId=38577&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 先判断有没有环，有环的话一个从相遇点开始，一个从头开始。每次前进一步，再次相遇点就是环点
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        
        // 先判断有么有环
        while (fast != nullptr) {
            ListNode *nextFast = fast->next;
            if (nextFast == nullptr) {
                // 没有环
                return nextFast;
            }
            fast = nextFast->next;
            slow = slow->next;
            if (fast == slow) {
                // 跑一圈追赶的节点
                break;
            }
        }
        // 没有环
        if (fast == nullptr) {
            return fast;
        }
        // 确定有环后，一个从head开始，一个从相遇点开始，每次前进一步，再次相遇时就是环点
        slow = pHead;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
