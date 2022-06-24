#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    ListNode *fast = head, *slow = head;

    if (head == NULL || head->next == NULL) {
        return false;
    }

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }

    return false;
}

int main()
{
    ListNode n4(4);
    ListNode n0(0);
    ListNode n2(2);
    ListNode n3(3);

    n3.next = &n2;
    n2.next = &n0;
    n0.next = &n4;
    n4.next = &n2;

    cout << hasCycle(&n3);

    return 0;
}