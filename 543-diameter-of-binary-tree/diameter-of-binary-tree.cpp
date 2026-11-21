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
    int ans = 0;
    int ht(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = ht(root->left);
        int r = ht(root->right);
        ans = max(ans, l+r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = ht(root);
        return ans;
    }
};