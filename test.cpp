#include <stdio.h>
#include <stdlib.h>
#include "mathlib.h"
#include <limits.h>
#include <math.h>

void testAdd(double opA, double opB, double result){
  double tmp;
  if (tmp=(plus(opA,opB)) == result) {
    printf(" PASSED: %lf + %lf = %lf\n", opA, opB, result);
  } else {
    printf(" FAILED: %lf + %lf; expected %lf => result %lf\n", opA, opB, result, tmp);
  }
}

void testSub(double opA, double opB, double result){
  double tmp;
  if (tmp=(minus(opA,opB)) == result) {
    printf(" PASSED: %lf - %lf = %lf\n", opA, opB, result);
  } else {
    printf(" FAILED: %lf - %lf; expected %lf => result %lf\n", opA, opB, result, tmp);
  }
}
void testMul(double opA, double opB, double result){
  double tmp;
  if (tmp=(mul(opA,opB)) == result) {
    printf(" PASSED: %lf * %lf = %lf\n", opA, opB, result);
  } else {
    printf(" FAILED: %lf * %lf; expected %lf => result %lf\n", opA, opB, result, tmp);
  }
}

void testDiv(double opA, double opB, double result){
  double tmp;
  if (tmp=(div(opA,opB)) == result) {
    printf(" PASSED: %lf / %lf = %lf\n", opA, opB, result);
  } else {
    printf(" FAILED: %lf / %lf; expected %lf => result %lf\n", opA, opB, result, tmp);
  }
}

void testMod(int opA, int opB, int result){
  int tmp;
  if (tmp=(mod(opA,opB)) == result) {
    printf(" PASSED: %d %% %d = %d\n", opA, opB, result);
  } else {
    printf(" FAILED: %d %% %d; expected %d => result %d\n", opA, opB, result, tmp);
  }
}

void testFact(unsigned int opA, unsigned int result){
  unsigned int tmp= fact(opA);
  if (tmp == result) {
    printf(" PASSED: %d! = %d\n", opA, result);
  } else {
    printf(" FAILED: %d! ; expected %d => result %d\n", opA, result, tmp);
  }
}

void testPow(double opA, unsigned int exp, double result){
  double tmp= pow(opA, exp);
  if (tmp == result) {
    printf(" PASSED: %lf^%d = %lf\n", opA,exp, result);
  } else {
    printf(" FAILED: %lf^%d ; expected %lf => result %d\n", opA, exp, result, tmp);
  }
}

int main(void) {
  
  printf("Running tests:\n");
  printf("Addition:\n");
  
  double x;
  //---------
  testAdd(10,10,20);
  testAdd(0.0001,-0.0001,0);
  testAdd(0,-0,0);
  testAdd(10001,-20002,-10001);
  testAdd(-254,-246,-500);
   //---------
  printf("Subtraction:\n");
  testSub(10, 5, 5);
  testSub(0, -123, 123);
  testSub(-5000, 5000, -10000);
  testSub(-10000, -10000, 0);
  testSub(0,0,0);
  printf("Multiplication:\n");
  testMul(-1,-2,2);
  testMul(0,123,0);
  testMul(124,0,0);
  testMul(-12,-2,24);
  testMul(1,-2,-2);
  testMul(234,-428,-100152);
  //---------
  printf("Division: (0 jako vysledek indikuje chybu)\n");
  testDiv(1,0,0);
  testDiv(125,5,25);
  testDiv(1000,-10,-100);
  testDiv(-12.5,-12.5,1);
  testDiv(12.5,-12.5,-1);
   //---------
  printf("Modulo:\n");
  testMod(123,5,3);
  testMod(12, 5, 2);
  testMod(0, 5, 0);
  //---------
  printf("Factiorial:\n");
  testFact(5,120);
  testFact(0,1);
  testFact(1,1);
  testFact(12, 479001600);  
   //---------
  printf("Pow:\n");
  testPow(1,1,1);
  testPow(1,0,1);
  testPow(0,0,1);
  testPow(0,1,0);
  testPow(-2,3,-8);
   //---------
    
  
  return EXIT_SUCCESS;
  
}