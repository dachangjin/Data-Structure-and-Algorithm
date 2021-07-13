//
//  main.cpp
//  NC40_addInList
//
//  Created by tommywwang on 2021/7/13.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// NC40 两个链表生成相加链表
// https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b?tpId=188&&tqId=38610&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 将链表使用数组装入，转为数组和即可。注意进位。
class Solution {
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if (!head1) {
            return head2;
        }
        if (!head2) {
            return head1;
        }
        vector<int> array1;
        vector<int> array2;
        while (head1 != nullptr) {
            array1.push_back(head1->val);
            head1 = head1->next;
        }
        while (head2 != nullptr) {
            array2.push_back(head2->val);
            head2 = head2->next;
        }
        int size1 = (int)array1.size();
        int size2 = (int)array2.size();
        vector<int> longArray = size1 > size2 ? array1 : array2;
        vector<int> shortArray = size1 > size2 ? array2 : array1;
        int longSize = size1 > size2 ? size1 : size2;
        int shortSize = size1 > size2 ? size2 : size1;
        bool more = false;
        while (longSize > 0) {
            int shortNum = 0;
            if (shortSize > 0) {
                shortNum = shortArray[shortSize - 1];
            }
            int num = longArray[longSize - 1] + shortNum + (more ? 1 : 0);
            longArray[longSize - 1] = num % 10;
            more = num >= 10;
            longSize --;
            shortSize--;
        }
        if (more) {
            longArray.insert(longArray.begin(), 1);
        }
        ListNode *head = new ListNode(0);
        ListNode *tempHead = head;
        for (int val : longArray) {
            ListNode *node = new ListNode(val);
            tempHead->next = node;
            tempHead = tempHead->next;
        }
        ListNode *newHead = head->next;
        delete head;
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
