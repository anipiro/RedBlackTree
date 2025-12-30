#include <iostream>
#include <algorithm>
#include "Node.h"
#include "RedBlackTree.h"
using namespace std;

RedBlackTree::RedBlackTree() : root(nullptr) {}
RedBlackTree::RedBlackTree(const RedBlackTree& other) {
    root = kopisDamxmare(other.root, nullptr);
}
RedBlackTree::~RedBlackTree() { destroyTree(root);}

RedBlackTree& RedBlackTree::operator=(const RedBlackTree& other) {
    if (this != &other) {
        destroyTree(root);
        root = kopisDamxmare(other.root, nullptr);
    } return *this;
}

Node* RedBlackTree::kopisDamxmare(Node* node, Node* mshobeli) {
    if (node == nullptr) { return nullptr; }

    Node* newNode = new Node(node->mnishvneloba);
    newNode->shavia = node->shavia;
    newNode->marcxenaShvili = node->marcxenaShvili;
    newNode->mshobeli = mshobeli;
    newNode->marcxena = kopisDamxmare(node->marcxena, newNode);
    newNode->marjvena = kopisDamxmare(node->marjvena, newNode);
    return newNode;
}

void RedBlackTree::destroyTree(Node* node) {
    if (node == nullptr) { return;}
    destroyTree(node->marcxena);
    destroyTree(node->marjvena);
    delete node;
}

void RedBlackTree::marcxenaRotate(Node* x) {
    if (x == nullptr || x->marjvena == nullptr) {return;}

    Node* y = x->marjvena;
    x->marjvena = y->marcxena;

    if (y->marcxena != nullptr) {
        y->marcxena->mshobeli = x;
        y->marcxena->marcxenaShvili = false;
    } 
    
    y->mshobeli = x->mshobeli;

    if (x->mshobeli == nullptr) {
        root = y;
        y->marcxenaShvili = false;
    }
    else if (x->marcxenaShvili) {
        x->mshobeli->marcxena = y;
        y->marcxenaShvili = true;
    }
    else {
        x->mshobeli->marjvena = y;
        y->marcxenaShvili = false;
    }
    y->marcxena = x;
    x->mshobeli = y;
    x->marcxenaShvili = true;
}

void RedBlackTree::marjvenaRotate(Node* y) {
    if (y == nullptr || y->marcxena == nullptr) { return;}

    Node* x = y->marcxena;
    y-> marcxena = x->marjvena;

    if (x->marjvena != nullptr) {
        x->marjvena->mshobeli = y;
        x->marjvena->marcxenaShvili = true;
    }

    x->mshobeli = y-> mshobeli;

    if (y->mshobeli == nullptr) {
        root = x;
        x->marcxenaShvili = false;
    }
    else if (y->marcxenaShvili) {
        y->mshobeli->marcxena = x;
        x->marcxenaShvili = true;
    }
    else {
        y->mshobeli->marjvena = x;
        x->marcxenaShvili = false;
    }

    x->marjvena = y;
    y->mshobeli = x;
    y->marcxenaShvili = false;
}

void RedBlackTree::insert(int mnsh) {
    Node* newNode = new Node(mnsh);

    if (root == nullptr) {
        root = newNode;
        root->shavia = true;
        return;
    }

    Node* axlandeli = root;
    Node* mshobeli = nullptr;

    while (axlandeli != nullptr) {
        mshobeli = axlandeli;
        if (mnsh < axlandeli->mnishvneloba) {
            axlandeli = axlandeli->marcxena;
        }
        else if (mnsh > axlandeli->mnishvneloba) {
            axlandeli = axlandeli->marjvena;
        } else {
            delete newNode;
            return;
        }
    }

    newNode->mshobeli = mshobeli;

    if (mnsh < mshobeli->mnishvneloba) {
        mshobeli->marcxena = newNode;
        newNode->marcxenaShvili = true;
    }
    else {
        mshobeli->marjvena = newNode;
        newNode->marcxenaShvili = false;
    } shesworeba(newNode);
}

