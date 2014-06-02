#ifndef _BPLUSTREE_HPP
#define _BPLUSTREE_HPP

#include <iostream>
#include <stack>
using namespace std;

class BPlusTree
{
private:
    static const int minimumDegree = 3;
    static const int minKeyNum = minimumDegree - 1;
    static const int maxKeyNum = 2*minimumDegree - 1;
    static const int minChildNum = minimumDegree;
    static const int maxChildNum = 2*minimumDegree;
    static const int minLeafSlot = minKeyNum;
    static const int maxLeafSlot = maxKeyNum;
    class Node
    {
    public:
        bool isLeaf;
        int keyNum;

        Node() { keyNum = 0;}

        virtual int getLower(int k) = 0;
    };

    class innerNode : public Node
    {
        friend class BPlusTree;
    private:
        Node* child[maxChildNum];
        int key[maxKeyNum];
    public:
		innerNode() {isLeaf = false;}
        virtual int getLower(int k);
        void insert(int key, Node *p);
        int split(Node* newNode, int k);
    };

    class leafNode : public Node
    {
        friend class BPlusTree;
    private:
        string value[maxLeafSlot];
        int key[maxLeafSlot];
        leafNode *left;
        leafNode *right;
    public:
        leafNode() {isLeaf = true; left = NULL; right = NULL;}
        virtual int getLower(int k);
        void insert(int key, string value);
        int split(leafNode* newNode);
    };

private:
    Node *root;
    leafNode* leftHead;

private:
    bool get(Node* node, int key, string& value);
    void insertNode(Node* node, int key, string value, Node* p, stack<Node *>* parent);

public:
    BPlusTree() {
        root = NULL;
        leftHead = NULL;
    }

    bool get(int key, string& value);
    void put(int key, string value);

};

#endif
