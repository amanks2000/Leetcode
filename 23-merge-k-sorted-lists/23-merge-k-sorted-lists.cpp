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
    ListNode* mergeHelper(int start, int end, vector<ListNode*>& lists) {
        if(start > end)
            return NULL;
        if(start == end)
            return lists[start];

        int mid = (start + end)/2;
        ListNode* h1 = mergeHelper(start, mid, lists);
        ListNode* h2 = mergeHelper(mid+1, end, lists);

        if(h2 != NULL && h1 == NULL) return h2;
        if(h1 != NULL && h2 == NULL) return h1;
        
        // Merging two LinkedLists
        ListNode* res = h1, *temp = NULL;
        while(h1 != NULL && h2 != NULL) {
            if(h1->val <= h2->val) {
                temp = h1;
                h1 = h1->next;
            }
            else {
                if(temp == NULL) res = h2;
                ListNode* temp2 = h1;
                h1 = h2;
                h2 = temp2;
                if(temp != NULL) temp->next = h1;
                temp = h1;
                h1 = h1->next;
            }
        }
        if(h2 != NULL && temp != NULL) temp->next = h2;
        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        // Divide and conquer approach;
        return mergeHelper(0, k-1, lists);
    }
};