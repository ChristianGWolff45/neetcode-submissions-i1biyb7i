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
        ListNode* dummy = new ListNode(0, head);
        ListNode* l = dummy;
        ListNode* r = head;
        std::cout << l->val << std::endl;
        for(int i = 0; i < n; i++){
            r = r->next;
        }
        while(r != nullptr){
            r = r->next;
            l = l->next;
            std::cout << l->val << std::endl;
            
        }
        
        if(l->next == head){ 
            delete dummy;
            dummy = head;
            head = head->next;
            delete dummy;      
        } else{
            delete dummy;
            dummy = l->next;
            l->next = l->next->next;
            delete dummy;
        }
        


        return(head);
        
    }
};
