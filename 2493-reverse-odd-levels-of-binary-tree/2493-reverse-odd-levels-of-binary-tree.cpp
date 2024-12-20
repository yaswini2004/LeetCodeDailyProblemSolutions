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
    TreeNode* reverseOddLevels(TreeNode* root) {
         _helper(root->left, root->right, 1);
        return root;
    }

private:
    void _helper(TreeNode* root, TreeNode* mirror, int depth) {
        if (root == nullptr) {
            return;
        }

        if (depth % 2) {
            swap(root->val, mirror->val);
        }

        _helper(root->left, mirror->right, depth + 1);
        _helper(root->right, mirror->left, depth + 1);
        
    }
};