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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        int x;
        ListNode * temp1, * temp2;
        if(list1->val > list2->val){
            x = list2->val;
            temp2 = list2->next;
            temp1 = list1;  
        }
        else{
            x = list1->val;
            temp1 = list1->next;
            temp2 = list2;
        }

        ListNode* l3 = new ListNode(x);
        ListNode* mover = l3;

        while(temp1 && temp2){
            if(temp1->val >= temp2->val){
                ListNode* temp3 = new ListNode(temp2->val);
                mover->next = temp3;
                mover = temp3;
                temp2 = temp2->next;
            }
            else{
                ListNode* temp3 = new ListNode(temp1->val);
                mover->next = temp3;
                mover = temp3;
                temp1 = temp1->next;
            }
        }


        while(temp1){
            ListNode* temp3 = new ListNode(temp1->val);
            mover->next = temp3;
            mover = temp3;
            temp1 = temp1->next;
        }

        while(temp2){
            ListNode* temp3 = new ListNode(temp2->val);
            mover->next = temp3;
            mover = temp3;
            temp2 = temp2->next;
        }
        return l3;
    }
};

