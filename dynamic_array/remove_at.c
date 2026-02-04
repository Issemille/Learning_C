#include <stdio.h>
#include <stdlib.h>



int remove_at(int **arr, int *size, int index){

	for(int i = index-1; i < (*size)-1; i++){
		(*arr)[i]=(*arr)[i+1];
	}

	(*size)--;
	
	int *temp = realloc(*arr,( *size) * sizeof(int));

	if(temp==NULL) {
		return -1;
	} else {
		*arr = temp;
	}

	return 1;
}



int main() {
	
	int len = 6;

	int *buffer = malloc(sizeof(int)*len);
	
	if(buffer==NULL){
		return -1;
	}

	 for(int i = 0; i < len; i++){
        	buffer[i] = i;
	 }

	int index = 3;
   

	for(int i = 0; i < len; i++){
		printf("%d\n", buffer[i]);
	}

	int result = remove_at(&buffer, &len, index);


	if(result==1){
		for(int i = 0; i < len; i++){
			printf("%d\n", buffer[i]);
		}
		free(buffer);
	} else {
		printf("wtf are u doing?\n");
	}
}
