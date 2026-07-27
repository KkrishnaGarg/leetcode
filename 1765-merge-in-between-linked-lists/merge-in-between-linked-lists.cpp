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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        int cnt1 = 0;
        ListNode* secondStartAfterThis = list1, * firstStartfromThis = nullptr;
        while(temp1){
            if(cnt1 == a-1) secondStartAfterThis = temp1;
            if(cnt1 == b+1){
                firstStartfromThis = temp1;
                break;
            }
            if(cnt1 >= a && cnt1<=b){
                ListNode* n = temp1;
                temp1 = temp1->next;
                delete n;
                cnt1++;
                continue;
            }
            temp1 = temp1->next;
            cnt1++;
        }
        secondStartAfterThis->next = list2;
        ListNode* tail2 = list2;
        while(tail2->next){
            tail2 = tail2->next;
        }
        tail2->next = firstStartfromThis;

        return list1;
    }
};