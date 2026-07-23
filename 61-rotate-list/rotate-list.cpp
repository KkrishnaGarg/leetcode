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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        int n=1;
        ListNode* temp = head;
        while(temp->next){
            n++;
            temp = temp->next;
        }
        ListNode* tail = temp;
        k = k % n;
        if(k==0) return head;
        temp = head;
        int cnt = n - k;
        ListNode* after = nullptr;
        while(temp){
            cnt--;
            if(cnt==0){
                after = temp->next;
                temp->next = nullptr;
            }
            temp = temp->next;
        }
        tail->next = head;
        return after;
    }
};