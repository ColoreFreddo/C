#include <stdio.h>
#define N 30

void sottoSequenze(int strip[], int lunghezza[]) {
  int i = 0;
  while (i < N) {
    printf("%i\n", strip[i]);
    i++;
  }
	while (i < N) {
    printf("%i\n", lunghezza[i]);
    i++;
  }
}


int main(void) {
  int V[N] = {1, 3, 4, 0, 1, 0, 9, 4, 2, 0};
  int i = 0, j = 0, k = 0;
  int strip[N];
  int lunghezza[N];
  int conta = 0;
  int maxrep = 0;
	int nvettore = 0;

  while (i < N) {
    if (V[i] == 0) {
      if (conta >= maxrep) {
        maxrep = conta;
        lunghezza[j] = conta;
        j++;
				conta = 0;
      }
    } else {
      strip[k] = V[i];
      conta++;
      k++;
    }
    i++;
  }
  sottoSequenze(strip, lunghezza);
  return 0;
}
