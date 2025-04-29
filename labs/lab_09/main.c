#include <stdio.h>
#include "simplelist.h"

int main(void) {
    Node *n1 = NULL;
    n1 = newNode(4);
    insertAtEnd(&n1,3);
    insertAtEnd(&n1,2);
    Node *n2 = NULL;
    n2 = newNode(7);
    insertAtEnd(&n2,8);
    insertAtEnd(&n2,9);
    printList(n1);
    printf("\n");
    printList(n2);
    printf("\n");
    Node *n3 = NULL;
    n3=newNode(0);
    printList(n3);
    printf("\n");
    int s;
    while (isEmpty(n1)==false || isEmpty(n2)==false) {
        s=n1->data+n2->data;
        printf("%i \n",s);
        if (s>9) {
            n3->data=n3->data+s%10;
            printList(n3);
            n3=newNode(s/10);
        }
        else {
            n3->data+=n3->data+s;
            n3=newNode(0);
        }
        deleteFromEnd(&n1);
        deleteFromEnd(&n2);
        printList(n3);
        printList(n1);
        printf("\n");
        printList(n2);
        printf("\n");
    }
    printList(n3);
}
