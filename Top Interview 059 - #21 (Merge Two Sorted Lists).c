struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {return list2;} //base case
    if (list2 == NULL) {return list1;} //only 1 list left to merge
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2); //merge current element of list1 since its smaller then merge lest of list1
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next); //skip to next element of list2
    return list2; //returning in all cases so dont need else
}
