#ifndef STACK_H
#define STACK_H

struct Node {
    char data;
    Node* next;
    Node(char d) : data(d), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* head;
public:
    LinkedListStack() : head(nullptr) {}
    
    void push(char x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    char top() {
        if (head) return head->data;
        return '\0';
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    ~LinkedListStack() {
        while (!isEmpty()) pop();
    }
};

#endif