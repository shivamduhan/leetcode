bool hasCycle(struct ListNode *head) {
    if (head == NULL || (head->next == NULL)) {
        return false; //cant have cycle if there's 0 or 1 node
    }
    struct ListNode *slow = head, *fast = head -> next; //define hare and tortoise
    while (slow != fast) { //if pointers are equal, they are looping. Therefore, cycle.
        if (fast == NULL || fast->next == NULL) {
            return false; //hare has gotten to the last node without meeting tortoise, no cycle
        }
        slow = slow -> next; //1 step at a time
        fast = fast -> next -> next; //2 steps at a time
    }
    return true;
}
