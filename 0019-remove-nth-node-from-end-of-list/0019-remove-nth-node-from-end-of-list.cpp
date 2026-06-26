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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1)
            return nullptr;
        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        int a = cnt - n;
        int z = 1;
        temp = head;
        while (z != a) {
            if (a == 0) {
                head = head->next;
                return head;
            }
            temp = temp->next;
            z++;
        }
        temp->next = temp->next->next;
        return head;
    }
};