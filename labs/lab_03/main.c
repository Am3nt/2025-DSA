#include <stdio.h>
#include "Student.h"

int main(void) {
    Student_t student={"Csengo Csenge","ASDFASDF","Vajda Hunyad",{2003,3,4},1,8};
    //readStudentDetails(&student);
    printStudent(student);
    return 0;
}
