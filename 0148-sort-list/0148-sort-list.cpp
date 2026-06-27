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
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* lefthead, ListNode* righthead) {
        ListNode* newhead = new ListNode(-1);
        ListNode* pre = newhead;
        while (lefthead != nullptr && righthead != nullptr) {
            if (lefthead->val > righthead->val) {
                ListNode* x = new ListNode(righthead->val);
                pre->next = x;
                pre = pre->next;
                righthead = righthead->next;
            } else {
                ListNode* x = new ListNode(lefthead->val);
                pre->next = x;
                pre = pre->next;
                lefthead = lefthead->next;
            }
        }
        if (lefthead != nullptr)
            pre->next = lefthead;
        else
            pre->next = righthead;
        return newhead->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* middle = findmiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next = nullptr;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge(lefthead, righthead);
    }
};