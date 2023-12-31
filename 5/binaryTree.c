#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 树的定义
typedef struct binaryTreeNode {
    int data;
    struct binaryTreeNode* lChild;
    struct binaryTreeNode* rChild;
} binaryTreeNode, *binaryTree;

// 访问根节点
void visit(binaryTreeNode* root) {
    printf("%d ", root->data);
}

// 递归遍历二叉树
// 先序遍历
void preOrder(binaryTree root) {
    if (root == NULL) {
        return;
    }
    visit(root);
    preOrder(root->lChild);
    preOrder(root->rChild);
}

// 中序遍历
void inOrder(binaryTree root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->lChild);
    visit(root);
    inOrder(root->rChild);
}

// 后序遍历
void postOrder(binaryTree root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->lChild);
    postOrder(root->rChild);
    visit(root);
}

// 非递归遍历二叉树
//  链栈的定义
typedef struct linkedStackNode {
    binaryTreeNode* node;
    struct linkedStackNode* next;
} linkedStackNode, *linkedStack;

// 链栈初始化
linkedStack initLinkedStack() {
    linkedStack head = (linkedStack)malloc(sizeof(linkedStackNode));
    if (head == NULL) {
        return NULL;
    }
    head->next = NULL;
    return head;
}

// 入栈
int push(linkedStack head, binaryTreeNode* node) {
    linkedStackNode* temp = (linkedStackNode*)malloc(sizeof(linkedStackNode));
    if (temp == NULL) {
        return -1;
    }
    temp->node = node;
    temp->next = head->next;
    head->next = temp;
    return 0;
}

// 出栈
binaryTreeNode* pop(linkedStack head) {
    linkedStackNode* temp = head->next;
    binaryTreeNode* node = temp->node;
    head->next = temp->next;
    free(temp);
    return node;
}

// 先序遍历
void preOrderUnRecursion(binaryTree root) {
    if (root != NULL) {
        linkedStack stack = initLinkedStack();
        push(stack, root);
        while (stack->next != NULL) {
            // 当栈不为空时
            root = pop(stack);
            printf("%d ", root->data);
            if (root->rChild != NULL) {
                push(stack, root->rChild);
            }
            if (root->lChild != NULL) {
                push(stack, root->lChild);
            }
        }
        free(stack);
    }
}

// 中序遍历
void inOrderUnRecursion(binaryTree root) {
    if (root != NULL) {
        linkedStack stack = initLinkedStack();
        while (stack->next != NULL || root != NULL) {
            if (root != NULL) {
                push(stack, root);
                root = root->lChild;
            } else {
                root = pop(stack);
                printf("%d ", root->data);
                root = root->rChild;
            }
        }
        free(stack);
    }
}

// 后序遍历
void postOrderUnRecursion(binaryTree root) {
    if (root != NULL) {
        linkedStack stack1 = initLinkedStack();
        linkedStack stack2 = initLinkedStack();
        push(stack1, root);
        while (stack1->next != NULL) {
            // 当栈不为空时
            root = pop(stack1);
            push(stack2, root);
            if (root->lChild != NULL) {
                push(stack1, root->lChild);
            }
            if (root->rChild != NULL) {
                push(stack1, root->rChild);
            }
        }
        while (stack2->next != NULL) {
            printf("%d ", pop(stack2)->data);
        }
        free(stack1);
        free(stack2);
    }
}

// 广度优先遍历
// 队列节点的定义
typedef struct queueNode {
    binaryTreeNode* node;
    struct queueNode* next;
} queueNode;

// 队列的定义
typedef struct queue {
    queueNode* front;
    queueNode* rear;
} queue;

// 队列初始化
queue* initQueue() {
    queue* head = (queue*)malloc(sizeof(queue));
    if (head == NULL) {
        perror("内存分配失败！");
        exit(EXIT_FAILURE);
    }
    head->front = head->rear = NULL;
    return head;
}

// 入队列
void enQueue(queue* Queue, binaryTreeNode* node) {
    queueNode* temp = (queueNode*)malloc(sizeof(queueNode));
    if (temp == NULL) {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }
    temp->node = node;
    temp->next = NULL;
    if (Queue->rear == NULL) {
        Queue->front = Queue->rear = temp;
    } else {
        Queue->rear->next = temp;
        Queue->rear = temp;
    }
}

