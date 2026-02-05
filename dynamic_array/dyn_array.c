#include <stdio.h>
#include <stdlib.h>


int arr_init(int **arr, int *size, int *capacity){

	(*size) = 0;
	
	int *temp = malloc(sizeof(int) * (*capacity));
	
	if(temp==NULL){
		return -1;
	} else {
		*arr = temp;
		return 0;
	}
}


int arr_push(int **arr, int *size, int *capacity, int value){
	
	if((*capacity)==(*size)){
		int *temp = realloc(*arr, sizeof(int) * (*capacity)*2);
		if(temp==NULL){
			return -1;
		} else {
			*arr = temp;
			(*capacity) = (*capacity) * 2;		
		}
	}

	(*arr)[*size] = value;

	(*size)++;
	return 0;
}


int arr_remove_at(int *arr, int *size, int index){
	
	for(int i = index; i<(*size)-1; i++){
		arr[i] = arr[i+1];
	}

	(*size)--;

	return 0;
}	


int arr_free(int **arr){

	free(*arr);
	*arr = NULL;
	return 0;
}


int arr_get(int *arr, int size, int index, int *out){

	if(0<=index && index < size){

		(*out) = arr[index];
	       return 0;
	}
	
	return -1;	
	
}



int main(void) {
    int *arr = NULL;
    int size = 0;
    int capacity = 4;

    if (arr_init(&arr, &size, &capacity) != 0) {
        printf("Init failed\n");
        return 1;
    }

    printf("Pushing values:\n");
    for (int i = 0; i < 10; i++) {
        if (arr_push(&arr, &size, &capacity, i * 10) != 0) {
            printf("Push failed at %d\n", i);
            arr_free(&arr);
            return 1;
        }
        printf("  pushed %d (size=%d, capacity=%d)\n",
               i * 10, size, capacity);
    }

    printf("\nArray contents:\n");
    for (int i = 0; i < size; i++) {
        int value;
        arr_get(arr, size, i, &value);
        printf("  arr[%d] = %d\n", i, value);
    }

    printf("\nRemoving element at index 3\n");
    arr_remove_at(arr, &size, 3);

    printf("After removal:\n");
    for (int i = 0; i < size; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);
    }

    arr_free(&arr);
    return 0;
}
