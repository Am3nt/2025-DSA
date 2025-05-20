#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
//#include "../hash_static_uj/headers/hash_table.h"

int main() {
    HashTable table;
    createHashArray(&table);
    display(table);
    // srand(time(0));
    if (!freopen("results.txt","r", stdin)) { printf("Error Memory"); return 0; }
    int n=0;
    scanf("%i\n",&n);
    for (int i = 0; i < n; i++) {
        int key = 0;
        float temp;
        char s[7];
        scanf("%s%f\n",s,&temp);
        for (int j = 0; j < strlen(s); j++) {
            key+= s[j];
        }
        insert(&table,key,temp, s);
    }
    display(table);
    destroyHashArray(&table);
    return 0;
}
