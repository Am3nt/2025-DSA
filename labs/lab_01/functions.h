//
// Created by User on 2/25/2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 *
 * @param a
 * @param b
 * @return
 */
int sum(int a, int b);

/**
 *
 * @param a
 * @param b
 * @param c
 * @return
 */
float minimum(float a, float b,float c);

/**
 *
 * @param n
 * @return
 */
float* allocateMemoryForArray1(int n);

/**
 *
 * @param n
 * @param dpArray
 */
void allocateMemoryForArray2(int n, int **dpArray);

/**
 *
 * @param pn a tomb merete
 * @param dpArray a pointer ami a tombre mutat
 * @param input forras fajl
 */
void readArray(int *pn, int **dpArray, const char *input);

/**
 *
 * @param n
 * @param pArray
 * @param output
 */
void printArray(int n, float *pArray, const char *output);

/**
 *
 * @param dpArray
 */
void deallocateMemoryForArray(int** dpArray);

/**
 *
 * @param n
 * @param pArray
 * @param start
 * @param end
 */
void fillWithRandomNumbers(int n, float *pArray, int start, int end);

/**
 * 
 * @param n 
 * @return 
 */
bool prime(int n);

#endif //FUNCTIONS_H
