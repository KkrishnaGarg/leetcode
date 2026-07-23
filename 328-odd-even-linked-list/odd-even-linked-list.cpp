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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;
        ListNode* oddHead = new ListNode(-1);
        ListNode* odd = oddHead;
        ListNode* evenHead = new ListNode(-1);
        ListNode* even = evenHead;
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            if(cnt&1){
                odd->next = temp;
                odd = temp;
            }
            else{
                even->next = temp;
                even = temp;
            }
            temp = temp->next;
        }
        odd->next = evenHead->next;
        even->next = nullptr;
        ListNode* newHead = oddHead->next;
        delete evenHead;
        delete oddHead;
        return newHead;
    }
};