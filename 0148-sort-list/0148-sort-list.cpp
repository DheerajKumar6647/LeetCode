class Solution {
public:
    ListNode* sortList(ListNode* head) {
       vector<int>helper;
       ListNode* temp = head;
       while(temp != NULL){
        helper.push_back(temp->val);
        temp = temp->next;
       }
       sort(helper.begin() , helper.end());
       temp = head;
       int i=0;
       while(temp != NULL){
        temp->val = helper[i];
        i++;
        temp = temp->next;
       }
       return head;
    }
};