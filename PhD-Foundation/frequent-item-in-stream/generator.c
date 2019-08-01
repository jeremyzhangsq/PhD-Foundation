#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int s = atoi(argv[1]);
	int n = atoi(argv[2]);
	FILE *fp;
	fp = fopen("record.txt","w");
	int r;
	for(int i = 0; i<n; i++){
		r = rand();
		fprintf(fp,"%d\t", r%s);
	}
	fprintf(fp,"\n");
	fclose(fp);
	return 0;
}
