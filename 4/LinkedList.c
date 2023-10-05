#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 单向链表
typedef struct node1 {
    int data;
    struct node1* next;
} node1, *linkedList1;

void initList1(linkedList1* head) {
    *head = (linkedList1)malloc(sizeof(node1));
    (*head)->next = NULL;
    return;
}

// 头插法建单向链表
void creatFromHead1(linkedList1 head) {
    node1* s;
    int i;
    scanf("%d", &i);
    while (i != -1) {
        s = (node1*)malloc(sizeof(node1));
        s->data = i;
        s->next = head->next;
        head->next = s;
        scanf("%d", &i);
    }
    return;
}

// 尾插法建单向链表
void creatFromTail1(linkedList1 head) {
    node1 *s, *t;
    t = head;
    int i;
    scanf("%d", &i);
    while (i != -1) {
        s = (node1*)malloc(sizeof(node1));
        s->data = i;
        t->next = s;
        s->next = NULL;
        t = s;
        scanf("%d", &i);
    }
    return;
}

// 遍历输出单向链表
void printList1(linkedList1 head) {
    node1* node = head->next;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    return;
}

// 释放单链表内存
void freeList1(linkedList1 head) {
    node1* current = head;
    while (current != NULL) {
        node1* temp = current;
        current = current->next;
        free(temp);
    }
}

// 反转单向链表
node1* reverseLinkedList1(node1* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node1 *prev, *current, *next;
    prev = NULL;
    current = head->next;
    next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
    return head;
}

// 双向链表
typedef struct node2 {
    int data;
    struct node2* prev;
    struct node2* next;
} node2, *linkedList2;

void initList2(linkedList2* head) {
    *head = (linkedList2)malloc(sizeof(node2));
    (*head)->prev = NULL;
    (*head)->next = NULL;
    return;
}

// 头插法建双向链表
void creatFromHead2(linkedList2 head) {
    node2* s;
    int i;
    scanf("%d", &i);
    while (i != -1) {
        s = (node2*)malloc(sizeof(node2));
        s->data = i;
        s->next = head->next;
        if (s->next != NULL) {
            s->next->prev = s;
        }
        head->next = s;
        s->prev = head;
        scanf("%d", &i);
    }
    return;
}

// 尾插法建双向链表
void creatFromTail2(linkedList2 head) {
    node2 *s, *t;
    t = head;
    int i;
    scanf("%d", &i);
    while (i != -1) {
        s = (node2*)malloc(sizeof(node2));
        s->data = i;
        t->next = s;
        s->prev = t;
        s->next = NULL;
        t = s;
        scanf("%d", &i);
    }
    return;
}

// 遍历输出双向链表
void printList2(linkedList2 head) {
    node2* node = head->next;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    return;
}

// 释放双链表内存
void freeList1(linkedList2 head) {
    node2* current = head;
    while (current != NULL) {
        node2* temp = current;
        current = current->next;
        free(temp);
    }
}

// 反转双向链表
node2* reverseLinkedList2(node2* head) {
    node2 *current = head->next, *prev, *temp;
    head->next->prev = NULL;
    while (current != NULL) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        prev = current;
        current = temp;
    }
    head->next = prev;
    prev->prev = head;
    return head;
}

// 打印两个有序单向链表的公共部分
void printPublicPart(linkedList1 head1, linkedList1 head2) {
    node1 *p1, *p2;
    p1 = head1->next;
    p2 = head2->next;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            printf("%d ", p1->data);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->data > p2->data) {
            p2 = p2->next;
        } else {
            p1 = p1->next;
        }
    }
    return;
}

// 快慢指针找到链表中点

// 奇数个节点时慢指针指向中点
// 偶数个节点时慢指针指向前一个中点
node1* findMidpoint1(linkedList1 head) {
    if (head == NULL || head->next == NULL) {
        // 处理空链表或只有一个节点的情况
        return NULL;
    }
    int count = 1;
    node1 *ptrSlow, *ptrFast;
    ptrSlow = ptrFast = head->next;
    while (ptrFast != NULL && ptrFast->next != NULL) {
        ptrFast = ptrFast->next->next;
        if (ptrFast == NULL) {
            break;
        }
        ptrSlow = ptrSlow->next;
        count++;
    }
    printf("中点数据为：%d\n中点节点序号为：%d\n", ptrSlow->data, count);
    return ptrSlow;
}

