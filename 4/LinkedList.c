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
    while (p1!=NULL&&p2!=NULL) {
        if(p1->data==p2->data){
            printf("%c ",p1->data);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data){
            p2=p2->next;
        }
        else{
            p1=p1->next;
        }
    }
    return;
}

int main() {
    linkedList1 list1;
    linkedList1 list2;
    initList1(&list1);
    initList1(&list2);
    creatFromTail1(list1);
    creatFromTail1(list2);
    printPublicPart(list1,list2);
    return 0;
}