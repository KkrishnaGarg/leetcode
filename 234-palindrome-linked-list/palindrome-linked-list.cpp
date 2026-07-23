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
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* firstMiddle = middle(head);
        ListNode* second = reverse(firstMiddle->next);
        while(second){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }

    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp){
            ListNode* after = temp->next;
            temp->next = prev;
            prev = temp;
            temp = after;
        }
        return prev;
    }
};