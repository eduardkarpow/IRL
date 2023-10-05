#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d\n", &N);
    int * array = (int*) malloc(sizeof(int)*N);
    int countPositive = 0;
    int sumNegative = 0;
    for(int i = 0; i < N; i++){
	scanf("%d\n", &array[i]);
	if(array[i] > 0){
	    countPositive++;
	} else if(array[i] < 0){
	    sumNegative += array[i];
	}
    }    
    printf("Count positive: %d\nSum negative: %d\n", countPositive, sumNegative);
    free(array);

    return 0;
}
