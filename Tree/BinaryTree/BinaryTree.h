
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 从前序遍历序列"ABD##E#H##CF##G##"创建二叉树
BTNode* BinaryTreeCreate(BTDataType* PreOrderStr, int n);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树k层的节点数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 二叉树层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 完全二叉树判断
bool BinaryTreeComplete(BTNode* root);
// 二叉树深度
int BinaryTreeDepth(BTNode*root);