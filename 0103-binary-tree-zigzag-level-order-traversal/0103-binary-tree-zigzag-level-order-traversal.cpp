
class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1+ max(levels(root->left),levels(root->right));
    }
    void nthlevel(TreeNode* root , int curr , int i , vector<int> &v){
        if(i%2 == 0){
            if(root == NULL) return ;
            if(curr == i){
                v.push_back(root->val);
            }
            nthlevel(root->right , curr+1 , i , v);
            nthlevel(root->left , curr+1 , i , v);
        }
        else{
            if(root == NULL) return ;
            if(curr == i){
                v.push_back(root->val);
            }
            nthlevel(root->left , curr+1 , i , v);
            nthlevel(root->right ,curr+ 1 , i , v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>>ans;
        for(int i=1; i<=n; i++){
            vector<int>v;
            nthlevel(root , 1 , i , v);
            ans.push_back(v);
        }
        return ans;
    }
};