// 出队列
binaryTreeNode* deQueue(queue* Queue) {
    if (Queue->front == NULL) {
        printf("队列空！");
        return NULL;
    }
    binaryTreeNode* node = Queue->front->node;
    queueNode* temp = Queue->front;
    Queue->front = Queue->front->next;
    temp->next = NULL;
    free(temp);
    if (Queue->front == NULL) {
        Queue->rear = NULL;
    }
    return node;
}

// 计算队列长度
int size(queue* Queue) {
    int result = 0;
    queueNode* node = Queue->front;
    while (node != NULL) {
        result++;
        node = node->next;
    }
    return result;
}

// 广度优先遍历
void BFS(binaryTree head) {
    if (head == NULL) {
        return;
    }
    queue* Queue = initQueue();
    enQueue(Queue, head);
    while (Queue->front != NULL) {
        head = deQueue(Queue);
        visit(head);
        if (head->lChild != NULL) {
            enQueue(Queue, head->lChild);
        }
        if (head->rChild != NULL) {
            enQueue(Queue, head->rChild);
        }
    }
}

// 统计二叉树最大宽度
int maxWidth(binaryTree root) {
    if (root == NULL) {
        return 0;
    }
    queue* Queue = initQueue();
    enQueue(Queue, root);
    int maxWidth = 0;
    while (Queue->front != NULL) {
        int levelSize = size(Queue);
        maxWidth = levelSize > maxWidth ? levelSize : maxWidth;
        for (int i = 0; i < levelSize; i++) {
            binaryTreeNode* node = deQueue(Queue);
            if (node->lChild != NULL) {
                enQueue(Queue, node->lChild);
            }
            if (node->rChild != NULL) {
                enQueue(Queue, node->rChild);
            }
        }
    }
    return maxWidth;
}

// 判断一个树是否是搜索二叉树
bool isBSTUtil(binaryTree root, long long min, long long max) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= min || root->data >= max) {
        return false;
    }
    return isBSTUtil(root->lChild, min, root->data) &&
           isBSTUtil(root->rChild, root->data, max);
}

