//Detail implementation that you need to provide
#pragma once

using namespace std;
template <class Type>
struct nodeType 
{
    Type info;
    nodeType<Type>* link;
    nodeType<Type>* prevLink;

};

/*void unorderdLinkedList<Type>::insertFirst(const Type& newItem){
    nodeType<Tpe> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem; //store the new item in teh node
    newNode->link = this->top; //insert newNode before first
    this->top = newNode; //make first point to the actual first node 
    this->count++; 

    if (this->bottom)
}
void unorderdLinkedList<Type>::insertLast(const Type& newItem){
    nodeType<Tpe> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem; //store the new item in teh node
    newNode->link = nullptr; //insert newNode before first
    if (this-> top == nullptr){
        this-> top = newNdoe;
        this->btotom = newNOde;
        this->count++;
    } else {
        this ->bottom->linkt = newNOde;
        this->bottom = newNode;
        this->count++;
    }
    if (this->bottom)
}

Delete: implement an equal operator (copy from assignment and add it to discussion)
*/