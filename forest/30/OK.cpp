#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
std::fstream fin("tst.in");
std::ofstream fout("tst.out");
int maxN = 0;
std::set <__int64> a;
class TNode {
public:
    TNode(int key, int keyH, int maxH)
        : Key(key), keyH(keyH), maxH(maxH)
    {
    }

    int Key;
    int maxH = 0;
    int keyH = 1;
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
    void LRAA(TNode* node);
    void ALRcount(TNode* node);
    void deleteT(TNode*& cur);  //left
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
void TTree::deleteT(TNode*& cur) {
    if (cur->Left == NULL || cur->Right == NULL) { // если есть один потомок, или их вообще нет
        TNode* sav = cur;
        if (cur->Left != NULL) // перетаскиваем потомка на место вершины, а саму вершину удаляем
            cur = cur->Left;
        else
            cur = cur->Right;
        delete sav;
    }
    else {
        TNode** p2 = &cur->Left;
        while ((*p2)->Right) p2 = &((*p2)->Right);
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

}
void TTree::ALR(TNode* node) {
    if (node != NULL)
        fout << node->Key /* ' ' << node->keyH << ' ' << node->maxH*/ << '\n';
    if (node->Left != NULL)
        ALR(node->Left);
    if (node->Right != NULL)
        ALR(node->Right);
    return;
}

void TTree::LRAA(TNode* node) {
    if (node->Left != NULL)
        LRAA(node->Left);
    if (node->Right != NULL)
        LRAA(node->Right);

    if (node->Left != NULL)
        maxN = node->Left->maxH;
    else maxN = 0;
    if (node->Right != NULL)
        maxN = (maxN >= node->Right->maxH) ? maxN : node->Right->maxH;
    if (node->Left == NULL and node->Right == NULL) {
        node->maxH = node->keyH;
        maxN = node->maxH;
    }
    node->keyH = maxN - node->keyH;
    node->maxH = maxN;
    return;
}
void TTree::ALRcount(TNode* node) {
    int maxL;
    int maxR;
    int max;
    int min;
    if (node != NULL) {
        if (node->Left != NULL)
            maxL = node->Left->keyH;
        else maxL = -1;
        if (node->Right != NULL)
            maxR = node->Right->keyH;
        else  maxR = -1; 
        if (maxL-maxR == 2 or maxL - maxR == -2) a.insert(node->Key);
    }
    if (node->Left != NULL)
        ALRcount(node->Left);
    if (node->Right != NULL)
        ALRcount(node->Right);
    return;
    //a.insert(node->Key);
}
void TTree::Insert(int x) {
    TNode** cur = &Root;
    int keyH = 1;
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
        keyH++;
    }
    *cur = new TNode(x, keyH, keyH);
}
int main()
{
    TTree* tree = new TTree;
    for (int data; fin >> data;)
        tree->Insert(data);
    //tree->deletNode(nodeD);
    if (tree->Root)
        tree->LRAA(tree->Root);
    if (tree->Root)
        tree->ALRcount(tree->Root);
    std::set <__int64> ::iterator it = a.begin();
    if (a.size() % 2 == 1) {
        std::set <__int64> ::iterator it = a.begin();
        __int64 i = 0;
        while (i < (a.size() / 2)) {
            std::cout << *it << '\n';
            it++;
            i++;
        }
        std::cout << *it << '\n';
        tree->deletNode(*it);
    }
    std::cout << '\n';
    std::set <__int64> ::iterator it1 = a.begin();
    for (int i = 0; i < a.size(); i++) {
        std::cout << *it1 << '\n';
        it1++;
    }
    if (tree->Root)
        tree->ALR(tree->Root);
}