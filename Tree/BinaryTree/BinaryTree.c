#include"main.h"

// 从前序遍历序列"ABD##E#H##CF##G##"创建二叉树
BTNode* BuyBTNode(BTDataType data) {
    BTNode* Node = malloc(sizeof(BTNode));
    assert(Node);
    Node->_data = data;
    Node->_left = NULL;
    Node->_right = NULL;
    return Node;
}

BTNode* _BinaryTreeCreate(BTDataType* PreOrderStr, int n, int* pi) {
    if (*pi >= n) {
        return NULL;
    }
    if (PreOrderStr[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    BTNode* root = BuyBTNode(PreOrderStr[(*pi)]);
    (*pi)++;
    root->_left = _BinaryTreeCreate(PreOrderStr, n, pi);
    root->_right = _BinaryTreeCreate(PreOrderStr, n, pi);
    return root;
}

BTNode* BinaryTreeCreate(BTDataType* PreOrderStr, int n) {
    int pi = 0;
    return _BinaryTreeCreate(PreOrderStr, n, &pi);
}

// 二叉树销毁
void _BinaryTreeDestory(BTNode* Node) {
    if (Node == NULL)
        return;
    _BinaryTreeDestory(Node->_left);
    _BinaryTreeDestory(Node->_right);
    free(Node);
}

void BinaryTreeDestory(BTNode** root) {
    _BinaryTreeDestory(*root);
    *root = NULL;
}

// 二叉树节点数
int BinaryTreeSize(BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子数
int BinaryTreeLeafSize(BTNode* root) {
    if (root == NULL) 
        return 0;

    if (root->_left == NULL && root->_right == NULL) {
        return 1;
    }

    return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树k层的节点数
int BinaryTreeLevelKSize(BTNode* root, int k) {
    if (root == NULL)
        return 0;
    if (k == 0)
        return 1;

    return BinaryTreeLevelKSize( root->_left, k-1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
    if (root == NULL)
        return NULL;

    if (root->_data == x)
        return root;

    BTNode* left = BinaryTreeFind(root->_left, x);
    if (left)
        return left;
    return BinaryTreeFind(root->_right, x);
}

// 二叉树前序遍历
void _BinaryTreePrevOrder(BTNode* Node) {
    if (Node == NULL) 
        return;

    printf("%c", Node->_data);
    _BinaryTreePrevOrder(Node->_left);
    _BinaryTreePrevOrder(Node->_right);
}

void BinaryTreePrevOrder(BTNode* root) {
    _BinaryTreePrevOrder(root);
    printf("\n");
}

// 二叉树中序遍历
void _BinaryTreeInOrder(BTNode* Node) {
    if (Node == NULL) 
        return;
    
    _BinaryTreeInOrder(Node->_left);
    printf("%c", Node->_data);
    _BinaryTreeInOrder(Node->_right);
}

void BinaryTreeInOrder(BTNode* root) {
    _BinaryTreeInOrder(root);
    printf("\n");
}

// 二叉树后序遍历
void _BinaryTreePostOrder(BTNode* Node) {
    if (Node == NULL) 
        return;
    
    _BinaryTreePostOrder(Node->_left);
    _BinaryTreePostOrder(Node->_right);
    printf("%c", Node->_data);
}

void BinaryTreePostOrder(BTNode* root) {
    _BinaryTreePostOrder(root);
    printf("\n");
}

// 二叉树层序遍历
void BinaryTreeLevelOrder(BTNode* root){
    Queue* Q = QueueCreate(root);
    while(!QueueEmpty(Q)){
        BTNode* Node = QueuePop(Q);
        if(Node != NULL){
            printf("%c", Node->_data);
            QueuePush(Q, Node->_left);
            QueuePush(Q, Node->_right);
        }
    }
    printf("\n");
}

// 二叉树深度
int BinaryTreeDepth(BTNode*root){
    if(root == NULL)
        return 0;
    int left = BinaryTreeDepth(root->_left);
    int right = BinaryTreeDepth(root->_right);

    return left > right ? left + 1 : right + 1;
}

// 完全二叉树判断
bool BinaryTreeComplete(BTNode* root){
    Queue* Q = QueueCreate(root);
    while(!QueueEmpty(Q)){
        BTNode* Node = QueuePop(Q);
        if(Node == NULL)
            break;
        QueuePush(Q, Node->_left);
        QueuePush(Q, Node->_right);
    }

    while(!QueueEmpty(Q)){
        BTNode* Node = QueuePop(Q);
        if(Node != NULL)
            return false;
    }

    return true;
}