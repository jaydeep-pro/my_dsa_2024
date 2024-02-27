/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;
       
            return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int lh = 0, rh = 0;
        if (root -> left)
            lh = height(root->left);
        if (root -> right)
            rh = height(root->right);

            return max(lh +rh , max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};