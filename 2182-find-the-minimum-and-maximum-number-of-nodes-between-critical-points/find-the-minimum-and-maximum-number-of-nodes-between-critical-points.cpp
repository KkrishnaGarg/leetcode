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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        ListNode* left = head;
        ListNode* temp = head->next;

        int i = 1;
        int firstCritical = -1;
        int lastCritical = -1;
        int minDist = INT_MAX;

        while (temp && temp->next) {
            ListNode* right = temp->next;

            if((temp->val > left->val && temp->val > right->val) || (temp->val < left->val && temp->val < right->val)) {
                if(firstCritical == -1) firstCritical = i;
                else minDist = min(minDist, i - lastCritical);
                lastCritical = i;
            }

            left = temp;
            temp = right;
            i++;
        }

        if (firstCritical == -1 || firstCritical == lastCritical) {
            return ans;
        }

        ans[0] = minDist;
        ans[1] = lastCritical - firstCritical;

        return ans;
    }
};