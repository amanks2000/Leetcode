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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverseLL(l1), *head2 = reverseLL(l2);

        int carry = 0;
        ListNode* head = NULL, *prev;
        while(head1 != NULL && head2 != NULL) {
            int val = head1->val + head2->val + carry;
            carry = val/10;
            ListNode* newNode = new ListNode(val % 10);
            if(head == NULL) {
                head = newNode;
                prev = head;
            }
            else {
                prev->next = newNode;
                prev = newNode;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        ListNode* temp = NULL;
        if(head1 != NULL) temp = head1;
        else if(head2 != NULL) temp = head2;

        while(temp != NULL) {
            int val = temp->val + carry;
            carry = val/10;
            ListNode* newNode = new ListNode(val % 10);
            prev->next = newNode;
            prev = newNode;
            temp = temp->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(1);
            prev->next = newNode;
        }
        return reverseLL(head);
    }

    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* prevTail = head->next;
        ListNode* smallAns = reverseLL(head->next);
        head->next = NULL;
        prevTail->next = head;
        return smallAns;
    }
};