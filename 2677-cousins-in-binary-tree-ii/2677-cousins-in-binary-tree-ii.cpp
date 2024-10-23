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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, int> parent_sum; // <parent, sum_of_its_child>

        queue<pair<TreeNode*, TreeNode*>> q; // <node, parent>
        q.push({root, nullptr});

        TreeNode *node, *parent;
        long long total_sum = 0ll, curr_total_sum = 0ll;
        
        root->val = 0;

        while(!q.empty()){
            unordered_map<TreeNode*, int> curr_sum;

            curr_total_sum = 0ll;

            for(int curr_size = q.size(); curr_size > 0; curr_size--){
                node = q.front().first; 
                parent = q.front().second;
                q.pop();

                if(parent_sum.find(parent) != parent_sum.end()){
                    node->val = (int)(total_sum - parent_sum[parent]);
                }

                curr_sum[node] = ((node->left)?node->left->val:0) + ((node->right)?node->right->val:0);
                curr_total_sum += curr_sum[node];

                if(node->left) q.push({node->left, node});
                if(node->right) q.push({node->right, node});
            }

            parent_sum = curr_sum;
            total_sum = curr_total_sum;
        }

        return root;
        
    }
};