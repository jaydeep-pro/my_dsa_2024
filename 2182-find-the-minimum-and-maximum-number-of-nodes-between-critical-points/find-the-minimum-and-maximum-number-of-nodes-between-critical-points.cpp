#include <vector>
#include <climits>

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> criticalPoints;
        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        int index = 1;

        while (currNode && currNode->next) {
            ListNode* nextNode = currNode->next;
            if ((currNode->val < prevNode->val && currNode->val < nextNode->val) ||
                (currNode->val > prevNode->val && currNode->val > nextNode->val)) {
                criticalPoints.push_back(index);
            }
            prevNode = currNode;
            currNode = nextNode;
            index++;
        }

        std::vector<int> result;
        if (criticalPoints.size() < 2) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int minDist = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDist = std::min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }
        int maxDist = criticalPoints.back() - criticalPoints.front();

        result.push_back(minDist);
        result.push_back(maxDist);

        return result;
    }
};
