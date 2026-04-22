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
        ListNode* reverseHead = reverse(head);
        ListNode* slow = nullptr;
        ListNode* toDelete = reverseHead;
        for(int i = 0; i < n - 1 && toDelete != nullptr; i++){
            slow = toDelete;
            toDelete = toDelete->next;
        }
        if(toDelete == reverseHead){
            reverseHead = reverseHead->next;;
            delete toDelete;
        }
        else if(toDelete->next != nullptr){
            slow->next = slow->next->next;
            delete toDelete;
        }else{
            slow->next = nullptr;
            delete toDelete;
        }

        return(reverse(reverseHead));
        
    }
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr, *cur = head, *next;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
