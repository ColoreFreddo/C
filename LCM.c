#include <stdio.h>

int main(void) {
  int a;
  int b;
  int t;
  int max;
  
  printf("Insert value A:\n");
  scanf("%i", &a);
  printf("Insert value B:\n");
  scanf("%i", &b);

  if (a/1 && b/1){
    if (a>b){
      a=max;
    }else {
      b=max;
    }
    while (1){
    t = max % b;
      if (t==0){
        printf("LCM = %i",b);
        break;
      }
    max = b % t;
      if (max==0){
        printf("LCM = %i",t);
        break;
      }
    b = t % max;
      if (b==0){
        printf("LCM = %i", max);
        break;
      }
    }
  }else {
    return -1;
  }
  return 0;
}
