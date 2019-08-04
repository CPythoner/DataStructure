#include "binarytree.h"
#include <stdlib.h>
#include <stdio.h>

void InitBiTree(BiTree *T)
{
    *T = NULL;
}

bool CreateBiTree(BiTree *T)
{
    TElemType elem;
    printf("请输入树的结点: ");
    scanf("%d", &elem);

    if (elem == 0)
    {
        printf("您输入的是0，是否创建空树? 0 - 是；1 - 当前树的data域值为0: ");
        int result;
        scanf("%d", &result);
        if (result == 0)
        {
            *T = NULL;
            return true;
        }
    }

    *T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    if (!(*T))
        return false;
    (*T)->data = elem;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));

    return true;
}

void DestoryBiTree(BiTree *T)
{

}

void ClearBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild)
            ClearBiTree(&((*T)->lchild));
        if ((*T)->rchild)
            ClearBiTree(&((*T)->rchild));

        free(*T);
        *T = NULL;
    }
}

bool BiTreeEmpty(BiTree T)
{
    return T == NULL;
}

int BiTreeDepth(BiTree T)
{
    int LD = 0;
    int RD = 0;

    if (T == NULL)
        return 0;
    else
    {
        LD = BiTreeDepth(T->lchild);
        RD = BiTreeDepth(T->rchild);

        return (LD > RD ? LD : RD) + 1;
    }
}

bool Root(BiTree T, TElemType *e)
{
    if (!T)
        return false;
    else
    {
        *e = T->data;
        return true;
    }

}

TElemType Value(BiTree p)
{
    return p->data;
}

void Assign(BiTree p, TElemType e)
{
    p->data = e;
}

bool Parent(BiTree T, TElemType e, TElemType *parentData)
{
    if (T == NULL)
        return false;

    if (((T->lchild != NULL) && (T->lchild->data == e))
         || ((T->rchild != NULL) && (T->rchild->data == e)))
    {
        *parentData = T->data;
        return true;
    }
    else
    {
        if (Parent(T->lchild, e, parentData) || Parent(T->rchild, e, parentData))
            return true;
    }

    return false;
}


BiTree ParentNode(BiTree T, TElemType e)
{
    if (T == NULL)
        return false;

    if (((T->lchild != NULL) && (T->lchild->data == e))
         || ((T->rchild != NULL) && (T->rchild->data == e)))
    {
        return T;
    }

    BiTree parent;
    if ((parent = ParentNode(T->lchild, e)) != NULL)
        return parent;
    else
        return ParentNode(T->rchild, e);
}

int CountLeaf(BiTree T)
{
    int count = 0;

    if (T == NULL)
        return 0;

    if (T->lchild == NULL || T->rchild == NULL)
    {
        count++;
    }

    count += CountLeaf(T->lchild);
    count += CountLeaf(T->rchild);

    return count;
}

BiTree FindNode(BiTree T, TElemType e)
{
    if (T == NULL)
        return NULL;

    BiTree node = NULL;

    if (T->data == e)
        return T;

    if ((node = FindNode(T->lchild, e)) != NULL)
        return node;
    else if (T->rchild != NULL)
        return FindNode(T->rchild, e);
}

BiTree LeftChild(BiTree T, TElemType e)
{
    BiTree node = FindNode(T, e);

    if (node != NULL)
        return node->lchild;
    else
        return NULL;
}


BiTree RightChild(BiTree T, TElemType e)
{
    BiTree node = FindNode(T, e);

    if (node != NULL)
        return node->rchild;
    else
        return NULL;
}

BiTree LeftSibling(BiTree T, TElemType e)
{
    BiTree parent = ParentNode(T, e);
    if (parent != NULL)
    {
        if (parent->lchild->data != e)
            return parent->lchild;
        else
            return NULL;
    }
    else
        return NULL;
}


BiTree RightSibling(BiTree T, TElemType e)
{
    BiTree parent = ParentNode(T, e);
    if (parent != NULL)
    {
        if (parent->rchild->data != e)
            return parent->rchild;
        else
            return NULL;
    }
    else
        return NULL;
}

bool InsertBiTree(BiTree T, TElemType e, BiTree insertTree, int LR)
{
    BiTree node = FindNode(T, e);

    if (node != NULL)
    {
        if (LR == 0)
        {
            node->lchild = insertTree;
            return true;
        }
        else if (LR == 1)
        {
            node->rchild = insertTree;
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

BiTree LocationBiTree(BiTree T, TElemType e)
{
    return FindNode(T, e);
}

void PreOrderTraverse(BiTree T, void(Visit)(TElemType))
{
    if (T)
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
}

void InOrderTraverse(BiTree T, void Visit(TElemType))
{
    if (T)
    {
        InOrderTraverse(T->lchild, Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild, Visit);
    }
}

void PostOrderTraverse(BiTree T, void Visit(TElemType))
{
    if (T)
    {
        PostOrderTraverse(T->lchild, Visit);
        PostOrderTraverse(T->rchild, Visit);
        Visit(T->data);
    }
}

void LevelOrderTraverse(BiTree T, void Visit(TElemType))
{
    int i = 0, j = 0;
    BiTree tree[100];

    if (T)
        tree[j++] = T;

    while (i < j)
    {
        Visit(tree[i]->data);
        if (tree[i]->lchild)
            tree[j++] = tree[i]->lchild;
        if (tree[i]->rchild)
            tree[j++] = tree[i]->rchild;

        i++;
    }
}

int DeleteBiTree(BiTree T, TElemType e, int LR)
{
    BiTree p = FindNode(T, e);
    if (p != NULL)
    {
        ClearBiTree(p);
        return true;
    }
    else
        return false;
}