// 奇数个节点时慢指针指向中点
// 偶数个节点时慢指针指向后一个中点
node1* findMidpoint2(linkedList1 head) {
    if (head == NULL || head->next == NULL) {
        // 处理空链表或只有一个节点的情况
        return NULL;
    }
    int count = 1;
    node1 *ptrSlow, *ptrFast;
    ptrSlow = ptrFast = head->next;
    while (ptrFast != NULL && ptrFast->next != NULL) {
        ptrSlow = ptrSlow->next;
        ptrFast = ptrFast->next->next;
        count++;
    }
    printf("中点数据为：%d\n中点节点序号为：%d\n", ptrSlow->data, count);
    return ptrSlow;
}

// 奇数个节点时慢指针指向中点前一个节点
// 偶数个节点时慢指针指向前一个中点前一个节点
node1* findMidpoint3(linkedList1 head) {
    if (head == NULL || head->next->next->next == NULL) {
        // 处理空链表或只有一个节点的情况
        return NULL;
    }
    int count = 1;
    node1 *ptrSlow, *ptrFast, *ptrPrv;
    ptrSlow = ptrFast = head->next;
    ptrPrv = head;
    while (ptrFast != NULL && ptrFast->next != NULL) {
        ptrFast = ptrFast->next->next;
        if (ptrFast == NULL) {
            break;
        }
        ptrSlow = ptrSlow->next;
        ptrPrv = ptrPrv->next;
        count++;
    }
    printf("中点前一个节点数据为：%d\n中点节点序号为：%d\n", ptrPrv->data,
           count - 1);
    return ptrPrv;
}

// 奇数个节点时慢指针指向中点后一个节点
// 偶数个节点时慢指针指向后一个中点后一个节点
node1* findMidpoint4(linkedList1 head) {
    if (head == NULL || head->next->next->next == NULL) {
        // 处理空链表或只有一个节点的情况
        return NULL;
    }
    int count = 1;
    node1 *ptrSlow, *ptrFast;
    ptrSlow = ptrFast = head->next;
    while (ptrFast != NULL && ptrFast->next != NULL) {
        ptrSlow = ptrSlow->next;
        ptrFast = ptrFast->next->next;
        count++;
    }
    printf("中点后一个节点数据为：%d\n中点节点序号为：%d\n",
           ptrSlow->next->data, count + 1);
    return ptrSlow->next;
}

// 判断该链表是否为回文结构（空间复杂度O(1)）
bool isPalindrome(linkedList1 head) {
    if (head->next->next == NULL) {
        return true;
    }
    node1 *midPtr1, *midPtr2;
    linkedList1 head1;
    initList1(&head1);
    midPtr1 = findMidpoint1(head);
    midPtr2 = findMidpoint2(head);
    if (midPtr1 == midPtr2) {
        head1->next = midPtr1->next;
        midPtr1->next = NULL;
        node1* tail = head1->next;
        reverseLinkedList1(head1);
        tail->next = midPtr1;
    } else {
        midPtr1->next = NULL;
        head1->next = midPtr2;
        reverseLinkedList1(head1);
    }
    node1 *leftPtr, *rightPtr;
    leftPtr = head->next;
    rightPtr = head1->next;
    while (leftPtr != NULL && rightPtr != NULL) {
        if (leftPtr->data != rightPtr->data) {
            free(head1);
            return false;
        }
        leftPtr = leftPtr->next;
        rightPtr = rightPtr->next;
    }
    free(head1);
    return true;
}

// 划分链表为荷兰国旗式
linkedList1 listPartition(linkedList1 head, int num) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node1* sH = NULL;
    node1* sT = NULL;
    node1* eH = NULL;
    node1* eT = NULL;
    node1* bH = NULL;
    node1* bT = NULL;
    node1* current = head->next;
    node1* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = NULL;
        if (current->data < num) {
            if (sH == NULL) {
                sH = current;
                sT = current;
            } else {
                sT->next = current;
                sT = current;
            }
        } else if (current->data == num) {
            if (eH == NULL) {
                eH = current;
                eT = current;
            } else {
                eT->next = current;
                eT = current;
            }
        } else {
            if (bH == NULL) {
                bH = current;
                bT = current;
            } else {
                bT->next = current;
                bT = current;
            }
        }
        current = next;
    }
    if (sH != NULL) {
        head->next = sH;
        if (eH != NULL) {
            sT->next = eH;
            eT->next = bH;
        } else {
            sT->next = bH;
        }
    } else if (eH != NULL) {
        head->next = eH;
        eT->next = bH;
    } else {
        head->next = bH;
    }
    return head;
}

