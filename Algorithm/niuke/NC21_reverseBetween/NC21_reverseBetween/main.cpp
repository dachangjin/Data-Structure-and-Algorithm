//
//  main.cpp
//  NC21_reverseBetween
//
//  Created by wangwei on 2021/7/30.
//

#include <iostream>


struct ListNode {
    int val;
    struct ListNode *next;
    
    ListNode(int i) {
        this->val = i;
    }
};

// NC21 链表内指定区间反转
// https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=188&&tqId=38555&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 使用辅助头结点。
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *mNode = newHead;
        ListNode *nNode = newHead;
        ListNode *preM = newHead;
        ListNode *afterN = newHead;
        // 获取第m个节点和第m-1个节点
        while (m != 0) {
            mNode = mNode->next;
            m --;
            if (m == 1) {
                preM = mNode;
            }
        }
        // 获取第n个节点
        while (n != 0) {
            nNode = nNode->next;
            n --;
        }
        // 获取第n+1个节点
        afterN = nNode->next;
        // 将第n个节点与后面断开，方便反转链表
        nNode->next = nullptr;
        // 反正链表
        reverse(mNode);
        // 拼接链表
        preM->next = nNode;
        mNode->next = afterN;
        
        return newHead->next;
    }
    
    void reverse(ListNode *start) {
        ListNode *head = nullptr;
        while (start) {
            ListNode *next = start->next;
            
            start->next = head;
            head = start;

            start = next;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution sol;
    sol.reverseBetween(node1, 2, 4);
    return 0;
}
