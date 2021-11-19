#include <iostream>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
 
    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    int length() {
        Node* current = head;
        int res = 0;
        while (current = current->next) {
            res ++;
        }
        return res;
    }

    /* Function to k-Reverse */
    void kReverse(int k)
    {
        Node *preheader = new Node(-1);
        preheader->next = head;
        Node *current = preheader, *next, *prev = preheader;

        int len = length();

        while(len>=k) {
            current = prev->next;
            next = current->next;
            for(int i=1; i<k; i++) {
                current->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = current->next;
            }
            prev = current;
            len-=k;
        }
        head = preheader->next;
    }
 
    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    ll.push(3);
    ll.push(35);
    ll.push(7);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.kReverse(2);
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}