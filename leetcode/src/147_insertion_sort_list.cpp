#include "147_insertion_sort_list.h"

InsertionSortListSolution::ListNode *InsertionSortListSolution::find_min(InsertionSortListSolution::ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    int min = head->val;
    ListNode *min_prev = nullptr;

    ListNode *prev = head;
    ListNode *node = head->next;

    while (node != nullptr) {
        if (min > node->val) {
            min = node->val;
            min_prev = prev;
        }
        prev = node;
        node = node->next;
    }

    return min_prev;
}

InsertionSortListSolution::ListNode *InsertionSortListSolution::bubble(InsertionSortListSolution::ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *prev_min = find_min(head);
    if (prev_min == nullptr) {
        head->next = insertionSortList(head->next);
        return head;
    }

    ListNode *min = prev_min->next;
    prev_min->next = min->next;
    min->next = bubble(head);
    return min;

}

InsertionSortListSolution::ListNode *
InsertionSortListSolution::insertion_inplace(InsertionSortListSolution::ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *node = head;
    int tmp;

    while (node != nullptr) {
        ListNode *cur = node->next;

        while (cur != nullptr) {
            if (node->val > cur->val) {
                tmp = node->val;
                node->val = cur->val;
                cur->val = tmp;
            }

            cur = cur->next;
        }

        node = node->next;
    }

    return head;
}

InsertionSortListSolution::ListNode *
InsertionSortListSolution::insertionSortList(InsertionSortListSolution::ListNode *head) {
    return bubble(head);
}
