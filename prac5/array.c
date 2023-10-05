#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d\n", &N);
    int *array = (int*) malloc(N*sizeof(int));
    for(int i = 0; i < N; ++i){
	scanf("%d\n", &array[i]);
    }    
    for(int i = 0; i < N; ++i){
	printf("%d ", array[i]);
    }
    printf("\nPointer is: %p\n", array);
    free(array);
	
    return 0;
}
