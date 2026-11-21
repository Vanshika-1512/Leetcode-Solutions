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
    vector<vector<int>> res;
    int level = 0;

    void zig(TreeNode* root){
        if(root == nullptr){
            return;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            level++;
            int n = dq.size();
            vector<int> ans;
            if(level % 2 != 0){
                for(int i=0; i<n; i++){
                    TreeNode* curr = dq.front();
                    dq.pop_front();
                    ans.push_back(curr->val);
                    if(curr->left){
                        dq.push_back(curr->left);
                    }
                    if(curr->right){
                        dq.push_back(curr->right);
                    }
                }
            }
            else{
                for(int i=0; i<n; i++){
                    TreeNode* curr = dq.back();
                    dq.pop_back();
                    ans.push_back(curr->val);
                    if(curr->right){
                        dq.push_front(curr->right);
                    }
                    if(curr->left){
                        dq.push_front(curr->left);
                    }
                }
            }
            res.push_back(ans);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zig(root);
        return res;
    }
};