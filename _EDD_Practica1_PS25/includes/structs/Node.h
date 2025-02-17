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
    Node(T *value);

    T *getData();
    void setData(T *value);

    Node *getNext();
    void setNext(Node *next);

};



#endif //NODE_H
