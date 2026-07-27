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
        Node* temp = head;
        while(temp){
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = nullptr;
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* t1 = dummy;
        Node* t2 = head;
        while(t2){
            t1->next = t2->next;
            t1 = t1->next;
            t2->next = t1->next;
            t2 = t2->next;
        }
        t1->next = nullptr;
        return dummy->next;
    }
};