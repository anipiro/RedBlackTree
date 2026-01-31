# Red-Black Tree (C++) 🌳

## Overview

This repository contains a **complete implementation of a Red-Black Tree** in **C++**.
A Red-Black Tree is a self-balancing binary search tree that guarantees **O(log n)** time complexity for insertion, deletion, and search operations by maintaining strict coloring and structural properties.

The project was developed as part of a university programming assignment and follows all required specifications, while also including additional validation and testing utilities. Since it was essential for me to use
Georgian language throughout the whole project, most of the words are in Georgian instead of English.

---

## Features

✅ Iterative and recursive insertion
✅ Full Red-Black Tree deletion with fix-up cases
✅ Iterative and recursive search
✅ Tree traversals (Preorder, Inorder, Postorder)
✅ Deep copy support (copy constructor & assignment operator)
✅ Proper memory management (destructor & clear)
✅ Validation of Red-Black Tree properties
✅ Comprehensive test driver

---

## Project Structure

```
├── Node.h              # Node class definition
├── RedBlackTree.h      # RedBlackTree class declaration
├── RedBlackTree.cpp    # RedBlackTree implementation
├── Driver.cpp          # Test cases
└── README.md           # Project documentation
```
## Node Structure

Each node stores:

* `value` – integer key
* `color` – red or black
* `parent` pointer
* `left` child pointer
* `right` child pointer
* metadata indicating left/right child relationship

The `RedBlackTree` class is declared as a friend to allow controlled access to node internals.

---

## Supported Operations

### Insertion

* New nodes are inserted as red
* Tree is rebalanced using recoloring and rotations
* Root is always enforced as black

### Deletion

* Handles all standard Red-Black Tree deletion cases
* Uses successor replacement for nodes with two children
* Includes full fix-up logic when removing black nodes

### Search

* Available in both iterative and recursive forms
* Follows standard binary search tree traversal rules

### Traversals

* Preorder
* Inorder
* Postorder

Traversal output includes both **node value and color**.

---

## Validation Utilities

The implementation includes a validation function that ensures:

* The root node is black
* No two red nodes appear consecutively
* All root-to-leaf paths contain the same number of black nodes

Additional helpers:

* `size()` – number of nodes
* `height()` – height of the tree
* `clear()` – deallocates all nodes

---

## Testing

All functionality is tested in `Driver.cpp`, including:

* Multiple insertions
* Searches
* Deletions
* Copy constructor behavior
* Assignment operator correctness
* Self-assignment safety
* Complex insert/delete sequences

Console output clearly demonstrates correct behavior for each operation.

---

## Technologies Used

* **Language:** C++
* **Paradigm:** Object-Oriented Programming
* **Concepts:**

  * Balanced Binary Search Trees
  * Pointers and Dynamic Memory
  * Recursion
  * Copy Semantics

---

## Notes

* The implementation strictly follows Red-Black Tree rules.
* Defensive checks and validation functions were added to ensure correctness.
* Code is written for clarity and correctness over premature optimization.

---


