## 2. Add Two Numbers

### Description: 
>You are given two **non-empty** linked lists representing two non-negative integers. 
 The digits are stored in **reverse order** and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.  
You may assume the two numbers do not contain any leading zero, except the number 0 itself.  
>Difficulty:    Medium

### Example:  
>**Input:** (2 -> 4 -> 3) + (5 -> 6 -> 4)  
**Output:** 7 -> 0 -> 8  
**Explanation:** 342 + 465 = 807.  

### Submission:
**version 1 :** C++ 16 ms 10.5 MB
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
```
**version 2 :** python3 84 ms 13.1 MB
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        temp = head
        temp2 = temp
        while l1 or l2:
            if not temp.next:
                temp.next = ListNode(0)
            t1, t2 = temp.val, temp.next.val
            
            if l1:
                temp.val = (t1 + l1.val) % 10
                temp.next.val = t2 + (t1 + l1.val) // 10
                t1, t2, l1 = temp.val, temp.next.val, l1.next
            if l2:
                temp.val = (t1 + l2.val) % 10
                temp.next.val = t2 + (t1 + l2.val) // 10
                t1, t2, l2 = temp.val, temp.next.val, l2.next
            temp2 = temp
            temp = temp.next
        
        if temp.val is 0:
            temp2.next = None
        return head
```        