// 复制复杂链表（链表头含数据）
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* rand;
} Node;

Node* copyListWithRand(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        // 复制每一个节点到原节点后
        next = current->next;
        Node* node = (Node*)malloc(sizeof(Node));
        node->value = current->value;
        current->next = node;
        node->next = next;
        current = next;
    }
    current = head;
    Node* copy = NULL;
    while (current != NULL) {
        // 复制节点的随机节点为原节点随机节点的后一个节点（随机节点为NULL时特殊处理）
        next = current->next->next;
        copy = current->next;
        copy->rand = current->rand == NULL ? NULL : current->rand->next;
        current = next;
    }
    current = head;
    Node* res = head->next;
    while (current != NULL) {
        next = current->next->next;
        copy = current->next;
        current->next = next;
        copy->next = next == NULL ? NULL : next->next;
        current = next;
    }
    return res;
}

// 找到两个链表的相交点，空间复杂度为O(1)

// 找到链表第一个入环节点，如果无环，返回NULL
node1* getLoopNode(linkedList1 head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return NULL;
    }
    node1* slow = head->next;
    node1* fast = head->next->next;
    while (slow != fast) {
        if (fast->next == NULL || fast->next->next == NULL) {
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 两链表均无环
node1* noLoop(linkedList1 head1, linkedList1 head2) {
    if (head1 == NULL || head1->next == NULL || head2 == NULL ||
        head2->next == NULL) {
        return NULL;
    }
    node1* current1 = head1->next;
    node1* current2 = head2->next;
    int length1 = 1;
    int length2 = 1;
    while (current1->next != NULL) {
        length1++;
        current1 = current1->next;
    }
    while (current2->next != NULL) {
        length2++;
        current2 = current2->next;
    }
    if (current1 != current2) {
        return NULL;
    }
    int lengthDelta;
    if (length1 >= length2) {
        lengthDelta = length1 - length2;
        current1 = head1;
        current2 = head2;
    } else {
        lengthDelta = length2 - length1;
        current1 = head2;
        current2 = head1;
    }
    for (int i = 0; i < lengthDelta; i++) {
        current1 = current1->next;
    }
    while (current1 != current2) {
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1;
}

// 两链表均有环
node1* bothLoop(linkedList1 head1,
                node1* loop1,
                linkedList1 head2,
                node1* loop2) {
    node1* current1;
    node1* current2;
    if (loop1 == loop2) {
        current1 = head1->next;
        current2 = head2->next;
        int length1 = 1;
        int length2 = 1;
        while (current1 != loop1) {
            length1++;
            current1 = current1->next;
        }
        while (current2 != loop2) {
            length2++;
            current2 = current2->next;
        }
        int lengthDelta;
        if (length1 >= length2) {
            lengthDelta = length1 - length2;
            current1 = head1;
            current2 = head2;
        } else {
            lengthDelta = length2 - length1;
            current1 = head2;
            current2 = head1;
        }
        for (int i = 0; i < lengthDelta; i++) {
            current1 = current1->next;
        }
        while (current1 != current2) {
            current1 = current1->next;
            current2 = current2->next;
        }
        return current1;
    } else {
        current1 = loop1->next;
        while (current1 != loop1) {
            if (current1 == loop2) {
                return loop1;
            }
            current1 = current1->next;
        }
        return NULL;
    }
}

// 主方法，找到两个链表的相交点
node1* getCrossedNode(linkedList1 head1, linkedList1 head2) {
    if (head1 == NULL || head1->next == NULL || head2 == NULL ||
        head2->next == NULL) {
        return NULL;
    }
    node1* loop1 = getLoopNode(head1);
    node1* loop2 = getLoopNode(head2);
    if (loop1 == NULL && loop2 == NULL) {
        return noLoop(head1, head2);
    } else if (loop1!=NULL&&loop2!=NULL) {
        return bothLoop(head1,loop1,head2,loop2);
    }else{
        return NULL;
    }
}

int main() {
    linkedList1 list1;
    initList1(&list1);
    creatFromTail1(list1);
    listPartition(list1, 5);
    printList1(list1);
    freeList1(list1);
    return 0;
}