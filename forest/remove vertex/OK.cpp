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
    void Insert(int);
    void ALR(TNode* node);
    void deleteT(TNode* &cur);
    void deletNode(int);
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
void TTree::deleteT(TNode* &cur) {
        if (cur->Left == NULL || cur->Right == NULL) { // если есть один потомок, или их вообще нет
            TNode* sav = cur;
            if (cur->Left != NULL) // перетаскиваем потомка на место вершины, а саму вершину удаляем
                cur = cur->Left;
            else
                cur = cur->Right;
            delete sav;
        }
        else { // дальше идет процедура удаления, если у вершины есть оба потомка
            TNode** p2 = &cur->Right;
            while ((*p2)->Left) p2 = &((*p2)->Left);
            cur->Key = (*p2)->Key;
            deleteT(*p2);
        }
    
}
void TTree::deletNode(int x) {
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
            deleteT(*cur);
        }
    }
    /*TNode* node1 = node;
    if (node->Right)
        node1 = node->Right;
    while (node1->Left) {
        if (node1->Left)
            node1 = node1->Left;
    }
    int num = node1->Key;
    node->Key = num;*/
    
    /*node = node1;
    if (node1->Right)
        node1 = node1->Right;
    node->Left = node1->Right;
    node->Key = node1->Key;
    */
    //node1->Left = nullptr;
    //node1->Right = nullptr;

}
void TTree::ALR(TNode* node) {
    if (node != NULL)
    fout << node->Key << '\n';
    if (node->Left != NULL)
        ALR(node->Left);
    if (node->Right != NULL)
        ALR(node->Right);
    return;

    
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
    int nodeD;
    fin >> nodeD;
    TTree* tree = new TTree;
    for (int data; fin >> data;)
        tree->Insert(data);
    tree->deletNode(nodeD);
    if(tree->Root)
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