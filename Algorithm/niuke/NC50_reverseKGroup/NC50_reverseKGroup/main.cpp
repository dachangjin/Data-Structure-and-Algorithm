//
//  main.cpp
//  NC50_reverseKGroup
//
//  Created by tommywwang on 2021/7/15.
//

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
};

// NC50 链表中的节点每k个一组翻转
// https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=188&&tqId=38557&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 反转链表
// 1.k个一组反转，然后连接
// 2.k个一组反转，递归
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    // 解法1
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        ListNode *newHead = nullptr;
//        int increase = 1;
//        ListNode *start = head;
//        ListNode *end = head;
//        ListNode *temp = head;
//        ListNode *lastEnd = nullptr;
//        bool setHead = false;
//        while (temp != nullptr) {
//            ListNode *tempNext = temp->next;
//            if (increase == k) {
//                end = temp;
//                ListNode *hh = reverseK(start,
//                                        end,
//                                        &temp->next);
//                // 设置新head
//                if (!setHead) {
//                    newHead = hh;
//                    setHead = true;
//                } else {
//                    // 连接上一个k段和此k段
//                    lastEnd->next = hh;
//                }
//                // 保存上一个k端最后一个节点，反转后start即为上一个k段的最后一个节点
//                lastEnd = start;
//                // start继续向下移动
//                start = tempNext;
//
//                increase = 0;
//            }
//            temp = tempNext;
//            increase ++;
//        }
//        if (!newHead) {
//            return head;
//        }
//
//        return newHead;
//    }
//
//    // 反转start到end，将end->当做tempHead
//    ListNode *reverseK(ListNode *start, ListNode *end, ListNode **tempHead) {
//        ListNode *head = nullptr;
//        if (*tempHead) {
//            head = *tempHead;
//        }
//        ListNode *endNext = end->next;
//        while (start != endNext) {
//            ListNode *nextStart = start->next;
//            start->next = head;
//            head = start;
//            start = nextStart;
//        }
//        return head;
//    }
    // 解法2,递归
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        ListNode *node = head;
        for (int i = 0; i < k; i ++) {
            if (!node) {
                return head;
            }
            node = node->next;
        }
        ListNode *newHead = reverseK(head, node);
        head->next = reverseKGroup(node, k);
        return newHead;
    }
    
    ListNode* reverseK(ListNode *start, ListNode *end) {
        ListNode *head = nullptr;
        while (start != end) {
            ListNode *next = start->next;
            start->next = head;
            head = start;
            start = next;
        }
        return head;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *node5 = new ListNode();
    node5->val = 5;
    ListNode *node4 = new ListNode();
    node4->val = 4;
    ListNode *node3 = new ListNode();
    node3->val = 3;
    ListNode *node2 = new ListNode();
    node2->val = 2;
    ListNode *node1 = new ListNode();
    node1->val = 1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution sol;
    sol.reverseKGroup(node1, 2);
    return 0;
}
