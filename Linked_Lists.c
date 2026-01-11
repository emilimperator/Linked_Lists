#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
} *first = NULL, *second = NULL;

struct ListNode *Create(int A[], int length, struct ListNode *list);
void Display(struct ListNode *list);
int Count(struct ListNode *list);
int Sum(struct ListNode *list);
int Max(struct ListNode *list);
int Min(struct ListNode *list);
int LinearSearch(struct ListNode *list, int key);
struct ListNode *Insert(struct ListNode *list, int index, int element);
struct ListNode *Insert_Sorted(struct ListNode *list, int element);
struct ListNode *Append(struct ListNode *list, int element);
struct ListNode *Delete(struct ListNode *list, int index);
bool Is_Sorted(struct ListNode *list);
struct ListNode *Remove_Duplicates_Sorted(struct ListNode *list);
struct ListNode *Reverse_1(struct ListNode *list);
struct ListNode *Reverse_2(struct ListNode *list);
struct ListNode *Concatenating(struct ListNode *list1, struct ListNode *list2);
struct ListNode *Merging(struct ListNode *list1, struct ListNode *list2);
bool Is_Loop(struct ListNode *list);
void Free_List(struct ListNode *list);

int main(void) {
    int length_A;
    printf("Enter the size of an array: ");
    scanf("%d", &length_A);

    int *A = (int *)malloc(sizeof(int) * length_A);
    if (!A){
        printf("Malloc failed.\n");
        return 0;
    }
    printf("Enter the elements of an array: ");
    for (int i = 0; i < length_A; i++) {
        scanf("%d", &A[i]);
    }

    first = Create(A, length_A, first); // 1 2 3 4

    printf("The number of elements is: %d\n", Count(first));

    printf("The Sum of all elements in the list is: %d\n", Sum(first));

    printf("The Max and Min elements in the list are: %d and %d\n", Max(first),
           Min(first));

    first = Insert(first, 4, 5); // 1 2 3 4 5
    printf("After inserting 5 into 4th index: ");
    Display(first);

    first = Append(first, 5); // 1 2 3 4 5 5
    printf("After appending 5 to the end of the list: ");
    Display(first);

    first = Insert_Sorted(first, 6); // 1 2 3 4 5 5 6
    printf("After inserting 6 into the sorted array: ");
    Display(first);

    first = Delete(first, 2); // 1 2 4 5 5 6
    printf("After deleting the element at 2nd index: ");
    Display(first);

    printf("To check whether the list is sorted or not: %d\n",
           Is_Sorted(first));

    first = Remove_Duplicates_Sorted(first); // 1 2 4 5 6
    printf("After removing the duplicates from the sorted array: ");
    Display(first);

    first = Reverse_1(first); // 6 5 4 2 1
    printf("After the first method of reversing the list: ");
    Display(first);

    first = Reverse_2(first); // 1 2 4 5 6
    printf("After the second method of reversing the list: ");
    Display(first);

    int length_B;
    printf("Enter the size of the 2nd array: "); // 3
    scanf("%d", &length_B);

    int *B = (int *)malloc(sizeof(int) * length_B);
    if (!B){
        printf("Malloc failed.\n");
        return 0;
    }
    printf("Enter the elements of the 2nd array: ");
    for (int i = 0; i < length_B; i++) {
        scanf("%d", &B[i]);
    }

    second = Create(B, length_B, second); // 1 2 3

    struct ListNode *merged = Merging(first, second); // 1 1 2 2 3 4 5 6
    printf("After merging two sorted lists: ");
    Display(merged);

    struct ListNode *mixed = Concatenating(first, second); // 1 2 4 5 6 1 2 3
    printf("After Concatenating two lists: ");
    Display(mixed);

    printf("To test if the linked list is in a loop or not: %d\n",
           Is_Loop(first));

    Free_List(first);
    Free_List(second);
    Free_List(merged);
    Free_List(mixed);
    free(A);
    free(B);
}

