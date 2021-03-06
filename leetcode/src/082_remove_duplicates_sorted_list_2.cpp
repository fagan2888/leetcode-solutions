#include "082_remove_duplicates_sorted_list_2.h"

ListNode * RemoveDuplicatesSortedList2Solution::deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    if (head->val == head->next->val) {
        int value = head->val;
        ListNode *next = head->next;
        while (next != nullptr && next->val == value) {
            next = next->next;
        }

        return deleteDuplicates(next);
    }

    head->next = deleteDuplicates(head->next);
    return head;
}
