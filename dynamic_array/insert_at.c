#include <stdio.h>
#include <stdlib.h>

int insert_at(int **arr, int *size, int index, int value){

	if(index >= 0 && (*size) >= index){
		
		(*size)++;

		int *temp = realloc(*arr, (*size) * sizeof(int));

		if(temp==NULL){
			return -1;
		} else{
			*arr = temp;
		}
		
		for(int i = (*size)-1;i>index; i--){
			(*arr)[i] = (*arr)[i-1];
		}

		(*arr)[index] = value;

		return 1;


			
	} else {
		return -1;
	}

}




int main(){
	
	int size = 10;

	int *buffer = malloc(size * sizeof(int));

	if(buffer==NULL){
		return -1;
	}

	for(int i = 0; i < size; i++){
		buffer[i] = i;
	}

	for(int i = 0; i < size; i++){
		printf("%d\n", buffer[i]);
	}

	printf("\n");
	
	int index = 5;

	int value = 1312;

	int result = insert_at(&buffer, &size, index, value);

	if(result==1){
		for(int i = 0; i < size; i++){
			printf("%d\n", buffer[i]);
		}
		free(buffer);
	} else{
		printf("wtf are u doing?");
	}



}
