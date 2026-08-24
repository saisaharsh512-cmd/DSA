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
Node* add_front(Node* head, int x) {
    Node* newNode = new Node(x, head);
    return newNode;
}
Node* add_back(Node* head, int x) {
    if (head == nullptr) return new Node(x);
    Node* temp = head;
    while (temp->next!= nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(x);
    return head;
}
Node* delete_front(Node* head, int& value) {
    if (head == nullptr) {
        value = -1;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    value = temp->data;
    delete temp;
    return head;
}
Node* delete_back(Node* head, int& value) {
    if (head == nullptr) {
        value = -1;
        return nullptr;
    }
    if (head->next == nullptr) {
        value = head->data;
        delete head;
        return nullptr;
    }
    Node* temp = head->next;
    Node* prev = head;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    value = temp->data;
    delete temp;
    return head;
}
int check_x(Node* head, int x) {
    Node* temp = head;
    while (x--) {
        temp = temp->next;
    }
    return temp->data;
}

int main() {
    int q;
    cin >> q;
    Node* head = nullptr;
    bool rev = false;
    int len = 0;
    int rev_c = 0;
    for (int i = 0; i < q; i++) {
        char input[3];
        cin>>input;
        if (strcmp(input, "L")==0) {
            int x;
            cin >> x;
            if (rev) head = add_back(head, x);
            else head = add_front(head, x);
            len++;
        }
        else if (strcmp(input, "R")==0) {
            int x;
            cin >> x;
            if (rev) head = add_front(head, x);
            else head = add_back(head, x);
            len++;
        }
        else if (strcmp(input, "PL")==0) {
            int value;
            if (rev) head = delete_back(head, value);
            else head = delete_front(head, value);
            cout<<value<<endl;
            if (len>0) len--;
        }
        else if (strcmp(input, "PR")==0) {
            int value;
            if (rev) head = delete_front(head, value);
            else head = delete_back(head, value);
            cout<<value<<endl;
            if (len>0) len--;
        }
        else if (strcmp(input, "S")==0) {
            int x;
            cin >> x;
            if (len<x) cout<<"-1"<<endl;
            else if (rev) cout << check_x(head, len-x)<<endl;
            else cout << check_x(head, x-1)<<endl;
        }
        else if (strcmp(input, "F")==0) rev = !rev;
    }
    return 0;
}