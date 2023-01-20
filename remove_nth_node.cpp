#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* recursive_removal(ListNode* current, int &n) {
    if (current == nullptr) {
        return nullptr;
    }

    ListNode* next_node = recursive_removal(current -> next, n);
    current -> next = next_node;
    n--;

    cout << "current n: " << n << endl;

    if (n == 0) {
        ListNode* res = current -> next;
        delete current;
        return res;
    }


    return current;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    return recursive_removal(head, n);
}

int main() {
    //1,2,3,4,5
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    
    ListNode *p = head;

    while (p != nullptr) {
        cout << p -> val << ", ";
        p = p -> next;
    }

    cout << endl;

    head = removeNthFromEnd(head, 2);

    p = head;

    while (p != nullptr) {
        cout << p -> val << ", ";
        p = p -> next;
    }

    cout << endl;
    return 0;
}
