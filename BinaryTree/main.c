#include <stdio.h>
#include "binarytree.h"

void Visit(TElemType elem);

int main()
{
    BiTree T;

    printf("Init a binary tree ...\n");
    InitBiTree(&T);

    printf("Check if the binary is empty ...\n");
    bool empty = BiTreeEmpty(T);
    printf("Check result is %s\n", empty ? "true" : "false");

    printf("Create binary tree ...\n");
    bool result = CreateBiTree(&T);
    printf("The result of CreateBiTree is %d\n", result);

    printf("Depth of the binary tree is %d\n", BiTreeDepth(T));

    printf("Check if the binary is empty ...\n");
    empty = BiTreeEmpty(T);
    printf("Check result is %s\n", empty ? "true" : "false");

    printf("Count the leaf number of the binary tree ...\n");
    int count = CountLeaf(T);
    printf("Leaf count of the binary tree is %d\n", count);

    printf("Find root of the binary tree ...\n");
    TElemType rootValue;
    result = Root(T, &rootValue);
    if (!result)
        printf("The binary tree is empty, there is no root node.\n");
    else
        printf("Root value of the binary tree is: %d.\n", rootValue);

    printf("Find the node who's value is 5 ...\n");
    TElemType elem = 5;
    BiTree node = FindNode(T, elem);
    printf("%s\n", node == NULL ? "There is no node who's value is 5"
                                : "Find it.");
    if (node != NULL)
    {
        printf("Value of node is: %d\n", Value(node));
        TElemType parentElem;
        if (Parent(T, Value(node), &parentElem))
            printf("The node's parent value is: %d\n", parentElem);

        printf("Assign a new value to the node ...\n");
        Assign(node, 36);
        printf("The new value of the node is %d.\n", Value(node));
    }

    elem = 2;
    printf("Find the left child of node who's value is %d.\n", elem);
    node = LeftChild(T, elem);
    if (node == NULL)
        printf("There is no left child.\n");
    else
        printf("The value of left child is %d.\n", node->data);

    printf("Find the right child of node who's value is %d.\n", elem);
    node = RightChild(T, elem);
    if (node == NULL)
        printf("There is no right child.\n");
    else
        printf("The value of right child is %d.\n", node->data);

    printf("Find the left sibling of node who's value is %d.\n", elem);
    node = LeftSibling(T, elem);
    if (node == NULL)
        printf("There is no left sibling.\n");
    else
        printf("The value of left sibling is %d.\n", node->data);

    printf("Find the right sibling of node who's value is %d.\n", elem);
    node = RightSibling(T, elem);
    if (node == NULL)
        printf("There is no right sibling.\n");
    else
        printf("The value of right sibling is %d.\n", node->data);

    printf("PreOrderTraverse test ...\n");
    PreOrderTraverse(T, Visit);

    printf("InOrderTraverse test ...\n");
    InOrderTraverse(T, Visit);

    printf("PostOrderTraverse test ...\n");
    PostOrderTraverse(T, Visit);

    printf("LevelOrderTraverse test ...\n");
    LevelOrderTraverse(T, Visit);
    return 0;
}

void Visit(TElemType elem)
{
    printf("%d ", elem);
}
