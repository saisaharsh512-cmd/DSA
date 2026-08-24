#include<bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};
void insertend(node*& head, int value) {
    node* newNode = new node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void pop(node*& head, int k) {
    if (head == nullptr || k <= 0)
        return;
    if (k == 1) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node* temp = head;
    for (int i = 1; i < k - 1; i++) {
        if (temp->next == nullptr)
            return;
        temp = temp->next;
    }
    node* toDelete = temp->next;
    if (toDelete == nullptr)
        return;
    temp->next = toDelete->next;
    delete toDelete;
}
void display(node* head) {
    while (head!=nullptr) {
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main() {
    int n;
    cin>>n;
    int x;cin>>x;
    node* head = new node(x);
    for (int i=1; i<n; i++) {
        cin>>x;
        insertend(head,x);
    }
    int k;
    cin>>k;
    node* temp=head;
    int i=1;
    while (n--) {
        if (temp->val >= k) {
            insertend(head,temp->val);
            temp=temp->next;
            pop(head,i);
            continue;
        }
        temp=temp->next;i++;
    }
    display(head);
}