#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// int findPosition(int length, int index, int rotation) {
// int num = index - rotation;
// if (num < 0) {
// num += length;
// }
// return num;
// }

int main(){
  int n; // length
  int k; // rotations
  scanf("%d %d",&n,&k);
  int *a = malloc(sizeof(int) * n);
  int *b = malloc(sizeof(int) * n);
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }

  memcpy(b, a + k, n * sizeof(int) - k * sizeof(int));
  memcpy(b + n - k, a, k * sizeof(int));

  // printing
  for(int i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }

  return 0;

}
