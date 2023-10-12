#include <stdio.h>
#include <stdlib.h>

void count(int* array, int N, int *countPositive, int *sumNegative) {
    for(int i = 0; i < N; i++){
	if(array[i] > 0){
	    *countPositive+=1;
	} else if(array[i] < 0){
	    *sumNegative += array[i];
	}
    }    
}
int main(){
    int N;
    scanf("%d\n", &N);
    int *array = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
	scanf("%d\n",&array[i]);
    }
    int countPositive = 0;
    int sumNegative = 0;
    count(array, N, &countPositive, &sumNegative);
    printf("Count positive: %d\nSum negative: %d\n", countPositive, sumNegative);
    void (*func) (int*, int, int*, int*);
    func = count;
    printf("Pointer to function: %p\n", func);
    free(array);

    return 0;
}
