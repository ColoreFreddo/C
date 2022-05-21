#include <stdio.h>

int Max(int n1,int n2){
  int max;
  if (n1 > n2 ){
  max = n1;
  }else {
    max = n2;
  }
  return max;
}

int Min(int n1,int n2){
  int min;
  if (n1 < n2 ){
  min = n1;
  }else {
    min = n2;
  }
  return min;
}

int main(void) {
int n1,n2,n3,max,low,discard,test=0;
FILE *in = fopen("numbers.txt", "r");
if (fscanf(in, "%d", &n1)==-1){
  printf("Error: empty file!");
  return 0;
}
  fscanf(in, "%d", &n2);
  fscanf(in, "%d", &n3);
  max = Max(n1,n2);
do{
  if ((n1 + n2)==n3){
    test=1;
  }
  else if ((n1 - n2)==n3){
    test=1;
  }
  else if((n1 * n2)==n3){
    test = 1;
  }
  else if (n2 != 0 && (n1 / n2)==n3){
    test = 1;
  }
  else 
    discard++;
  test = 0;
  if (test==1){
    n1=n2;
    n2=n3;
  }
  max = Max(max,n3);
  min = Min(min,n3);
}while (fscanf(in, "%d\n", &n3)!=EOF);
  printf("max = %d\n",max);
  printf("low = %d\n", min);
  printf("discard = %d\n", scarto);
return 0;
}
