/**
Given a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
  1            <---
/   \
2     3         <---
\     \
 5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }

        queue<TreeNode *> Q;
        Q.push(root);
        TreeNode *node = root;

        while(!Q.empty()) {
            int levelSize = Q.size();

            for(int i = 0; i < levelSize; i++) {
                node = Q.front();
                Q.pop();

                if(node->left != NULL) {
                    Q.push(node->left);
                }
                if(node->right != NULL) {
                    Q.push(node->right);
                }

                if(i == levelSize - 1) {
                    res.push_back(node->val);
                }
            }
        }

        return res;
    }
};
