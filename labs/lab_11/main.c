#include <stdio.h>
#include "./headers/binary_search_tree.h"
#include "./headers/constants.h"
#include <string.h>

int main(void) {
    freopen("data.txt", "r", stdin);
    Barat uj;
    Node *head=NULL;
    while ((scanf("%[^;];%d;%d;%d;%c;%d\n",
    uj.nev,
    &uj.szuletesiDatum.ev,
    &uj.szuletesiDatum.honap,
    &uj.szuletesiDatum.nap,
    &uj.nem,
    &uj.bulizas) != EOF))
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
