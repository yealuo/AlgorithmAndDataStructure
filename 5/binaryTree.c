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
queue* initqueue() {
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

// 广度优先遍历
void BFS(binaryTree head) {
    if (head == NULL) {
        return;
    }
    queue* Queue = initqueue();
    enQueue(Queue, head);
    while (Queue->front!=NULL) {
        head=deQueue(Queue);
        visit(head);
        if(head->lChild!=NULL){
            enQueue(Queue,head->lChild);
        }
        if(head->rChild!=NULL){
            enQueue(Queue,head->rChild);
        }
    }
}

// 实验用二叉树
binaryTreeNode* createNode(int data) {
    binaryTreeNode* newNode = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
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
}

int main() {
    // 创建一个简单的二叉树
    binaryTree myTree = createSampleTree();

    //BFS遍历
    BFS(myTree);

    // 释放树的内存
    free(myTree);

    return 0;
}