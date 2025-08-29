#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

int main() {
    int K;
    cin >> K;

    Node* head = nullptr;

    for (int i = 1; i <= 4; i++) {
        addNode(head, i * K);
    }

    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next != nullptr) cout << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
