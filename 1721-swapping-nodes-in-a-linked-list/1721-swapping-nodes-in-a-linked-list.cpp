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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 = head, *temp2 = head, *temp;
        int cnt = 1;

        while(cnt < k) {
            temp1 = temp1->next;
            cnt++;
        }

        temp = temp1;

        while(temp1->next != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        swap(temp->val, temp2->val);
        return head;
    }
};