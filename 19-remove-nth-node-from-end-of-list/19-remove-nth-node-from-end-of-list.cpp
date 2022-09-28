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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            temp = temp->next;
            count++;
        }
        n = count - n;

        if(n==0)
            return head->next;
        
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while(n--) {
            if(n == 0) {
                cur->next = nxt->next;
                delete nxt;
                break;
            }
            cur = nxt;
            nxt = nxt->next;
        }
        return head;
    }
};