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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        long double y = (cnt * 1.0) / 2;
        int x = floor(y);
        int a = 0;
        temp = head;
        while (a < x - 1) {
            a++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};