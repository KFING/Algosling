// ConsoleApplication11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstdio>
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
std::fstream fin("input.txt");
std::ofstream fout("output.txt");
class TNode {
public:
    TNode(int key)
        : Key(key)
    {
    }

    int Key;
    TNode* Left = nullptr;
    TNode* Right = nullptr;
};
class TTree {
public:
    TTree()
        : Root(0)
    {
    }

    ~TTree() {
        DestroyNode(Root);
    }
    void Insert(int x);
    void ALR(TNode* node);
private:
    static void DestroyNode(TNode* node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

public:
    TNode* Root;

};
void TTree::ALR(TNode* node) {
    fout << node->Key << '\n';
    if (node->Left)
        ALR(node->Left);
    if (node->Right)
        ALR(node->Right);
}
void TTree::Insert(int x) {
    TNode** cur = &Root;
    while (*cur) {
        TNode& node = **cur;
        if (x < node.Key) {
            cur = &node.Left;
        }
        else if (x > node.Key) {
            cur = &node.Right;
        }
        else {
            return;
        }
    }
    *cur = new TNode(x);
}
int main()
{
    
    TTree* tree = new TTree;
    for (int data; fin >> data;)
        tree->Insert(data);
    tree->ALR(tree->Root);
    
    /*int el;
    std::cin >> el;
    while (el != 1) {
        tree->Insert(el);
        std::cin >> el;
    }
    tree->ALR(tree->Root);*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file