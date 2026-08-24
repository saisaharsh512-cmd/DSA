#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node( int d ,Node* next1 = nullptr) {
        data = d;
        next = next1;
    }
};
Node* ConvertNumbersToCircularLinkedList(int n) {
    Node* head = new Node(1);
    Node* mover = head;
    Node* tail = head;
    for (int i = 2; i <= n; i++) {
        tail = new Node(i);
        mover->next = tail;
        mover = tail;
    }
    tail->next = head;
    return head;
}
class Query {
    public:
    int t;
    int x;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    Node* head = ConvertNumbersToCircularLinkedList(n);
    vector<Query> v(q);
    for (int i = 0; i < q; i++) {
        cin >> v[i].t;
        cin >> v[i].x;
    }
    vector<vector<int>> ans(q);
    Node* temp = head;
    Node* prev = head;
    while (prev->next != head) prev = prev->next;
    int r = 0;
    for (int j = 0; j < q; j++) {
        int time = v[j].t;
        while (r < time) {
            int rem = n-r;
            for (int i = 0; i<(k-1)%(rem); i++) {
                prev = temp;
                temp = temp->next;
            }
            Node* d = temp;
            temp = temp->next;
            prev->next = temp;
            delete d;
            r++;
        }
        int x = v[j].x;
        int rem2 = n -  time;
        Node* curr = temp;
        bool found = false;
        for (int i = 0; i < rem2; i++) {
            if (curr->data == x) {
                found = true;
                Node* p = curr;
                int count = min(5, rem2);
                for (int z = 0; z < count; z++) {
                    ans[j].push_back(p->data);
                    p = p->next;
                }
                break;
            }
            curr = curr->next;
        }
        if (!found) ans[j].push_back(-1);
    }
    for (int i = 0; i < q; i++) {
        if (ans[i][0]==-1) cout << "-1" << endl;
        else {
            for (int f : ans[i]) cout << f << " ";
            cout << endl;
        }
    }
    return 0;
}