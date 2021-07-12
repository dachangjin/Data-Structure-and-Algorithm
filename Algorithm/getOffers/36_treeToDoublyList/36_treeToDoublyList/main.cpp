//
//  main.cpp
//  36_treeToDoublyList
//
//  Created by tommywwang on 2021/6/9.
//

#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/submissions/
/*
 第一步中序遍历BST，传入节点构建链表，节点最后会移动到链表末尾
 第二步将节点移到链表头部
 第三部构建循环列表
 */
class Solution {
public:
    
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return root;
        }
        Node *head = NULL;
        //第一步
        dfs(&head, root);
        //第二步
        Node *last = head;
        while (head->left != NULL) {
            head = head->left;
        }
        //第三步 构造循环链表
        head->left = last;
        last->right = head;
        return head;
        
    }
    // 需要传指向指针的指针
    void dfs(Node **head, Node *node) {
        if (node == NULL) {
            return;
        }
        if (node->left != NULL) {
            dfs(head, node->left);
        }
        if (*head == NULL) {
            *head = node;
        } else {
            (*head)->right = node;
            node->left = *head;
            *head = node;
        }
        if (node->right != NULL) {
            dfs(head, node->right);
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Node *root = new Node(4);
    Node *node2 = new Node(2);
    Node *node5 = new Node(5);
    Node *node1 = new Node(1);
    Node *node3 = new Node(3);
    root->left = node2;
    root->right = node5;
    node2->left = node1;
    node2->right = node3;
    Solution sol;
    sol.treeToDoublyList(root);
    return 0;
}
