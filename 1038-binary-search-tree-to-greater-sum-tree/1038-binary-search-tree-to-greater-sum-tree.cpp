
class Solution {
public:
void greaterSum(TreeNode* &root , int &mx){
    if(root == NULL) return;
    greaterSum(root->right , mx);
    mx += root->val;
    root->val = mx;
    
    greaterSum(root->left , mx);
}
    TreeNode* bstToGst(TreeNode* root) {
        int mx = 0;
        greaterSum(root , mx);
        return root;
    }
};