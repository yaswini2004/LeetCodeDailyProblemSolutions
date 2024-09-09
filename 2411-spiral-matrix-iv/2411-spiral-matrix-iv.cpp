/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, INT_MAX));
        
        int i = 0, j = 0;
        while (head) {
            while (head && j < n && matrix[i][j] == INT_MAX) {
                matrix[i][j] = head->val;
                head = head->next;
                j++;
            }
            j--;
            i++;
            while (head && i < m && matrix[i][j] == INT_MAX) {
                matrix[i][j] = head->val;
                head = head->next;
                i++;
            }
            i--;
            j--;
            while (head && j >= 0 && matrix[i][j] == INT_MAX) {
                matrix[i][j] = head->val;
                head = head->next;
                j--;
            }
            j++;
            i--;
            while (head && i >= 0 && matrix[i][j] == INT_MAX) {
                matrix[i][j] = head->val;
                head = head->next;
                i--;
            }
            i++;
            j++;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INT_MAX) {
                    matrix[i][j] = -1;
                }
            }
        }
        
        return matrix;
    }
};