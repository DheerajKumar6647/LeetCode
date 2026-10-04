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
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while(temp1 != NULL && temp2 != NULL){
            int sum = temp2->val + temp1->val + carry;
            ListNode* newnode = new ListNode(sum%10); 
            temp ->next = newnode;
            temp = newnode;
            carry = sum/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1 == NULL){
            while(temp2 != NULL){
                int sum = temp2->val + carry;
                ListNode* newnode = new ListNode(sum%10); 
                temp ->next = newnode;
                temp = newnode;
                carry = sum/10;
                temp2 = temp2->next;
            }
        }
        else if(temp2 == NULL){
            while(temp1 != NULL){
                int sum = temp1->val + carry;
                ListNode* newnode = new ListNode(sum%10); 
                temp ->next = newnode;
                temp = newnode;
                carry = sum/10;
                temp1 = temp1->next;
            }
        }
        if(carry){
            temp ->next = new ListNode(carry);
        }

        
        
        return ans->next;
    }
};