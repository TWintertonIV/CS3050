#ifndef _bst_h
#define _bst_h

// Symbolic Constants




// Data types

// NOTE! - You will want to fill out this data structure.  Do you want a separate
// NODE data structure as well?
typedef struct _BST
{
    Node* Head;
} BST;

typedef void (*NODEVISITFUNC)(void * parm);
typedef struct _Node{
    void* satelliteData;
    long long key;
    Node* Left;
    Node* Right;
} Node;



// Prototypes
BST * NewBST();
void TreeInsert(BST * pBST, void * satellite, long long key);
void InOrder(BST * pBST, NODEVISITFUNC func);
void PreOrder(BST * pBST, NODEVISITFUNC func);
void PostOrder(BST * pBST, NODEVISITFUNC func);
void * Search(BST * pBST, long long key);
void TreeDelete(BST * pBST, long long key);

#endif
