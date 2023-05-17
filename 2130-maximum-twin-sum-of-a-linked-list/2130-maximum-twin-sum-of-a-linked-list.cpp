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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        vector<int> sums;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            sums.push_back(slow->val);
            slow = slow->next;
        }

        int n = sums.size(), pos = 1;
        
        while(slow != NULL) {
            sums[n - pos] += slow->val;
            slow = slow->next;
            pos++;
        }

        return *max_element(sums.begin(), sums.end());
        // alternate approach reverse the list, take 2 pointers, one is on original list
        // other is on the reverse list, iterate till middle and calculate the 
        // sum of nodes on the pointers, compare with max result
    }
};