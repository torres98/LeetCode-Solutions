struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    if (head -> next == nullptr)
        return head;

    // p, p -> next => p -> next, p
    ListNode *p1 = head, *p2 = head -> next;

    p1 -> next = swapPairs(p2 -> next);
    p2 -> next = p1;

    return p2;
}