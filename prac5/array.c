#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d\n", &N);
    int *array = (int*) malloc(N*sizeof(int));
    for(int i = 0; i < N; ++i){
	scanf("%d\n", &array[i]);
    }    
    printf("Pointer of array is %p\n", array);
    for(int i = 0; i < N; ++i){
	printf("value = %d pointer = %p\n ", array[i], &array[i]);
    }
    free(array);
	
    return 0;
}
