/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* curr = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {

        int add = 0;

        if (l1 == NULL)
            add = l2->val;
        else if (l2 == NULL)
            add = l1->val;
        else
            add = l1->val + l2->val;

        if (carry) {
            add += 1;
            carry = 0;
        }

        if (add > 9) {
            add %= 10;
            carry = 1;
        }

        // Create new node
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = add;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            curr = newNode;
        } else {
            curr->next = newNode;
            curr = newNode;
        }

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = 1;
        newNode->next = NULL;
        curr->next = newNode;
    }

    return head;
}