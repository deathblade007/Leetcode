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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr)
            return head;
        ListNode* odd = new ListNode(head->val);
        ListNode* head_odd = odd;
        ListNode* even = new ListNode(head->next->val);
        ListNode* even_head = even;
        ListNode* temp = head->next->next;
        int cnt = 3;
        while (temp != nullptr) {
            if (cnt % 2 == 1) {
                ListNode* x = new ListNode(temp->val);
                odd->next = x;
                odd = odd->next;
            } else {
                ListNode* x = new ListNode(temp->val);
                even->next = x;
                even = even->next;
            }
            cnt++;
            temp = temp->next;
        }
        odd->next = even_head;
        return head_odd;
    }
};