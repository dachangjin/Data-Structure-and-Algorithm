//
//  main.cpp
//  NC133_oddEvenList
//
//  Created by tommywwang on 2021/7/29.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// NC133 链表的奇偶重排
// https://www.nowcoder.com/practice/02bf49ea45cd486daa031614f9bd6fc3?tpId=188&&tqId=38658&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 以链表的节点编号奇偶重排，而非节点值。使用两个辅助链表分别记录奇和偶，然后合并链表。

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
            // write code here
        ListNode *oddHead = new ListNode(0);
        ListNode *evenHead = new ListNode(0);
        ListNode *oddTemp = oddHead;
        ListNode *evenTemp = evenHead;
        // 记录位置
        int index = 1;
        while (head) {
            ListNode *next = head->next;
            if (index % 2 == 0) {
                evenTemp->next = head;
                evenTemp = head;
            } else {
                oddTemp->next = head;
                if (head) {
                    // 奇数链表保持到最后一个非空值，方便连接偶数链表
                    oddTemp = head;
                }
            }
            index ++;
            head = next;
        }
        // 将偶数链表后面置空
        evenTemp->next = nullptr;
        oddTemp->next = evenHead->next;
        return oddHead->next;
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
    sol.oddEvenList(node1);
    return 0;
}
