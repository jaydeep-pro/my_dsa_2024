/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right= height(root->right);
        if(left>right){
            return left+1;
        }
        else{
            return right+1;
        }
    }
    void findLevelSum(TreeNode *root,int l,vector<long long>&levelSum){
        if(root==NULL){
            return;
        }
        levelSum[l]+=root->val;
        findLevelSum(root->left,l+1,levelSum);
        findLevelSum(root->right,l+1,levelSum);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // This problem can be solved using the simple height traversals
        // step-1 : find the height of the binary tree using the simple traversal technique
        int h=height(root);
        // check if total levels are less than k value
        if(h<k){
            return -1;
        }
        // define a vector to store the sum of all values at each of the level
        vector<long long>levelSum(h,0);
        findLevelSum(root,0,levelSum);
        sort(levelSum.rbegin(),levelSum.rend());
        return levelSum[k-1];
    }   
};