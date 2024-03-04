#include"main.h"

void test(char* str) {
    printf("-----------------test--------------------\n");
    BTNode* root = BinaryTreeCreate(str, strlen(str));

    printf("节点数：%d\n", BinaryTreeSize(root));
    printf("叶子数：%d\n", BinaryTreeLeafSize(root));

    int depth = BinaryTreeDepth(root);
    printf("二叉树深度：%d\n",depth);
    
    for(int i = 0; i < depth; i++)
        printf("%d层节点数: %d\n", i, BinaryTreeLevelKSize(root, i));

    BinaryTreePrevOrder(root);
    BinaryTreeInOrder(root);
    BinaryTreePostOrder(root);
    BinaryTreeLevelOrder(root);

    if(BinaryTreeComplete(root))
        printf("是完全二叉树\n");
    else
        printf("不是完全二叉树\n");
    //printf("%c\n",BinaryTreeFind(root, 'Z')->_data);

    BinaryTreeDestory(&root);
    printf("-----------------test--------------------\n");
}

int main() {
    char* str1 = "AB#C#DE#F#GH";
    test(str1);

    char* str2 = "ABD##E##CF##G##";
    test(str2);

    return 0;
}