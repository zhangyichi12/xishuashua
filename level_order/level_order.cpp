/**
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }

        queue<TreeNode *> Q;
        Q.push(root);
        TreeNode *node = root;

        while(!Q.empty()) {
            int levelSize = Q.size();
            vector<int> level;
            for(int i = 0; i < levelSize; i++) {
                node = Q.front();
                Q.pop();
                level.push_back(node->val);
                if(node->left != NULL) {
                    Q.push(node->left);
                }
                if(node->right != NULL) {
                    Q.push(node->right);
                }
            }
            res.push_back(level);
        }

        return res;
    }
};
