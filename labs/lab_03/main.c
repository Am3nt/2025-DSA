#include <stdio.h>
#include "Student.h"

int main(void) {
    int n;
    Student_t *t;
    readAllStudentsDetails(&t,&n,"be.txt");
    printAllStudents(t,n,"ki.txt");
    return 0;
}
