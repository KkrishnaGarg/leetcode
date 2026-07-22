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
        ListNode * evenStart = new ListNode(-1);
        ListNode * evenMover = evenStart;
        ListNode * oddStart = new ListNode(-1);
        ListNode * oddMover = oddStart;
        ListNode * temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            // odd
            if(cnt&1){
                ListNode * nOdd = new ListNode(temp->val);
                oddMover->next = nOdd;
                oddMover = nOdd;
            }
            // even
            else{
                ListNode * nEven = new ListNode(temp->val);
                evenMover->next = nEven;
                evenMover = nEven;
            }
            temp = temp->next;
        }
        oddMover->next = evenStart->next;
        return oddStart->next;
        
    }
};