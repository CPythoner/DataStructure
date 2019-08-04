#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdbool.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef int TElemType;

typedef struct BiTreeNode {
    TElemType data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
} BiTreeNode, *BiTree;

void InitBiTree(BiTree *T);         // create a new binary tree
bool CreateBiTree(BiTree *T);
void DestoryBiTree(BiTree *T);      // destory the binary tree
void ClearBiTree(BiTree *T);        // clear the binary tree
bool BiTreeEmpty(BiTree T);          // judge if a binary tree is empty
int BiTreeDepth(BiTree T);          // get the depth of the binary tree
bool Root(BiTree T, TElemType *e);   // get the root element
int CountLeaf(BiTree T);
TElemType Value(BiTree p);
BiTree FindNode(BiTree T, TElemType e);
void Assign(BiTree p, TElemType e);
bool Parent(BiTree T, TElemType e, TElemType *parentData);
BiTree ParentNode(BiTree T, TElemType e);
BiTree LeftChild(BiTree T, TElemType e);
BiTree RightChild(BiTree T, TElemType e);
BiTree LeftSibling(BiTree T, TElemType e);
BiTree RightSibling(BiTree T, TElemType e);
BiTree LocationBiTree(BiTree T, TElemType e);
bool InsertBiTree(BiTree T, TElemType e, BiTree insertTree, int LR);
int DeleteBiTree(BiTree T, TElemType e, int LR);
void PreOrderTraverse(BiTree T, void(Visit)(TElemType));
void InOrderTraverse(BiTree T, void(Visit)(TElemType));
void PostOrderTraverse(BiTree T, void(Visit)(TElemType));
void LevelOrderTraverse(BiTree T, void(Visit)(TElemType));

#endif // BINARYTREE_H
