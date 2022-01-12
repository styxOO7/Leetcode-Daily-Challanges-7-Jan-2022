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
    
    void solve(TreeNode* root, int x){
        if(!root) return;
        
        // at root:
        int cur = root->val;
        if(x > cur){
            if(root->right) solve(root->right, x);
            else{
                root->right = new TreeNode(x);
                return;
            }
        }
        else{
            if(root->left) solve(root->left, x);
            else{
                root->left = new TreeNode(x);
                return;
            }
        }
        
        return;
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return root = new TreeNode(val);
        
        solve(root, val);
        return root;
    }
};
