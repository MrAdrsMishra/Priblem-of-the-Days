class Solution {
    
    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!= NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward; 
        }
        return prev;
    }
    
public:
    ListNode* doubleIt(ListNode* head) {
       head = reverse(head);
        
        
        ListNode* temp = head;
        int carry = 0;
        ListNode* rec = NULL;
        
        while(temp!= NULL){  
            int total = carry + 2*(temp->val);
            temp->val = total % 10;
            carry = total / 10;
            rec = temp;
            temp = temp->next ;
        }
        
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            rec -> next = newNode;
            rec = newNode;
        }
        
        return reverse(head);
    }
};
