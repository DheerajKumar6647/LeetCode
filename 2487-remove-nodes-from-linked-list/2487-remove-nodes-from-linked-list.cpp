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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        while(head != NULL){
            st.push(head);
            head = head->next;
        }
        ListNode* tail = st.top();
        st.pop();
        while(st.size() != 0){
            ListNode* top = st.top();
            if(top->val >= tail->val){
                top->next = tail;
                tail = top;  
            }
             st.pop();
        }
        return tail;
    }
};