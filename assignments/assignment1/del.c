// collaborating students:
// other collaborators:
// other resources:

#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv[]) {
    int num_machines, num_jobs;
    int job[num_jobs] [3];

    /* command-line options parsing */
     (argc != 2) {
       printf("%s -i |-r\n", argv[0]);
       return -10;
     }

           (strcmp (argv[1], "-i")) {
     	printf("Enter the number of machines in stage 1: ");
	(scanf("%d", &num_machines) != 1) {
	printf("The number of machines is invalid.\n");
     }

}
