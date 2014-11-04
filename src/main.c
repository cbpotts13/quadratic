
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"
#include "get_input.h"


int main(){
  Values val;
  Roots roots;
  float ch;
  float a,b,c;
  float d; 
  int flag = 1; 
  int result;
  
  while (flag == 1) {

    while(get_input(&val) == -1);
    
    switch (result = solve_quad(&val, &roots)) {
      case -2: // No real roots
             printf("No real roots\n");
             break;
      case -1: // Not a quadratic (a == 0)
             printf("Not a quadratic (a==0)\n");
             break;
      case 1:  // double real root
             printf("Double real root %24.16f\n", roots.x1);
             break;
      case 2:  // two distinct roots
             printf("Roots  %24.16f  %24.16f\n", roots.x1, roots.x2);
             break;
      
    }
    do {
      printf("Please enter 1 to run again or 0 to quit: ");
      result = fscanf(stdin, "%d", &flag);
      fseek(stdin,0,SEEK_END);
      } while(result != 1);
    
  }
  return 0;
}
