// Ruben Navarro
// 02/13/2020
// Removes the Nth Node from Singly Linked List

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// displays list
void displayList(ListNode* head) {

    if (head == NULL) {
        std::cout << "head is NULL\n";
        return;
    }
    std::cout << "[";
    while (head != NULL) {
        std::cout << head->val;
        if (head->next != NULL)
            std::cout << ", ";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Number of Nth node to be removed
    int n = 2;

    // List Construction
    ListNode* head = new ListNode (1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = nullptr;

    // returns null is head is null
    if (head == NULL) {
        displayList(head);
        return 0;
    }

    // displays list is there is only a single node
    if (head->next == NULL && n == 1) {
        head = NULL;
        displayList(head);
        return 0;
    }
    else if (head->next == NULL && n != 1) {
        displayList(head);
        return 0;
    }

    // pointers for list traversals
    ListNode * first = head;
    ListNode * second = head;
    ListNode * prev = second;

    // counter variable to keep track of number of nodes
    int counter = 1;
    // flag for initial traversal
    bool flag = false;
    // traverse through list in order to remove nth node
    while (first != NULL) {
        if (flag) {
            prev = second;
            second = second->next;
        }
        if (counter == n && first->next != NULL)
            flag = true;
        else if (counter == n && first->next == NULL && counter <= 2) {
            head = first;
            displayList(head);
            return 0;
        }
        else if (counter == n && first->next == NULL && counter >= 3) {
            if (n == counter)
                head = head->next;
            displayList(head);
            return 0;
        }
        if (first->next == NULL) {
            prev->next = second->next;
        }
        first = first->next;
        ++counter;
    }
    // displays list
    displayList(head);
    return 0;
}
