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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode *slow=head, *fast=head;
        std::stack<ListNode*> back;

        while(fast != nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast=slow->next;
        slow->next = nullptr;

        while(fast != nullptr){
            back.push(fast);
            fast = fast->next;
        }
        slow = head;
        while(!back.empty()){
            fast=slow->next;
            slow->next = back.top();
            slow->next->next=fast;
            back.pop();
            slow=fast;

            
        }


    }
};
