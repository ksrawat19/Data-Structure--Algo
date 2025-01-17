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
//*solution 1

    // int maxDepth(TreeNode* root) {
    //     if(root==nullptr){
    //         return 0;
    //     }
    //     int height = 0;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     q.push(nullptr);
    //     while(!q.empty()){
    //         TreeNode* current = q.front();
    //         q.pop();
    //         if(current==nullptr){
    //             height += 1;
    //             if(!q.empty()){
    //                 q.push(nullptr);
    //             }
    //         }else{
    //             if(current->left!=nullptr){
    //                 q.push(current->left);
    //             }
    //             if(current->right!=nullptr){
    //                 q.push(current->right);
    //             }
    //         }
    //     }
    //     return height;
    // }
//*solution 2
    // int maxDepth(TreeNode* root) {
    //     if(root==nullptr){
    //         return 0;
    //     }
    //     int leftNode = maxDepth(root->left);
    //     int rightNode = maxDepth(root->right);
    //     int height = max(leftNode, rightNode) + 1;

    //     return height;
    // }
};