void RedBlackTree::insertRecursive(int mnsh) {
    if (root == nullptr) {
        root = new Node(mnsh);
        root->shavia = true;
        return;
    }

    Node* inserted = rekursiisShesatanad(root, mnsh, nullptr);

    if (inserted != nullptr) { shesworeba(inserted);}
}

Node* RedBlackTree::rekursiisShesatanad(Node* node, int mnsh, Node* mshobeli) {
    if (node == nullptr) {
        Node* newNode = new Node(mnsh);
        newNode->mshobeli = mshobeli;

        if (mshobeli != nullptr) {
            if (mnsh < mshobeli->mnishvneloba) {
                mshobeli->marcxena = newNode;
                newNode->marcxenaShvili = true;
            }
            else {
                mshobeli->marjvena = newNode;
                newNode->marcxenaShvili = false;
            }
        } return newNode;
    }

    if (mnsh == node->mnishvneloba) { return nullptr; }

    if (mnsh < node->mnishvneloba) {
        return rekursiisShesatanad(node->marcxena, mnsh, node);
    }  else {
        return rekursiisShesatanad(node->marjvena, mnsh, node);
    }
}

void RedBlackTree::shesworeba(Node* z) {
    while (z != root && z->mshobeli != nullptr && !z->mshobeli->shavia) {

        if (z->mshobeli->mshobeli == nullptr) { break; }
        
        if (z->mshobeli->marcxenaShvili) {
            Node* uncle = z->mshobeli->mshobeli->marjvena;

            if (uncle != nullptr && !uncle->shavia) {
                z->mshobeli->shavia = true;
                uncle->shavia = true;
                z->mshobeli->mshobeli->shavia = false;
                z = z->mshobeli->mshobeli;
            }
            else {
                if (!z->marcxenaShvili) {
                    z = z->mshobeli;
                    marcxenaRotate(z);
                }
                if (z->mshobeli != nullptr) {
                    z->mshobeli->shavia = true;
                    if (z->mshobeli->mshobeli != nullptr) {
                        z->mshobeli->mshobeli->shavia = false;
                        marjvenaRotate(z->mshobeli->mshobeli);
                    }
                }
            }
        }
        else {
            Node* uncle = z->mshobeli->mshobeli->marcxena;

            if (uncle != nullptr && !uncle->shavia) {
                z->mshobeli->shavia = true;
                uncle->shavia = true;
                z->mshobeli->mshobeli->shavia = false;
                z = z->mshobeli->mshobeli;
            }
            else {
                if (z->marcxenaShvili) {
                    z = z->mshobeli;
                    marjvenaRotate(z);
                }
                if (z->mshobeli != nullptr) {
                    z->mshobeli->shavia = true;
                    if (z->mshobeli->mshobeli != nullptr) {
                        z->mshobeli->mshobeli->shavia = false;
                        marcxenaRotate(z->mshobeli->mshobeli);
                    }
                }
            }
        }
    } root->shavia = true;
}

Node* RedBlackTree::minimumi(Node* node) {
    if (node == nullptr) { return nullptr; }
    while (node->marcxena != nullptr) { node = node->marcxena; }
    return node;
}

Node* RedBlackTree::maximumi(Node* node) {
    if (node == nullptr) { return nullptr; }

    while (node->marjvena != nullptr) {
        node = node->marjvena;
    } return node;
}

void RedBlackTree::gadatana(Node* u, Node* v) {
    if (u == nullptr) { return; }
    if (u->mshobeli == nullptr) { root = v; }
    else if (u->marcxenaShvili) { u->mshobeli->marcxena = v; }
    else { u->mshobeli->marjvena = v; }

    if (v != nullptr) {
        v->mshobeli = u->mshobeli;
        v->marcxenaShvili = u->marcxenaShvili;
    }
}

