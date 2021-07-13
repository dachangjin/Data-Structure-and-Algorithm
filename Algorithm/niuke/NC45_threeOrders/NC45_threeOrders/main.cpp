//
//  main.cpp
//  NC45_threeOrders
//
//  Created by tommywwang on 2021/7/13.
//

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// NC45 实现二叉树先序，中序和后序遍历
// https://www.nowcoder.com/practice/a9fec6c46a684ad5a3abd4e365a9d362?tpId=188&&tqId=38560&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
class Solution {
public:
    /**
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> array;
        if (root) {
            preOrder(array, root);
            result.push_back(array);
            array.clear();
            inOrder(array, root);
            result.push_back(array);
            array.clear();
            sufixOrder(array, root);
            result.push_back(array);
        }
        return result;
    }
    
    void preOrder(vector<int> &array, TreeNode *node) {
        array.push_back(node->val);
        if (node->left) {
            preOrder(array, node->left);
        }
        if (node->right) {
            preOrder(array, node->right);
        }
    }
    
    void inOrder(vector<int> &array, TreeNode *node) {
        if (node->left) {
            inOrder(array, node->left);
        }
        array.push_back(node->val);
        if (node->right) {
            inOrder(array, node->right);
        }
    }
    
    void sufixOrder(vector<int> &array, TreeNode *node) {
        if (node->left) {
            sufixOrder(array, node->left);
        }
        if (node->right) {
            sufixOrder(array, node->right);
        }
        array.push_back(node->val);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
