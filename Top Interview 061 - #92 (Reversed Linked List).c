/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (head == NULL || left == right) return head;
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy -> val = 0, dummy -> next = head; //create dummy node, attach it to head deals with edge cases
    struct ListNode * pre = dummy;
    for (int i = 1; i < left; i++) {pre = pre->next;} //reach the left node
    struct ListNode * curr = pre->next; //point to the node from where you'll start reversing
    for (int i = left; i < right; i++) { //go till node where reversing stops
        struct ListNode * tmp = curr->next; //save current node for reverse
        curr->next = tmp->next; //skip temp node
        tmp->next = pre->next; //insert temp at beginning
        pre->next = tmp; //make tmp the beginning of the reversed section
    }
    head = dummy->next;
    free(dummy);
    return head;

}