bool RedBlackTree::washla(int mnsh) {
    Node* z = rekursiisDzebna(root, mnsh);

    if (z == nullptr) { return false; }

    Node* y = z;
    Node* x;
    Node* xMshobeli;
    bool yOriginalColor = y->shavia;

    if (z->marcxena == nullptr) {
        x = z->marjvena;
        xMshobeli = z->mshobeli;
        gadatana(z, z->marjvena);
    }
    else if (z->marjvena == nullptr) {
        x = z->marcxena;
        xMshobeli = z->mshobeli;
        gadatana(z, z->marcxena);
    }
    else {
        y = minimumi(z->marjvena);
        yOriginalColor = y->shavia;
        x = y->marjvena;

        if (y->mshobeli == z) {
            xMshobeli = y;
        } else {
            xMshobeli = y->mshobeli;
            gadatana(y, y->marjvena);
            y->marjvena = z->marjvena;
            y->marjvena->mshobeli = y;
        }

        gadatana(z, y);
        y->marcxena = z->marcxena;
        y->marcxena->mshobeli = y;
        y->shavia = z->shavia;
    } delete z;

    if (yOriginalColor) {
        shesworebisWashla(x, xMshobeli);
    } return true;
}

void RedBlackTree::shesworebisWashla(Node* x, Node* xMshobeli) {
    while (x != root && (x == nullptr || x->shavia)) {

        if (xMshobeli != nullptr && (x == nullptr || x == xMshobeli->marcxena)) {
            Node* w = xMshobeli->marjvena;

            if (w == nullptr) {
                x = xMshobeli;
                xMshobeli = x->mshobeli;
                continue;
            }

            if (!w->shavia) {
                w->shavia = true;
                xMshobeli->shavia = false;
                marcxenaRotate(xMshobeli);
                w = xMshobeli->marjvena;
            }

            if (w == nullptr) {
                x = xMshobeli;
                xMshobeli = x->mshobeli;
                continue;
            }

            if ((w->marcxena == nullptr || w->marcxena->shavia) && (w->marjvena == nullptr || w->marjvena->shavia)) {
                w->shavia = false;
                x = xMshobeli;
                xMshobeli = x->mshobeli;
            }
            else {
                if (w->marjvena == nullptr || w->marjvena->shavia) {
                    if (w->marcxena != nullptr) { w->marcxena->shavia = true; }
                    w->shavia = false;
                    marjvenaRotate(w);
                    w = xMshobeli->marjvena;
                }

                if (w != nullptr) {
                    w->shavia = xMshobeli->shavia;
                    xMshobeli->shavia = true;
                    if (w->marjvena != nullptr) {
                        w->marjvena->shavia = true;
                    } marcxenaRotate(xMshobeli);
                } x = root;
            }
        }
        else if (xMshobeli != nullptr) {
            Node* w = xMshobeli->marcxena;

            if (w == nullptr) {
                x = xMshobeli;
                xMshobeli = x->mshobeli;
                continue;
            }

            if (!w->shavia) {
                w->shavia = true;
                xMshobeli->shavia = false;
                marjvenaRotate(xMshobeli);
                w = xMshobeli->marcxena;
            }

            if (w == nullptr) {
                x = xMshobeli;
                xMshobeli = x->mshobeli;
                continue;
            }

            if ((w->marjvena == nullptr || w->marjvena->shavia) && (w->marcxena == nullptr || w->marcxena->shavia)) {
                w->shavia = false;
                x = xMshobeli;
                xMshobeli = x->mshobeli;
            }
            else {
                if (w->marcxena == nullptr || w->marcxena->shavia) {
                    if (w->marjvena != nullptr) {  w->marjvena->shavia = true; }
                    w->shavia = false;
                    marcxenaRotate(w);
                    w = xMshobeli->marcxena;
                }

                if (w != nullptr) {
                    w->shavia = xMshobeli->shavia;
                    xMshobeli->shavia = true;
                    if (w->marcxena != nullptr) { w->marcxena->shavia = true;}
                    marjvenaRotate(xMshobeli);
                } x = root;
            }
        }  else { break;}
    } if (x != nullptr) { x->shavia = true;}
}

Node* RedBlackTree::rekursiisDzebna(Node* node, int mnsh) const {
    if (node == nullptr || node->mnishvneloba == mnsh) {
        return node;
    }

    if (mnsh < node->mnishvneloba) {
        return rekursiisDzebna(node->marcxena, mnsh);
    }  else {
        return rekursiisDzebna(node->marjvena, mnsh);
    }
}

