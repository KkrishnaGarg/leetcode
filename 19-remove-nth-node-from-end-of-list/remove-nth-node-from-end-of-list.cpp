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
        n = kFromStart(head, n);
        if(head == nullptr) return head;
        else if(n==1){
            ListNode* temp = head;
            head = temp->next;
            delete temp;
            return head;
        }
        else{
            int cnt=0; 
            ListNode* temp = head;
            ListNode* prev = nullptr;
            while(temp){
                cnt++;
                if(cnt == n){
                    prev->next = temp->next;
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            return head;
        }
        return head;
    }

    int kFromStart(ListNode* head, int n){
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt+1-n;
    }
};