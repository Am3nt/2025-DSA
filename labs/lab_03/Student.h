//
// Created by User on 3/4/2025.
//
typedef struct{
  int year,month,day;
  }Date_t;
enum Gender{Male,Female};

typedef struct{
    char name[51];
    char neptunCode[9];
    char birthPlace[26];
    Date_t dateOfBirth;
    enum Gender gender;
    float examResult;
}Student_t;
#ifndef STUDENT_H
#define STUDENT_H

/**
 * 
 * @param pStudent 
 */
void readStudentDetails(Student_t *pStudent);

/**
 * 
 * @param student 
 */
void printStudent(Student_t student);

/**
 * 
 * @param dpStudents 
 * @param numberOfStudents 
 */
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);

/**
 * 
 * @param dpStudents 
 * @param numberOfStudents 
 * @param input 
 */
void readAllStudentsDetails(Student_t **dpStudents, int*numberOfStudents, const char *input);

/**
 * 
 * @param pStudents 
 * @param numberOfStudents 
 * @param destination 
 */
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);

/**
 * 
 * @param dpStudents 
 * @param numberOfStudents 
 */
void calculatePercentageBoysGirls (Student_t **dpStudents, int numberOfStudents);

/**
 * 
 * @param pStudent 
 */
void deallocate(Student_t **pStudent);

/**
 * 
 * @param gender 
 * @return 
 */
char* getGender(enum Gender gender);
#endif //STUDENT_H
