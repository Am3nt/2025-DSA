#include <stdio.h>
#include "simple_list_functions.h"
#include "headers/binary_search_tree.h"

int main(void)
{
    /*Írj egy programot, amely az alábbi lépéseket hajtja végre az egyszeresen láncolt listán:

    Hozz létre egy üres listát.

    Adj hozzá három elemet a lista végéhez a insertAtEnd függvény segítségével.

    Adj hozzá egy elemet a lista elejére a insertAtBeginning függvénnyel.

    Adj hozzá egy elemet egy adott elem után a insertAfter függvény használatával (például a második elem után).

    Ellenőrizd, hogy a lista üres-e az isEmpty függvénnyel, és írd ki az eredményt.

    Írd ki a lista elemeit a printList függvénnyel.*/

        /*int number1=1, number2=2;
        Node *head1 = NULL;
        head1= newNode(number1);
        insertAtEnd(&head1,number2);
        printList(head1);*/
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
                 head = newNode(uj);
             }
             else
             {
                 insertAtEnd(&head,uj);
             }
         }
    printList(head);
    kibuli(head,buli(head));
    return 0;
}