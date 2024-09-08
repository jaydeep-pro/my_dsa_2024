class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Compute the total length of the linked list
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            temp = temp->next;
            length++;
        }

        // Step 2: Determine the size of each part
        int partSize = length / k; // Minimum nodes in each part
        int remainder = length % k; // Extra nodes to distribute

        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;
        ListNode* prev = nullptr;

        // Step 3: Split the list into k parts
        for (int i = 0; i < k && current; ++i) {
            result[i] = current;
            int currentPartSize = partSize + (i < remainder ? 1 : 0); // Add 1 if there's an extra node

            for (int j = 0; j < currentPartSize; ++j) {
                prev = current;
                current = current->next;
            }
            if (prev) {
                prev->next = nullptr; // End the current part
            }
        }

        return result;
    }
};
