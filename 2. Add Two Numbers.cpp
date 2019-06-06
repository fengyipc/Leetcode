/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // version 1 16 ms	10.5 MB
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result =  new ListNode(0);
        ListNode * temp = result;
        
        temp->val += (l1->val + l2->val) % 10;
        temp->next =  new ListNode((l1->val + l2->val) / 10);
        l1 = l1->next;
        l2 = l2->next;
        int t;
        while (l1 != NULL && l2 != NULL) {
            temp = temp->next;
            t = temp->val;
            temp->val = (t + l1->val + l2->val) % 10;
            temp->next =  new ListNode((t + l1->val + l2->val) / 10);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            temp = temp->next;
            t = temp->val;
            temp->val = (t + l1->val) % 10;
            temp->next =  new ListNode((t + l1->val) / 10);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            temp = temp->next;
            t = temp->val;
            temp->val = (t + l2->val) % 10;
            temp->next =  new ListNode((t + l2->val) / 10);
            l2 = l2->next;
        }
        if (temp->next->val == 0) {
            temp->next = NULL;
        }
        return result;
    }
};
