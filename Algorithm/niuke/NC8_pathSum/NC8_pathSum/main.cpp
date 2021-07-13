//
//  main.cpp
//  NC8_pathSum
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

// NC8 二叉树根节点到叶子节点和为指定值的路径
// https://www.nowcoder.com/practice/840dd2dc4fbd4b2199cd48f2dadf930a?tpId=188&&tqId=38567&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 递归回溯，节点为叶子节点结束，并且只有递归到叶子节点时才符合条件
class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        vector<int> array;
        dfs(result, array, sum, root);
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<int> &array, int sum, TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == node->val) {
                array.push_back(node->val);
                result.push_back(array);
                array.pop_back();
            }
            return;
        }
        array.push_back(node->val);
        if (node->left) {
            dfs(result, array, sum - node->val, node->left);
        }
        if (node->right) {
            dfs(result, array, sum - node->val, node->right);
        }
        array.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
