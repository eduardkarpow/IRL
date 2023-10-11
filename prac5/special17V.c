#include <stdio.h>
#include <stdlib.h>

void count(int* array, int N) {
    int countPositive = 0;
    int sumNegative = 0;
    for(int i = 0; i < N; i++){
	if(array[i] > 0){
	    countPositive++;
	} else if(array[i] < 0){
	    sumNegative += array[i];
	}
    }    
    printf("Count positive: %d\nSum negative: %d\n", countPositive, sumNegative);
}
int main(){
    int N;
    scanf("%d\n", &N);
    int *array = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
	scanf("%d\n",&array[i]);
    }
    count(array, N);
    free(array);

    return 0;
}
