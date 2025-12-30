#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>
#include <algorithm>
#include "Node.h"
class RedBlackTree {
private:
    Node* root;
    // Shetanistvis gankutvnili damxmare punqcia 
    void shesworeba(Node* node);
    void marcxenaRotate(Node* node);
    void marjvenaRotate(Node* node);
    Node* rekursiisShesatanad(Node* node, int mnish, Node* mshobeli);

    // Wasashlelad damxmare punqcia
    void shesworebisWashla(Node* node, Node* mshobeli);
    void gadatana(Node* u, Node* v);
    Node* minimumi(Node* node);
    Node* maximumi(Node* node);

    // Traversalistvis gankutvnili damxmare punqcia
    void preorderisDamxmare(Node* node) const;
    void inorderisDamxmare(Node* node) const;
    void postorderisDamxmare(Node* node) const;

	// Dzebnistvis damxmare punqcia
    Node* rekursiisDzebna(Node* node, int mnsh) const;
    Node* iteraciisDzebnisDamxmare(int mnsh) const;

    // Kopi operaciis damxmrae punqcia
    Node* kopisDamxmare(Node* node, Node* mshobeli);

    // Desqtruqtoris damxmare punqcia
    void destroyTree(Node* node);
    // Validaciis damxmare punqcia
    bool validaciisDamxmare(Node* node, int blackCount, int& pathBlackCount) const;
    int nodebisDatvla(Node* node) const;
    int getHeight(Node* node) const;

public:
    // Konstruqtori da destruqtori
    RedBlackTree();
    RedBlackTree(const RedBlackTree& other);
    ~RedBlackTree();

    // Gadatvirtvis operatori
    RedBlackTree& operator=(const RedBlackTree& other);

    void insert(int mnsh);
    void insertRecursive(int mnsh);

    bool washla(int mnsh);
    bool dzebna(int mnsh) const;
    bool iteraciisDzebna(int mnsh) const;

    void preorder() const;
    void inorder() const;
    void postorder() const;

    void display() const;
    bool isEmpty() const;
    int size() const;
    int height() const;
    bool validacia() const;
    void clear();
};

#endif