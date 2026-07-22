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

        ListNode * oddStart = head;
        
        ListNode * evenStart =  new ListNode(head->next->val);
        ListNode * evenMover = evenStart;
        
        ListNode * temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            // odd
            if(cnt&1 && cnt>1){
                ListNode * nOdd = new ListNode(temp->val);
                oddStart->next = nOdd;
                oddStart = nOdd;
                
            }
            // even
            else  if(!(cnt&1) && cnt>2){
                ListNode * nEven = new ListNode(temp->val);
                evenMover->next = nEven;
                evenMover = nEven;
            }
            temp = temp->next;
        }
        oddStart->next = evenStart;
        return head;
        
    }
};