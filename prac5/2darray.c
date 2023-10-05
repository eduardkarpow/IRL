#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int N;
    scanf("%d\n", &N);
    int **array = (int**) malloc(sizeof(int*)*N);
    for(int i = 0; i < N; i++){
	array[i] = (int*) malloc(sizeof(int)*N);
    }
    for(int i = 0; i < N; i++){
	for(int j = 0; j < N; j++){
	    scanf("%d\n", &array[i][j]);
	}
    }
    for(int i = 0; i < N; i++){
	for(int j = 0; j < N; j++){
	    printf("%d ", array[i][j]);
	}
	printf("\n");
    }
    printf("Main pointer %p\n", array);
    for(int i = 0; i < N; i++){
	printf("Pointer number %d: %p\n", i, array[i]);
    }
    for(int i = 0; i < N; i++){
	free(array[i]);
    }
    free(array);

    return 0;
}
