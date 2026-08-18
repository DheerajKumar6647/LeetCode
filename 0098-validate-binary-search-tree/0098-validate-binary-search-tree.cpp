class Solution {
public:
    void inorder(TreeNode* root , bool &flag, TreeNode* &prev){
        if(root == NULL) return ;
        inorder(root->left , flag , prev);
        if(prev != NULL){
            if(prev->val >= root->val){
                flag = false;
                return;
            }
        }
        prev = root;
        inorder(root->right , flag , prev);

    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        TreeNode* prev = NULL;  
        inorder(root , flag , prev);
        return flag;
    }
};