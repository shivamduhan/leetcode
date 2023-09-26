/*
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* curr = head;
    while (curr) {
        while ((curr -> next) && (curr -> val == curr->next->val)) {
            curr -> next = curr->next->next;            
        }
        curr = curr->next;        
    }
    return head;
}
*/

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {return NULL;}
    struct ListNode* curr = head;    
    while (curr -> next) {
        if (curr->val == curr->next->val) {
            struct ListNode*tmp = curr->next;
            curr -> next = curr->next->next;
            free(tmp);
        } else {curr = curr->next;}        
    }
    return head;
}
