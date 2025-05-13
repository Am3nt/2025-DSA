#include <stdio.h>
#include "constants.h"
#include "binary_tree.h"


int main(void) {
    int s;
    printf("Hany konvet szeretne beolvasni:");
    scanf("%d", &s);
    freopen("konyvek.txt", "r", stdin);
    Konyv uj;
    Node *head=NULL;
    for (int i = 0; i < s; ++i) {
        scanf("%[^\n]\n%[^\n]\n%d\n%d\n",
    uj.nev,
    uj.szerzo,
    &uj.kiev,
    &uj.kolcs);
        {
            if(head==NULL) {
                head = createNewNode(uj);
            }
            else
            {
                insertLeft(head,uj);
            }
            //printf("%s %s %d %d;\n",uj.nev,uj.szerzo,uj.kiev,uj.kolcs);
        }
    }
    freopen("CON", "r", stdin);
    inorderTraversal(head);
    int n;
    printf("Enter a number (1-3): ");
    scanf("%d", &n);
    switch (n) {
        case 1:{
            freopen("konyvek.txt", "r", stdin);
            scanf("%[^\n]\n%[^\n]\n%d\n%d\n",
    uj.nev,
    uj.szerzo,
    &uj.kiev,
    &uj.kolcs);
        {
            if(head==NULL) {
                head = createNewNode(uj);
            }
            else
            {
                insertRight(head,uj);
            }
            //printf("%s;%s;%d;%d;\n",uj.nev,uj.szerzo,uj.kiev,uj.kolcs);
        }
    }
        freopen("CON", "r", stdin);
        inorderTraversal(head);
        break;
        case 2:

        break;
        case 3:

        break;
        default:

        break;
    }
    return 0;
}
