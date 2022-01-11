// You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

// For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.


// Brute Approach:
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
//     L to R binary number -> root to leaf   
//     each path = binary -> number -> add to ans
    
    vector<vector<int>> big;    // store each path
    void dfs(TreeNode* root, vector<int> &tmp){
        if(root == NULL) return;
        
        tmp.push_back(root->val);
        dfs(root->left, tmp);
        dfs(root->right, tmp);
        
        // till the left ends.
        // here left ends, now push into big and start poping:
        if(root->left == NULL and root->right == NULL) big.push_back(tmp);
        tmp.pop_back();
        
        return;
            
    }
     
    int num(vector<int> binary){
        //1 1 0 -> 6 = 1*2^2 + 1*2^1 + 0*2^0 => a[]*2^place
        int place = 0;
        int ans = 0;
        
        int i = binary.size()-1;
        while(i >= 0){
            ans += binary[i] * pow(2, place);
            place++;
            i--;
        }
        
        return ans;
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        // vector of paths
        big.clear();        
        vector<int> tmp;
        dfs(root, tmp);
        
        // vetcor to binary sum:
        int res = 0;
        for(auto v: big){
            res += num(v);
        } 
        
        return res;

    }
};


// Optimized Approach:
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
    int sum;
    TreeNode* h;    // global root
    void solve(TreeNode* root, int x){
        if(!root) return;

        // dont include global root node
        if(root != h) x = x*2 + root->val;
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        // if at leaf then add sum:
        if(!l and !r) sum += x;
        
        // call left and right:
        solve(l, x);
        solve(r, x);
        
        return;
        
    }
 
    int sumRootToLeaf(TreeNode* root) {
        // key: 101 => a[] * 2^place -> for R to L
        // 101 =>  -> for L to R:
        // res = a[0];
        // res += res*2 + a[1];
        // 2*x + a[L to R] == 2^place * a[R to L]

        h = root;    
        sum = 0;
        solve(root, root->val);
        return sum;
    }
};




// editorial:
The main idea here is to get binary to decimal from LEFT to RIGHT. 
normally for right to left its simple:
binary = 1 0 1
idx      = 0 1 2
101 = 1*2^2 + 0*2^1 + 1*2^0

But for left to right, its like this:
binary = 1 0 1
idx      = 0 1 2

let res = binary[0] = 1
for idx = 1 to 2:
		res += res*2 + idx
		
dry run=>
res = 1
res = 1*2 + 0 = 2
res = 2*2 + 1 = 5
at final, res = 5.

CODE:

class Solution {
public:
    int sum;
    TreeNode* h;    // global root
    void solve(TreeNode* root, int x){
        if(!root) return;

        // dont include global root node
        if(root != h) x = x*2 + root->val;
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        // if at leaf then add sum:
        if(!l and !r) sum += x;
        
        // call left and right:
        solve(l, x);
        solve(r, x);
        
        return;
        
    }
 
    int sumRootToLeaf(TreeNode* root) {
        // key: 101 => a[] * 2^place -> for R to L
        // 101 =>  -> for L to R:
        // res = a[0];
        // res += res*2 + a[1];
        // 2*x + a[L to R] == 2^place * a[R to L]

        h = root;    
        sum = 0;
        solve(root, root->val);
        return sum;
    }
};


