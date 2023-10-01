#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 单向链表
typedef struct node1 {
    char data;
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
    char i;
    scanf("%c", &i);
    while (i != '$') {
        s = (node1*)malloc(sizeof(node1));
        s->data = i;
        s->next = head->next;
        head->next = s;
        scanf("%c", &i);
    }
    return;
}

// 尾插法建单向链表
void creatFromTail1(linkedList1 head) {
    node1 *s, *t;
    t = head;
    char i;
    scanf("%c", &i);
    while (i != '$') {
        s = (node1*)malloc(sizeof(node1));
        s->data = i;
        t->next = s;
        s->next = NULL;
        t = s;
        scanf("%c", &i);
    }
    return;
}

// 遍历输出单向链表
void printList1(linkedList1 head) {
    node1* node = head->next;
    while (node != NULL) {
        printf("%c", node->data);
        node = node->next;
    }
    return;
}

//释放单链表内存
void freeList1(linkedList1 head) {
    node1* current = head;
    while (current != NULL) {
        node1* temp = current;
        current = current->next;
        free(temp);
    }
}

// 双向链表
typedef struct node2 {
    char data;
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
    char i;
    scanf("%c", &i);
    while (i != '$') {
        s = (node2*)malloc(sizeof(node2));
        s->data = i;
        s->next = head->next;
        if (s->next != NULL) {
            s->next->prev = s;
        }
        head->next = s;
        s->prev = head;
        scanf("%c", &i);
    }
    return;
}

// 尾插法建双向链表
void creatFromTail2(linkedList2 head) {
    node2 *s, *t;
    t = head;
    char i;
    scanf("%c", &i);
    while (i != '$') {
        s = (node2*)malloc(sizeof(node2));
        s->data = i;
        t->next = s;
        s->prev = t;
        s->next = NULL;
        t = s;
        scanf("%c", &i);
    }
    return;
}

// 遍历输出双向链表
void printList2(linkedList2 head) {
    node2* node = head->next;
    while (node != NULL) {
        printf("%c", node->data);
        node = node->next;
    }
    return;
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
            printf("%c ", p1->data);
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
    printf("中点数据为：%c\n中点节点序号为：%d\n", ptrSlow->data, count);
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
    printf("中点数据为：%c\n中点节点序号为：%d\n", ptrSlow->data, count);
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
    printf("中点前一个节点数据为：%c\n中点节点序号为：%d\n", ptrPrv->data,
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
    printf("中点后一个节点数据为：%c\n中点节点序号为：%d\n", ptrSlow->next->data,
           count + 1);
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

int main() {
    linkedList1 list1;
    initList1(&list1);
    creatFromTail1(list1);
    printf("链表是否为回文结构判断结果：%s",
           isPalindrome(list1) ? "true" : "false");
    freeList1(list1);
    return 0;
}