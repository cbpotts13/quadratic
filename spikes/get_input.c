#include <stdio.h>
#include <stdlib.h>

int get_input(Values *val) {
  
  double a,b,c;
  
  printf("Enter a, b and c of quadratic equation: ");
  if (fscanf(stdin,"%lf%lf%lf",&a,&b,&c) != 3){
    fseek(stdin,0,SEEK_END);
    return -1;
  }
    
  fseek(stdin,0,SEEK_END);
  return 0;
}
