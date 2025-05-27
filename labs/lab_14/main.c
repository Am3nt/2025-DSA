#include <stdio.h>
#include "heap.h"
#include "binary_search_tree.h"

int main(void) {
    Student* arr=(Student*)malloc(CAPACITY*sizeof(Student));
    if (!arr) {
        printf("Memory allocation error");
        return 1;
    }
    if (!freopen("results.txt","r",stdin)) {
        printf("Error while opening file");
        return 1;
    }
    int i=0;
    while (scanf("%[^,],%f\n",arr[i].Neptun,&arr[i].average)!=EOF) {
        i++;
    }
    int n=i;
    heapSort(arr,n);
    printArray(arr,n);
    free(arr);
    Student1 uj;
    Node *head=NULL;
    if (!freopen("szesszio.csv","r",stdin)) {
        printf("Error while opening file");
        return 1;
    }
    while ((scanf("%[^,],%f\n",
    uj.Neptun,
    &uj.average
    ) != EOF))
    {
        if(head==NULL) {
            head = createNewNode(uj);
        }
        else
        {
            insert(head,uj);
        }
    }
    inorderTraversal(head);
    return 0;
}
