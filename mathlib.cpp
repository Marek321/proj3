#include <stdio.h>
#include <limits.h>
#include <math.h>

double plus(double opA, double opB) {
  //DBL_MAX
  return opA + opB;
}

double minus(double opA, double opB) {
  //DBL_MAX
  return opA - opB;
}

double mul(double opA, double opB) {
  //DBL_MAX
  if (opB == 0 || opA == 0) 
    return 0;
  else if (opB == 1)
    return opA;
  else if (opA == 1)
    return opB;

  return opA * opB;
}

int mod(int opA, int opB){
  return opA % opB;
}

double div(double opA, double opB) {
  if( opB == 0 )
    return 0;
  
  if (opA == opB)
    return 1;
  else if (opB == 1)
    return opB;
  else if (opA == 0)
    return NAN;
  
  return opA / opB;
}

unsigned int fact(unsigned int x) {
   unsigned int sum = 1;
    for(unsigned int i = 1; i <= x; ++i)
        sum *= i;

    return sum;
}

double pow(double base, unsigned int exp) {
  
  double sum = 1;
  
  if (exp == 0) {
    return 1;
  } else if (exp == 1){
    return base;
  } else if (base == 0) {
    return 0;
  } else if (base == 1){
    return 1;
  }
    
  for (unsigned int i = 0; i < exp; ++i){
    sum *= base;
  }

  return sum;
}
