#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int d, Node* n=nullptr) {
        data = d;
        next = n;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        Node* n = new Node(d);
        if (!head) head = tail = n;
        else tail = tail->next = n;
    }
    int r = n/k;
    if (n>1 && r>0) {
        Node* d1 = new Node(INT_MIN, head);
        Node* prevT = d1;
        Node* curr = head;
        while (r--) {
            Node* head2 = curr;
            Node* prev = nullptr;
            Node* next2 = nullptr;
            for (int j = 0; j < k; j++) {
                next2 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next2;
            }
            prevT->next = prev;
            head2->next = curr;
            prevT = head2;
        }
        head = d1->next;
    }
    Node* mover = head;
    while (mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
    return 0;
}