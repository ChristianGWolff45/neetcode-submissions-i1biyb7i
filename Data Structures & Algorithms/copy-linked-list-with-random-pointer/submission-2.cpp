/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        std::unordered_map<Node*, Node*> newNodes;
        Node* newHead = new Node(head->val);
        newNodes.insert({head, newHead});
        Node* newCur = newHead;
        Node* cur = head->next;
        while(cur != nullptr){
            newCur->next = new Node(cur->val);
            newCur = newCur->next;
            newNodes.insert({cur, newCur});
            cur = cur->next;
            
        }
        newCur = newHead;
        cur = head;
        while(newCur != nullptr){
            if(cur->random != nullptr){
                newCur->random = newNodes[cur->random];
            }
            newCur = newCur->next;
            cur = cur->next;
        }

        return newHead;
    }
};
