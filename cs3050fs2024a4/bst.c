#ifdef DEBUG
#include <stdio.h>
#endif
#include <stdlib.h>
#include "bst.h"

// Local functions

// These are stubs.  That is, you need to implement these functions.


//Co-Written with help from ChatGPT: https://chatgpt.com/c/6721549c-35b8-800e-99c5-0099f8e82f40
//Main alterations from ChatGPT prompting is to write out helper functions in TreeDelete as non-nested functions. Everything else is either
//written originally from me before prompting, or copied directly.
BST * NewBST()
{
    BST* newBST = malloc(sizeof(BST)); 

    newBST->Head = NULL;
    return newBST;
}


void TreeInsert(BST * pBST, void * satellite, long long key)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->satelliteData = satellite;
    newNode->Left = NULL;
    newNode->Right = NULL;

    if (pBST->Head == NULL) {
        pBST->Head = newNode;
        return;
    }

    Node* current = pBST->Head;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->Left;
        } else if (key > current->key) {
            current = current->Right;
        } else {
            free(newNode);  // Key already exists; no need to insert
            return;
        }
    }

    if (key < parent->key) {
        parent->Left = newNode;
    } else {
        parent->Right = newNode;
    }
}

void InOrder(BST * pBST, NODEVISITFUNC func)
{
    if (pBST->Head != NULL) {
        BST leftSubtree = { pBST->Head->Left };
        InOrder(&leftSubtree, func);
        func(pBST->Head->satelliteData);
        BST rightSubtree = { pBST->Head->Right };
        InOrder(&rightSubtree, func);
    }
}

void PreOrder(BST * pBST, NODEVISITFUNC func)
{
    if (pBST->Head != NULL) {
        func(pBST->Head->satelliteData);
        BST leftSubtree = { pBST->Head->Left };
        PreOrder(&leftSubtree, func);
        BST rightSubtree = { pBST->Head->Right };
        PreOrder(&rightSubtree, func);
    }
}



void PostOrder(BST * pBST, NODEVISITFUNC func)
{
    if (pBST->Head != NULL) {
        BST leftSubtree = { pBST->Head->Left };
        PostOrder(&leftSubtree, func);
        BST rightSubtree = { pBST->Head->Right };
        PostOrder(&rightSubtree, func);
        func(pBST->Head->satelliteData);
    }
}


void * Search(BST * pBST, long long key)
{
    if (pBST->Head == NULL) {
        return NULL;
    }
    if (pBST->Head->key == key) {
        return pBST->Head->satelliteData;
    }
    
    if (key < pBST->Head->key) {
        BST leftSubtree = { pBST->Head->Left };
        return Search(&leftSubtree, key);
    } else {
        BST rightSubtree = { pBST->Head->Right };
        return Search(&rightSubtree, key);
    }
}

Node* FindMin(Node* node) {
        while (node->Left != NULL) {
            node = node->Left;
        }
        return node;
}

Node* DeleteNode(Node* root, long long key) {
    // Base case: the key is not found
    if (root == NULL) {
        return NULL;
    }

    // If the key to be deleted is smaller than the root's key, go to the left subtree
    if (key < root->key) {
        root->Left = DeleteNode(root->Left, key);
    }
    // If the key to be deleted is greater than the root's key, go to the right subtree
    else if (key > root->key) {
        root->Right = DeleteNode(root->Right, key);
    }
    // If the key is the same as the root's key, then this is the node to be deleted
    else {
        // Case 1: Node has no children (it's a leaf node)
        if (root->Left == NULL && root->Right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has one child (either left or right)
        else if (root->Left == NULL) {
            Node* temp = root->Right;
            free(root);
            return temp;
        } else if (root->Right == NULL) {
            Node* temp = root->Left;
            free(root);
            return temp;
        }
        // Case 3: Node has two children
        else {
            // Find the in-order successor (minimum in the right subtree)
            Node* temp = FindMin(root->Right);

            // Copy the in-order successor's content to this node
            root->key = temp->key;
            root->satelliteData = temp->satelliteData;

            // Delete the in-order successor
            root->Right = DeleteNode(root->Right, temp->key);
        }
    }
    return root;
}

void TreeDelete(BST * pBST, long long key)
{
    pBST->Head = DeleteNode(pBST->Head, key);
}