bool isBST(binaryTree root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

// 方法二
static long int preValue = LLONG_MIN;
bool isBST2(binaryTree root) {
    if (root == NULL) {
        return true;
    }
    if (!isBST2(root->lChild)) {
        return false;
    }
    if (root->data <= preValue) {
        return false;
    } else {
        preValue = root->data;
    }
    return isBST2(root->rChild);
}

// 判断一个给定树是否是完全二叉树
bool isCBT(binaryTree root) {
    if (root == NULL) {
        return true;
    }
    queue* Queue = initQueue();
    bool leaf = false;
    binaryTreeNode* left = NULL;
    binaryTreeNode* right = NULL;
    enQueue(Queue, root);
    while (Queue->front != NULL) {
        root = deQueue(Queue);
        left = root->lChild;
        right = root->rChild;
        if ((left == NULL && right != NULL) ||
            (leaf && (left != NULL || right != NULL))) {
            return false;
        }
        if (left != NULL) {
            enQueue(Queue, left);
        }
        if (right != NULL) {
            enQueue(Queue, right);
        }
        if (left == NULL || right == NULL) {
            leaf = true;
        }
    }
    return true;
}

// 判断给定树是否是平衡二叉树
// 定义返回值
typedef struct returnType {
    bool isBalanced;
    int height;
} returnType;

// 初始化函数
returnType* initReturnType(bool isBalanced, int height) {
    returnType* result = (returnType*)malloc(sizeof(returnType));
    if (result == NULL) {
        perror("内存分配错误！");
        exit(EXIT_FAILURE);
    }
    result->isBalanced = isBalanced;
    result->height = height;
    return result;
}

// 递归函数
returnType* process(binaryTree root) {
    if (root == NULL) {
        return initReturnType(true, 0);
    }
    returnType* leftData = process(root->lChild);
    returnType* rightData = process(root->rChild);
    int height = leftData->height > rightData->height ? leftData->height + 1
                                                      : rightData->height + 1;
    bool isBalanced = leftData->isBalanced && rightData->isBalanced &&
                      abs(leftData->height - rightData->height) < 2;
    free(leftData);
    free(rightData);
    return initReturnType(isBalanced, height);
}

// 调用函数
bool isBalanced(binaryTree root) {
    return process(root)->isBalanced;
}

// 判断给定树是否是满二叉树
// 定义返回值
typedef struct returnType1 {
    int height;
    int nodeNum;
} returnType1;

// 初始化函数
returnType1* initReturnType1(int height, int nodeNum) {
    returnType1* result = (returnType1*)malloc(sizeof(returnType1));
    if (result == NULL) {
        perror("内存分配错误！");
        exit(EXIT_FAILURE);
    }
    result->height = height;
    result->nodeNum = nodeNum;
    return result;
}

// 递归函数
returnType1* process1(binaryTree root) {
    if (root == NULL) {
        return initReturnType1(0, 0);
    }
    returnType1* leftData = process1(root->lChild);
    returnType1* rightData = process1(root->rChild);
    int height = leftData->height > rightData->height ? leftData->height + 1
                                                      : rightData->height + 1;
    int nodeNum = leftData->nodeNum + rightData->nodeNum + 1;
    free(leftData);
    free(rightData);
    return initReturnType1(height, nodeNum);
}

// 调用函数
bool isFBS(binaryTree root) {
    if (root == NULL) {
        return true;
    }
    returnType1* temp = process1(root);
    return temp->nodeNum == (1 << temp->height - 1);
}

// 返回树上两节点的最低公共祖先
binaryTreeNode* lowestCommonAncestor(binaryTree root,
                                     binaryTreeNode* node1,
                                     binaryTreeNode* node2) {
    if (root == NULL || root == node1 || root == node2) {
        return root;
    }
    binaryTreeNode* left = lowestCommonAncestor(root->lChild, node1, node2);
    binaryTreeNode* right = lowestCommonAncestor(root->rChild, node1, node2);
    if (left != NULL && right != NULL) {
        return root;
    }
    return left != NULL ? left : right;
}

// 返回给定节点的后继节点
//树的定义
typedef struct binaryTreeNode1{
    int data;
    struct binaryTreeNode1* lChild;
    struct binaryTreeNode1* rChild;
    struct binaryTreeNode1* parent;
} binaryTreeNode1,*binaryTree1;

// 返回给定树的最左侧节点
binaryTreeNode1* getMostLeftNode(binaryTree1 root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->lChild!=NULL) {
        root=root->lChild;
    }
    return root;
}

// 返回后继节点
binaryTreeNode1* getSuccessorNode(binaryTree1 root) {
    if (root == NULL) {
        return NULL;
    }
    if(root->rChild!=NULL){
        return getMostLeftNode(root->rChild);
    }else{
        binaryTreeNode1* parent=root->parent;
        while(parent!=NULL&&parent->lChild!=root){
            root=parent;
            parent=root->parent;
        }
        return parent;
    }
}

// 二叉树的序列化与反序列化
// 先序遍历序列化
void serialByPre(binaryTree root){
    if(root==NULL){
        printf("#_");
        return;
    }
    printf("%d_",root->data);
    serialByPre(root->lChild);
    serialByPre(root->rChild);
}

//一个纸条面向自己向外对折N次，从上向下打印痕迹方向
//递归函数
 void printProcess(int i,int N,bool down){
    if(i>N){
        return;
    }
    printProcess(i+1,N,true);
    printf("%s",down?"凹":"凸");
    printProcess(i+1,N,false);
 }

//调用函数
void printAllFolds(int N){
    printProcess(1,N,true);
}



// 实验用二叉树
binaryTreeNode* createNode(int data) {
    binaryTreeNode* newNode = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
    if (newNode == NULL) {
        perror("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    return newNode;
}

binaryTree createSampleTree() {
    binaryTree root = createNode(1);
    root->lChild = createNode(2);
    root->rChild = createNode(3);
    root->lChild->lChild = createNode(4);
    root->lChild->rChild = createNode(5);
    root->rChild->lChild = createNode(6);
    root->rChild->rChild = createNode(7);
    return root;
    return;
    // 创建一个简单的二叉树
    binaryTree myTree = createSampleTree();

    serialByPre(myTree);

    // 释放树的内存
    free(myTree);

    return 0;
}