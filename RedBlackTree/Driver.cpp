#include "RedBlackTree.h"
#include <iomanip>
#include <string>
using namespace std;
void printTestHeader(const string& testName, int testNumber) {
    cout << "Testi " << testNumber << ": " << testName << endl;
}

void printResult(bool passed) {
    if (passed) {
        cout << "Imushava" << endl;
    } else { 
        cout << "Ver imushava" << endl;
    }
}

int main() {
    int testsPassed = 0;
    int totalTests = 0;

    // Konstruqtori
    printTestHeader("Konstruqtori da carieli xe", ++totalTests);
    {
        RedBlackTree tree;
        bool passed = tree.isEmpty() && tree.size() == 0 && tree.validacia();
        cout << "Carieli xe validuria" << endl;
        tree.display();
        printResult(passed);
        if (passed) testsPassed++;
    }

    printTestHeader("Ramdenime insertacia", ++totalTests);
    {
        RedBlackTree tree;
        int values[] = { 10, 20, 30, 15, 25, 5, 1 };
        for (int i = 0; i < 7; i++) tree.insert(values[i]);
        tree.display();
        tree.inorder();
        bool passed = tree.size() == 7 && tree.validacia();
        printResult(passed);
        if (passed) testsPassed++;
    }

    // Dzebna
    printTestHeader("Dzebnis operaciebi", ++totalTests);
    {
        RedBlackTree tree;
        tree.insert(15);
        tree.insert(10);
        tree.insert(20);
        bool passed = tree.dzebna(15) && tree.iteraciisDzebna(10) && !tree.dzebna(100);
        cout << "Dzebna(15): " << (tree.dzebna(15) ? "Ipova" : "Ver ipova") << endl;
        cout << "Dzebna(100): " << (tree.dzebna(100) ? "Ipova" : "Ver ipova") << endl;
        printResult(passed);
        if (passed) testsPassed++;
    }

    // Washla
    printTestHeader("Washlis Operacia", ++totalTests);
    {
        RedBlackTree tree;
        int values[] = { 50, 30, 70, 20, 40, 60, 80 };
        for (int i = 0; i < 7; i++) tree.insert(values[i]);
        cout << "Washlamde:" << endl;
        tree.display();
        tree.washla(20);
        cout << "Washlis shemdeg 20:" <<endl;
        tree.display();
        bool passed = !tree.dzebna(20) && tree.size() == 6 && tree.validacia();
        printResult(passed);
        if (passed) testsPassed++;
    }

    // Kopi konstruqtori
    printTestHeader("Kopi konstruqtori", ++totalTests);
    {
        RedBlackTree tree1;
        tree1.insert(50);
        tree1.insert(30);
        tree1.insert(70);
        RedBlackTree tree2(tree1);
        tree2.insert(25);
        bool passed = tree1.size() == 3 && tree2.size() == 4 && !tree1.dzebna(25);
        cout << "Tavdapirveli xis zoma: " << tree1.size() << endl;
        cout << "Dakopirebuli xis zoma: " << tree2.size() << endl;
        printResult(passed);
        if (passed) testsPassed++;
    }

    // Minichebis operacia
    printTestHeader("Minichebis operacia", ++totalTests);
    {
        RedBlackTree tree1, tree2;
        tree1.insert(10);
        tree1.insert(20);
        tree2.insert(100);
        tree2 = tree1;
        bool passed = tree2.size() == 2 && tree2.dzebna(10) && !tree2.dzebna(100);
        cout << "Minichebis shemdeg, meore xis zoma: " << tree2.size() << endl;
        printResult(passed);
        if (passed) testsPassed++;
    }

    printTestHeader("Dacva", ++totalTests);
    {
        RedBlackTree tree;
        tree.insert(10);
        tree.insert(20);
        tree = tree;
        bool passed = tree.size() == 2 && tree.validacia();
        cout << "Zoma: " << tree.size() << endl;
        printResult(passed);
        if (passed) testsPassed++;
    }

    // Kompleqsuri operaciebi
    printTestHeader("Kompleqsuri operaciebi", ++totalTests);
    {
        RedBlackTree tree;
        for (int i = 1; i <= 20; i++) tree.insert(i * 5);
        for (int i = 1; i <= 5; i++) tree.washla(i * 5);
        bool passed = tree.size() == 15 && tree.validacia();
        cout << "Insertaciisa da washlis shemdeg:" << endl;
        cout << "Zoma: " << tree.size() << ", Simaghle: " << tree.height() << endl;
        printResult(passed);
        if (passed) testsPassed++;
    }

    // Shedegebi
    cout << "Shedegebi" << endl;
    cout << "Warmatebit gavlili testebi: " << testsPassed << " / " << totalTests << endl;
    cout << "Warmatebis machvenebeli: " << fixed << setprecision(1) << (100.0 * testsPassed / totalTests) << "%" << endl;

    if (testsPassed == totalTests) {
        cout << "Warmatebit gaiara operacia" << endl;
    }
}