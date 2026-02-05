#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


#define LIMIT 20


int parse(char *line, char **argv, int max_args) {
    int argc = 0;
    char *p = line;

    while (*p != '\0') {

        while (*p == ' ' || *p == '\t' || *p == '\n') {
            *p = '\0';
            p++;
        }

        if (*p == '\0')
            break;

        if (argc < max_args - 1) {
            argv[argc++] = p;
        }

        while (*p && *p != ' ' && *p != '\t' && *p != '\n') {
            p++;
        }
    }

    argv[argc] = NULL;
    return argc;
}








int main() {
	
	printf("Enter 'exit' to exit\n");	
	char *args [LIMIT];

	

	char arg[LIMIT];
	char* exit_command = "exit"; 
	char* change = "cd";


	do {
		printf("shell> ");
		
		if (fgets(arg, LIMIT, stdin) == NULL) {
			break;
		}
			
		arg[strcspn(arg, "\n")] = '\0';

		
		int nr_arg = parse(arg, args, LIMIT);
				
		if(nr_arg==0){
			printf("WE NEED A COMMAND!\n");
			continue;
		}

		if(strcmp(args[0], change)==0){
			if(nr_arg==1){
				chdir("..");
				continue;
			}

			chdir(args[1]);
			continue;
		}
		
		int pid = fork();

		if(pid==0){
			execvp(args[0], args);
			printf("Unknown command\n");
			exit(1);
		} else if (pid==-1){
				printf("BIG PROBLEM\n");
				exit(1);
		} else{
			int status;
			wait(&status);
		}

	} while(strcmp(arg, exit_command));
}
