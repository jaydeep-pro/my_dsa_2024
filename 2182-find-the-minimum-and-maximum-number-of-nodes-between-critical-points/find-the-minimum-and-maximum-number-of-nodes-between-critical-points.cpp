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
        // jaydeepjangid
        vector<int> v;
        ListNode* temp = head->next;

        int prev = head->val, curr = -1, next = -1;
        int i = 1;

        while (temp && temp->next) {
            curr = temp->val;
            next = temp->next->val;

            if (((curr < prev) && (curr < next)) ||
                ((curr > prev) && (curr > next))) {
                v.push_back(i);
            }

            i++;

            prev = curr;
            temp = temp->next;
        }

        vector<int> ans;
        if (v.size() < 2) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 1; i < v.size(); i++) {
            mini = min(mini, (v[i] - v[i - 1]));
        }

        ans.push_back(mini);
        ans.push_back(v[v.size() - 1] - v[0]);

        return ans;
    }
};