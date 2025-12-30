#ifndef NODE_H
#define NODE_H
class RedBlackTree;
class Node {
    friend class RedBlackTree;
private:
    int mnishvneloba;
    bool shavia;
    bool marcxenaShvili;
    Node* mshobeli;
    Node* marcxena;
    Node* marjvena;
public:
    Node() : mnishvneloba(0), shavia(false), marcxenaShvili(false), marcxena(nullptr), marjvena(nullptr), mshobeli(nullptr) {}
    Node(int mnsh) : mnishvneloba(mnsh), shavia(false), marcxenaShvili(false), marcxena(nullptr), marjvena(nullptr), mshobeli(nullptr) {}
    int getMnishvneloba() const { return mnishvneloba; }
    bool getPeri() const { return shavia; }
};
#endif

