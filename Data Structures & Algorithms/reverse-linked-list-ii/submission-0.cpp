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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l = head, *r = head;
        stack<int> stk;
        while(left > 1){
            l = l->next;
            r = r->next;
            left--; right--;
        }

        while(right >= 1 && r != nullptr){
            stk.push(r->val);
            r = r->next;
            right--;
        }
        while(!stk.empty()){
            l->val = stk.top(); stk.pop();
            l = l->next;
        }
        return head;
    }
};