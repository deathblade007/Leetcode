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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* mover_ans = head;
        int carry = 0;
        ListNode* l_1 = l1;
        ListNode* l_2 = l2;
        while (l_1 != nullptr && l_2 != nullptr) {
            int x = l_1->val + l_2->val + carry;
            if (x >= 10) {
                int n = x % 10;
                carry = x / 10;
                // mover_ans->val = n;
                ListNode* ne = new ListNode(n);
                mover_ans->next = ne;
                mover_ans = mover_ans->next;
            } else {
                ListNode* ne = new ListNode(x);
                mover_ans->next = ne;
                mover_ans = mover_ans->next;
                carry = 0;
            }
            l_1 = l_1->next;
            l_2 = l_2->next;
        }
        if (l_1 == nullptr && l_2 == nullptr) {
            if (carry == 0) {
                ListNode* ans = head->next;
                cout << carry;
                return ans;
            } else {
                ListNode* last = new ListNode(carry);
                mover_ans->next = last;
                cout << carry;
                return head->next;
            }
        } else if (l_1 != nullptr && l_2 == nullptr) {
            while (l_1 != nullptr) {
                int y = l_1->val + carry;
                if (y >= 10) {
                    int n = y % 10;
                    carry = y / 10;
                    ListNode* ne = new ListNode(n);
                    mover_ans->next = ne;
                    mover_ans = mover_ans->next;
                } else {
                    ListNode* ne = new ListNode(y);
                    mover_ans->next = ne;
                    mover_ans = mover_ans->next;
                    carry = 0;
                }
                l_1 = l_1->next;
            }
            if (l_1 == nullptr && l_2 == nullptr) {
                if (carry == 0) {
                    ListNode* ans = head->next;
                    cout << carry;
                    return ans;
                } else {
                    ListNode* last = new ListNode(carry);
                    mover_ans->next = last;
                    cout << carry;
                    return head->next;
                }
            }
        } else if (l_2 != nullptr && l_1 == nullptr) {
            while (l_2 != nullptr) {
                int y = l_2->val + carry;
                if (y >= 10) {
                    int n = y % 10;
                    carry = y / 10;
                    ListNode* ne = new ListNode(n);
                    mover_ans->next = ne;
                    mover_ans = mover_ans->next;
                } else {
                    ListNode* ne = new ListNode(y);
                    mover_ans->next = ne;
                    mover_ans = mover_ans->next;
                    carry = 0;
                }
                l_2 = l_2->next;
            }
            if (l_1 == nullptr && l_2 == nullptr) {
                if (carry == 0) {
                    ListNode* ans = head->next;
                    cout << carry;
                    return ans;
                } else {
                    ListNode* last = new ListNode(carry);
                    mover_ans->next = last;
                    cout << carry;
                    return head->next;
                }
            }
        }
        return nullptr;
    }
};