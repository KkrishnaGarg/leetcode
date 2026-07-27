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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> arr;
        for(int i=0; i<lists.size(); i++){
            ListNode * temp = lists[i];
            while(temp){
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode* dummy = new ListNode (-1);
        ListNode* temp = dummy;
        int n = arr.size();
        if(n==0) return nullptr;
        for(int i=0; i<n; i++){
            ListNode* n =  new ListNode(arr[i]);
            temp->next = n;
            temp = n;
        }
        return dummy->next;
    }
};