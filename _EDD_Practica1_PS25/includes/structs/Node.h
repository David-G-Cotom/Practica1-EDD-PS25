//
// Created by Carlos Cotom on 16/02/2025.
//

#ifndef NODE_H
#define NODE_H



template <class T> class Node {

private:
    T *data;
    Node *next;

public:
    Node(T *value) {
        this->data = value;
        this->next = nullptr;
    }

    Node(T value) {
        this->data = new T(value);
        this->next = nullptr;
    }

    /*~Node() {
        delete data;
        delete next;
    }*/

    T *getData() {
        return this->data;
    }

    void setData(T *value) {
        this->data = value;
    }

    Node *getNext() {
        return this->next;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    T getValue() {
        return *this->data;
    }

    void setValue(T value) {
        this->data = new T(value);
    }

};



#endif //NODE_H
