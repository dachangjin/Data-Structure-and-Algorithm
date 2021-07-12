//
//  main.cpp
//  35_copyRandomList
//
//  Created by wangwei on 2021/6/8.
//

#include <iostream>


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1.创建新链表，将新链表和老链表交叉连接
        // A->B->C->D变为A->A'->B->B'->C->C'->D->D'
        if (head == NULL) {
            return  head;
        }
        Node *tempHead = head;
        while (tempHead != NULL) {
            Node *tempNext = tempHead->next;
            Node *newNode = new Node(tempHead->val);
            tempHead->next = newNode;
            newNode->next = tempNext;
            tempHead = tempNext;
        }
        // 2.将新链表按照老链表的random关系连线
        tempHead = head;
        while (tempHead != NULL) {
            Node *newNode = tempHead->next;
            if (tempHead->random != NULL) {
                newNode->random = tempHead->random->next;
            }
            tempHead = newNode->next;
        }
        // 3.将链表拆为新老两个链表
        tempHead = head;
        Node *newHead = tempHead->next;
        Node *newTemp = newHead;
        while (tempHead != NULL) {
            tempHead->next = newTemp->next;
            tempHead = tempHead->next;
            if (tempHead != NULL) {
                newTemp->next = tempHead->next;
                newTemp = newTemp->next;
            }
        }
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    Node *node7 = new Node(7);
    Node *node13 = new Node(13);
    Node *node11 = new Node(11);
    Node *node10 = new Node(10);
    Node *node1 = new Node(1);
    
    node7->next = node13;
    node13->next = node11;
    node11->next = node10;
    node10->next = node1;
    
    node13->random = node7;
    node11->random = node1;
    node10->random = node11;
    node1->random = node7;
    
    Solution sol;
    sol.copyRandomList(node7);
}
