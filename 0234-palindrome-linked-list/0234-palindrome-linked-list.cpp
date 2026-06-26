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
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        while (temp != nullptr) {
            nxt = temp->next;
            temp->next = pre;
            pre = temp;
            temp = nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* new_head = reverse(slow);
        ListNode* temp_1 = head;
        ListNode* temp_2 = new_head;
        while (temp_2 != nullptr) {
            if (temp_1->val != temp_2->val) {
                return false;
            } else {
                temp_1 = temp_1->next;
                temp_2 = temp_2->next;
            }
        }
        return true;
    }
};