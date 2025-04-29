//
// Created by User on 3/4/2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "student.h"

void readStudentDetails(Student_t *pStudent){
scanf("%[^\n]\n",&pStudent->name);
scanf("%[^\n]\n",&pStudent->neptunCode);
scanf("%[^\n]\n",&pStudent->birthPlace);
scanf("%d%d%d\n",&pStudent->dateOfBirth.year,&pStudent->dateOfBirth.month,&pStudent->dateOfBirth.day);
scanf("%i\n",&pStudent->gender);
scanf("%f\n",&pStudent->examResult);
  }

char* getGender(enum Gender gender) {
    switch (gender) {
        case 0: return "Male";
        case 1: return "Female";
    }
    return "Unkown";
}

void printStudent(Student_t student){
    printf("Name: %s\n",student.name);
    printf("Neptun code: %s \n",student.neptunCode);
    printf("Place of birth: %s \n",student.birthPlace);
    printf("Date of birth: %d ",student.dateOfBirth.year);
    printf("%d ",student.dateOfBirth.month);
    printf("%d \n",student.dateOfBirth.day);
    printf("Gender: %s \n",getGender(student.gender));
    printf("Exam result: %.2f\n",student.examResult);
}

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents=(Student_t*)malloc(numberOfStudents* sizeof(Student_t));
    if(!(*dpStudents)) {
        printf("Error");
        exit(-2);
    }
}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    if(!freopen(input,"r",stdin)){
        printf("Error");
        exit(-2);
    }
    scanf("%i\n", numberOfStudents);
    allocateMemoryForStudents(dpStudents,*numberOfStudents);
    for(int i=0; i < *numberOfStudents;i++) {
        readStudentDetails(&(*dpStudents)[i]);
    }
    freopen("CON","r",stdin);
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    freopen(destination,"w",stdout);
    for(int i=0; i< numberOfStudents;i++) {
        printStudent(pStudents[i]);
    }
}


void deallocate(Student_t **pStudent) {
    free(*pStudent);
    *pStudent=NULL;
}



