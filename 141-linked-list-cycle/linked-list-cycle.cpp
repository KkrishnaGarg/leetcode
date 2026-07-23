/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return false;
        unordered_map<ListNode*, int> visited;

        ListNode* temp = head;

        while (temp) {
            if (visited[temp]) {
                return true;
            }
            visited[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};