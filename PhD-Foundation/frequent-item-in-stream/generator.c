#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	FILE *fp;
	fp = fopen("record.txt","w");
	int r;
	for(int i = 0; i<n; i++){
		r = rand();
		fprintf(fp,"%d\t", r%10);
	}
	fprintf(fp,"\n");
	fclose(fp);
	return 0;
}