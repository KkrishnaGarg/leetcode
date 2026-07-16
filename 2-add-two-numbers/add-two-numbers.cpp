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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int adder = (l1->val + l2->val)%10;
        int carry = (l1->val + l2->val)/10;
        ListNode* l3 = new ListNode(adder);
        ListNode* mover = l3;
        ListNode* temp1 = l1->next;
        ListNode* temp2 = l2->next;
        while(temp1 && temp2){
            adder = (temp1->val + temp2->val + carry)%10;
            ListNode* temp3 = new ListNode(adder);
            mover->next = temp3;
            mover = temp3;
            carry = (temp1->val + temp2->val + carry)/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            adder = (temp1->val + carry)%10;
            ListNode* temp3 = new ListNode(adder);
            mover->next = temp3;
            mover = temp3;
            carry = (temp1->val + carry)/10;
            temp1 = temp1->next;
        }
        while(temp2){
            adder = (temp2->val + carry)%10;
            ListNode* temp3 = new ListNode(adder);
            mover->next = temp3;
            mover = temp3;
            carry = (temp2->val + carry)/10;
            temp2 = temp2->next;
        }
        if(carry){
            ListNode* temp3 = new ListNode(carry);
            mover->next = temp3;
        }
        return l3;
    }
};