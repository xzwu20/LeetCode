class Solution {
public:
RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return NULL;
    RandomListNode *p1, *p2;
    for (p1 = head;p1 != NULL;p1 = p1->next->next) {
        p2 = new RandomListNode(p1->label);
        p2->next = p1->next;
        p1->next = p2;
    }
    RandomListNode *newhead = head->next;
    for (p1 = head;p1 != NULL;p1 = p1->next->next) 
        if (p1->random) p1->next->random = p1->random->next;
    
    for (p1 = head;p1 != NULL; p1 = p1->next) {
        p2 = p1->next;
        p1->next = p2->next;
        if (p2->next) p2->next = p2->next->next;
    }
    return newhead;
};