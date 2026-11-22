# Red-black tree

A red-black tree of unique integers in C++, written for a university assignment, with a driver that checks it.

Identifiers and console messages are Georgian written in Latin letters, so the method table below gives the English meaning of each name.

## What it does

- **Insert.** `insert` walks down with a loop, `insertRecursive` does the same descent recursively. Both add the new node as red, then recolor and rotate. A value that is already in the tree is ignored.
- **Delete.** `washla` removes a value and returns whether it was found. A node with two children is replaced by its in-order successor, and a fix-up pass runs when a black node was removed.
- **Search.** `dzebna` and `iteraciisDzebna` both return `true` if the value is present. Both use the same iterative lookup.
- **Traversals.** `preorder`, `inorder` and `postorder` print every node as `value(B)` or `value(R)`. `display` is the preorder print.
- **Validation.** `validacia` checks that the root is black, that no red node has a red parent, and that every path from the root down has the same number of black nodes.
- **Copying and cleanup.** The copy constructor and `operator=` make a deep copy, self-assignment is guarded, and the destructor and `clear` free every node.

## How it works

`Node` holds the value, a `shavia` flag (true means black), pointers to the parent and both children, and a `marcxenaShvili` flag that says whether the node is its parent's left child. The rotations keep that flag up to date, so the fix-up code reads it instead of comparing pointers.

There is no sentinel leaf. A null pointer counts as a black leaf, and the delete fix-up carries the parent of the removed position alongside the node so it can work when that node is null.

| Method | Meaning | Cost |
| --- | --- | --- |
| `insert`, `insertRecursive` | insert | O(log n) |
| `washla` | delete | O(log n) |
| `dzebna`, `iteraciisDzebna` | search | O(log n) |
| `validacia` | check the red-black rules | O(n) |
| `size`, `height` | count nodes, count levels | O(n), computed by walking the tree |
| `preorder`, `inorder`, `postorder`, `clear` | print or free all nodes | O(n) |

`validacia` checks colors and black counts only. It does not check that the keys are in search-tree order.

## Example

From the delete test in `Driver.cpp`:

```cpp
RedBlackTree tree;
int values[] = { 50, 30, 70, 20, 40, 60, 80 };
for (int i = 0; i < 7; i++) tree.insert(values[i]);

tree.display();        // preorder print
tree.washla(20);       // delete 20
tree.display();

bool passed = !tree.dzebna(20) && tree.size() == 6 && tree.validacia();
```

`Driver.cpp` runs eight checks like this one: an empty tree, several inserts, search, delete, the copy constructor, assignment, self-assignment, and 20 inserts followed by 5 deletes. It prints `Imushava` (passed) or `Ver imushava` (failed) for each, then the number of checks passed.

## Build and run

The repository is a Visual Studio solution: open `RedBlackTree.slnx` and run it. With g++:

```
g++ -std=c++17 RedBlackTree/Driver.cpp RedBlackTree/RedBlackTree.cpp -o rbt
./rbt
```
