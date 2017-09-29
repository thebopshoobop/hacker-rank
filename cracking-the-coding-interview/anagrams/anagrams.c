#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int partition(char a[], int lo, int hi) {
    int pivot = a[hi];
    int i = lo - 1;
    for(int j = lo; j < hi; j++) {
        if(a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    if (a[hi] < a[i + 1]) {
        int temp = a[i + 1];
        a[i + 1] = a[hi];
        a[hi] = temp;
    }

    return i + 1;
}

void sort(char a[], int lo, int hi) {
    if(lo < hi) {
        int p = partition(a, lo, hi);
        sort(a, lo, p - 1);
        sort(a, p + 1, hi);
    }         
}


int main(){
    char a[512000];
    scanf("%s",a);
    char b[512000];
    scanf("%s",b);
      
    sort(b, 0, strlen(b) - 1);
    sort(a, 0, strlen(a) - 1);

    int i_a = 0;
    int i_b = 0;
    int moves = 0;
    while(i_a < strlen(a) && i_b < strlen(b)) {
        if(a[i_a] < b[i_b]) {
            i_a++;
            moves++;
        } else if (a[i_a] > b[i_b]) {
            i_b++;
            moves++;
        } else {
            i_b++;
            i_a++;
        }
    }
 
    
    moves += (strlen(a) - i_a) + (strlen(b) - i_b);
    
        
    printf("%d", moves);
    
    return 0;
}