Node* RedBlackTree::iteraciisDzebnisDamxmare(int mnsh) const {
    Node* axlandeli = root;
    while (axlandeli != nullptr) {
        if (mnsh == axlandeli->mnishvneloba) {
            return axlandeli;
        }
        else if (mnsh < axlandeli->mnishvneloba) {
            axlandeli = axlandeli->marcxena;
        } else {
            axlandeli = axlandeli->marjvena;
        }
    } return nullptr;
}

bool RedBlackTree::dzebna(int mnsh) const {
    return iteraciisDzebnisDamxmare(mnsh) != nullptr;
}

bool RedBlackTree::iteraciisDzebna(int mnsh) const {
    return iteraciisDzebnisDamxmare(mnsh) != nullptr;
}

void RedBlackTree::preorderisDamxmare(Node* node) const {
    if (node == nullptr) { return; }

    cout << node->mnishvneloba << "(" << (node->shavia ? "B" : "R") << ") ";
    preorderisDamxmare(node->marcxena);
    preorderisDamxmare(node->marjvena);
}

void RedBlackTree::inorderisDamxmare(Node* node) const {
    if (node == nullptr) { return;}
    inorderisDamxmare(node->marcxena);
    cout << node->mnishvneloba << "(" << (node->shavia ? "B" : "R") << ") ";
    inorderisDamxmare(node->marjvena);
}

void RedBlackTree::postorderisDamxmare(Node* node) const {
    if (node == nullptr) { return; }
    postorderisDamxmare(node->marcxena);
    postorderisDamxmare(node->marjvena);
    cout << node->mnishvneloba << "(" << (node->shavia ? "B" : "R") << ") ";
}

void RedBlackTree::preorder() const {
    if (isEmpty()) {
        cout << "Preorder: Xe carielia" << endl;
        return;
    } cout << "Preorder: ";
    preorderisDamxmare(root);
    cout << endl;
}

void RedBlackTree::inorder() const {
    if (isEmpty()) {
        cout << "Inorder: Xe carielia" << endl;
        return;
    }
    cout << "Inorder: ";
    inorderisDamxmare(root);
    cout << endl;
}

void RedBlackTree::postorder() const {
    if (isEmpty()) {
        cout << "Postorder: Xe carielia" << endl;
        return;
    }
    cout << "Postorder: ";
    postorderisDamxmare(root);
    cout << endl;
}

void RedBlackTree::display() const { preorder(); }

bool RedBlackTree::isEmpty() const { return root == nullptr; }

int RedBlackTree::nodebisDatvla(Node* node) const {
    if (node == nullptr) { return 0; }
    return 1 + nodebisDatvla(node->marcxena) + nodebisDatvla(node->marjvena);
}

int RedBlackTree::size() const { return nodebisDatvla(root); }

int RedBlackTree::getHeight(Node* node) const {
    if (node == nullptr) { return 0; }
    return 1 + max(getHeight(node->marcxena), getHeight(node->marjvena));
}

int RedBlackTree::height() const {
    return getHeight(root);
}

bool RedBlackTree::validaciisDamxmare(Node* node, int blackCount, int& pathBlackCount) const {
    if (node == nullptr) {
        if (pathBlackCount == -1) {
            pathBlackCount = blackCount;
        } return blackCount == pathBlackCount;
    }

    if (!node->shavia && node->mshobeli != nullptr && !node->mshobeli->shavia) { return false;}
    if (node->shavia) { blackCount++; }
    return validaciisDamxmare(node->marcxena, blackCount, pathBlackCount) && validaciisDamxmare(node->marjvena, blackCount, pathBlackCount);
}

bool RedBlackTree::validacia() const {
    if (root == nullptr) {  return true; }
    if (!root->shavia) { return false; }
int pathBlackCount = -1;
    return validaciisDamxmare(root, 0, pathBlackCount);
}

void RedBlackTree::clear() {
    destroyTree(root);
    root = nullptr;
}