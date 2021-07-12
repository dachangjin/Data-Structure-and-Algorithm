//
//  main.cpp
//  37_serializeBinaryTree
//
//  Created by wangwei on 2021/6/9.
//

#include <iostream>
#include <queue>
/*
 https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
 序列化/反序列化二叉树
 */

using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // 分隔符切分字符串为数组
    queue<string> split(string str,std::string pattern)
    {
        std::string::size_type pos;
        std::queue<std::string> result;
        str+=pattern;//扩展字符串以方便操作
        int size=str.size();
        for(int i=0; i<size; i++)
        {
            pos=str.find(pattern,i);
            if(pos<size)
            {
                std::string s=str.substr(i,pos-i);
                result.push(s);
                i=pos+pattern.size()-1;
            }
        }
        return result;
    }
    
    /*
     序列化
     层序遍历，判断left和right是否为空。为空则将null加入数组，否则将值加入数组，并将节点加入队列。需要注意的是最后数组末尾会多出很多null，需要剔除
     */
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string result("[");
        queue<TreeNode *> que;
        que.push(root);
        vector<string> vals;
        vals.push_back(to_string(root->val));
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node->left != nullptr) {
                que.push(node->left);
                vals.push_back(to_string(node->left->val));
            } else {
                vals.push_back("null");
            }
            if (node->right != nullptr) {
                que.push(node->right);
                vals.push_back(to_string(node->right->val));
            } else {
                vals.push_back("null");
            }
        }
        while (vals.back() == "null") {
            vals.pop_back();
        }
        vector<string>::iterator it;
        for (it = vals.begin(); it != vals.end(); it ++) {
            result.append(*it);
            result.append(",");
        }
        result.erase(result.length() - 1);
        result.append("]");
        return result;
    }

    /*
     层序遍历还原二叉树
     数值队列中下一个值不为null则说明node的左或者右节点不为null，构建一个节点并加入队列，继续遍历节点队列，直至队列为空
     */
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return nullptr;
        }
        if (data.length() == 3) {
            TreeNode *node = new TreeNode(0);
            string val = data.substr(1, 1);
            node->val = stoi(val);
            return node;
        }
        string value = data.substr(1, data.length() - 2);
        queue<string> vals = this->split(value, ",");
        TreeNode *root = new TreeNode(stoi(vals.front()));
        vals.pop();
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop();
            if (!vals.empty()) {
                string left = vals.front();
                vals.pop();
                if (left != "null") {
                    TreeNode *leftNode = new TreeNode(stoi(left));
                    node->left = leftNode;
                    nodes.push(leftNode);
                }
            }
            if (!vals.empty()) {
                string right = vals.front();
                vals.pop();
                if (right != "null") {
                    TreeNode *rightNode = new TreeNode(stoi(right));
                    node->right = rightNode;
                    nodes.push(rightNode);
                }
            }
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    Codec codec;
    cout<<codec.deserialize(codec.serialize(node1));
    return 0;
}


