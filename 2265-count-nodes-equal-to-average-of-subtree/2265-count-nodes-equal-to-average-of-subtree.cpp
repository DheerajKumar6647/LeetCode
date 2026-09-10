
class Solution {
public:
    int sum(TreeNode* root){
        if(root == NULL)
            return 0;
        return root->val + sum(root->left) + sum(root->right);    
    }
    int count(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + count(root->left) + count(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        int totalSum = sum(root);
        int totalCount = count(root);

        if(totalSum/totalCount == root->val) ans = 1;
        ans += averageOfSubtree(root->left);
        ans += averageOfSubtree(root->right);
        return ans;
    }
};