void Display(struct ListNode *list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

struct ListNode *Create(int A[], int length, struct ListNode *list) {
    if (length <= 0)
        return NULL;
    struct ListNode *temp, *last;
    list = (struct ListNode *)malloc(sizeof(struct ListNode));
    list->data = A[0];
    list->next = NULL;
    last = list;

    for (int i = 1; i < length; i++) {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return list;
}

int Count(struct ListNode *list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

int Sum(struct ListNode *list) {
    int sum = 0;
    while (list != NULL) {
        sum += list->data;
        list = list->next;
    }
    return sum;
}

int Max(struct ListNode *list) {
    if (list == NULL) {
        printf("The list is empty.\n");
        return 0;
    }
    int biggest = list->data;
    while (list != NULL) {
        if (list->data > biggest)
            biggest = list->data;
        list = list->next;
    }
    return biggest;
}

int Min(struct ListNode *list) {
    if (list == NULL) {
        printf("The list is empty.\n");
        return 0;
    }
    int smallest = list->data;
    while (list != NULL) {
        if (list->data < smallest)
            smallest = list->data;
        list = list->next;
    }
    return smallest;
}

int LinearSearch(struct ListNode *list, int key) {
    int index = 0;
    while (list != NULL) {
        if (list->data == key)
            return index;
        index++;
        list = list->next;
    }
    return -1;
}

struct ListNode *Insert(struct ListNode *list, int index, int element) {
    if (Count(list) < index || index > 0) {
        printf("Index is out of range.\n");
        return list;
    }
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = element;
    temp->next = NULL;

    if (list == NULL)
        return temp;

    if (index != 0) {
        struct ListNode *cur = list;
        index--;
        while (index > 0 && cur != NULL) {
            cur = cur->next;
            index--;
        }
        temp->next = cur->next;
        cur->next = temp;
    } else {
        temp->next = list;
        list = temp;
    }
    return list;
}

struct ListNode *Insert_Sorted(struct ListNode *list, int element) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = element;
    temp->next = NULL;
    if (list == NULL)
        return temp;

    struct ListNode *cur = list;
    while (cur->next != NULL) {
        if (cur->next->data >= element)
            break;
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;

    return list;
}

struct ListNode *Append(struct ListNode *list, int element) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = element;
    temp->next = NULL;

    if (list == NULL)
        return temp;

    struct ListNode *cur = list;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;

    return list;
}

struct ListNode *Delete(struct ListNode *list, int index) {
    if (Count(list) <= index) {
        printf("Index is out of range.\n");
        return list;
    }
    if (index == 0) {
        struct ListNode *prev = list;
        list = list->next;
        free(prev);
    } else {
        struct ListNode *prev = list;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        struct ListNode *del = prev->next;
        prev->next = del->next;
        free(del);
    }
    return list;
}

bool Is_Sorted(struct ListNode *list) {
    if (Count(list) != 0) {
        struct ListNode *cur = list;
        while (cur->next != NULL) {
            if (cur->next->data < cur->data)
                return false;
            cur = cur->next;
        }
        return true;
    }
    printf("No elements in sight.\n");
    return false;
}

struct ListNode *Remove_Duplicates_Sorted(struct ListNode *list) {
    if (list != NULL) {
        struct ListNode *cur = list;
        while (cur != NULL && cur->next != NULL) {
            if (cur->data == cur->next->data) {
                struct ListNode *dup = cur->next;
                cur->next = dup->next;
                free(dup);
            } else {
                cur = cur->next;
            }
        }
    } else {
        printf("The list is empty.\n");
    }
    return list;
}

struct ListNode *Reverse_1(struct ListNode *list) {
    int size = Count(list), index = 0;
    int *reversed_arr = (int *)malloc(sizeof(int) * size);
    if (!reversed_arr){
        printf("Malloc failed.\n");
        return list;
    }
    struct ListNode *cur = list;

    while (cur != NULL) {
        reversed_arr[index++] = cur->data;
        cur = cur->next;
    }
    cur = list;
    index--;
    while (cur != NULL) {
        cur->data = reversed_arr[index--];
        cur = cur->next;
    }

    free(reversed_arr);
    return list;
}

struct ListNode *Reverse_2(struct ListNode *list) {
    struct ListNode *cur = list;
    struct ListNode *q = NULL, *r = NULL;

    while (cur != NULL) {
        r = q;
        q = cur;
        cur = cur->next;
        q->next = r;
    }

    return q;
}

struct ListNode *Concatenating(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;

    while (list1 != NULL) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!node)
            return dummy.next;
        node->data = list1->data;
        node->next = NULL;

        tail->next = node;
        tail = tail->next;

        list1 = list1->next;
    }

    while (list2 != NULL) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!node)
            return dummy.next;
        node->data = list2->data;
        node->next = NULL;

        tail->next = node;
        tail = tail->next;

        list2 = list2->next;
    }

    return dummy.next;
}

struct ListNode *Merging(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;

    while (list1 != NULL && list2 != NULL) {
        int x;
        if (list1->data <= list2->data) {
            x = list1->data;
            list1 = list1->next;
        } else {
            x = list2->data;
            list2 = list2->next;
        }

        struct ListNode *node =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!node)
            return dummy.next;
        node->data = x;
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    while (list1 != NULL) {
        struct ListNode *node =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!node)
            return dummy.next;
        node->data = list1->data;
        node->next = NULL;
        tail->next = node;
        tail = node;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        struct ListNode *node =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!node)
            return dummy.next;
        node->data = list2->data;
        node->next = NULL;
        tail->next = node;
        tail = node;
        list2 = list2->next;
    }

    return dummy.next;
}

bool Is_Loop(struct ListNode *list) {
    struct ListNode *slow = list, *fast = list;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

void Free_List(struct ListNode *list) {
    while (list != NULL) {
        struct ListNode *node = list->next;
        free(list);
        list = node;
    }
}
