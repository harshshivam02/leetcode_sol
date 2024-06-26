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
 
  int diameter(TreeNode*root,int &maxd){
   
     if(root==NULL){return 0 ;}
        int left= diameter(root->left,maxd);
        int right=diameter(root->right,maxd);
        maxd=max(maxd,left+right);
   
        return max(left,right)+1;
  }

    int diameterOfBinaryTree(TreeNode* root) {
       int maxd=0; 
      diameter(root,maxd);
      return maxd;
    }
     


};