//
// Created by palma on 5/5/2023.
//

#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"

Node *createNewNode(Konyv newData) {
    Node *newItem = (Node*) malloc(sizeof (Node));
    if(!newItem)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    newItem->left = newItem->right = NULL ;
    return newItem;
}

Node *insertLeft(Node *root, Konyv newData) {
    root->left = createNewNode(newData);
    return root->left;
}

Node *insertRight(Node *root, Konyv newData) {
    root->right= createNewNode(newData);
    return root->right;
}

void preorderTraversal(Node *root) {
    if(root == NULL) return;
    printf("%s %s %d %d; \n",
    root->info.nev,
    root->info.szerzo,
    root->info.kiev,
    root->info.kolcs);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s %s %d %d; \n",
    root->info.nev,
    root->info.szerzo,
    root->info.kiev,
    root->info.kolcs);
    inorderTraversal(root->right);
}


void postorderTraversal(Node *root) {
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%s %s %d %d; \n",
    root->info.nev,
    root->info.szerzo,
    root->info.kiev,
    root->info.kolcs);
}

void destroyBinaryTree(Node **root) {
    if ((*root) != NULL) {
        destroyBinaryTree(&(*root)->left);
        destroyBinaryTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}
