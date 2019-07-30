#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	FILE *fp;
	fp = fopen("record.txt","w");
	for(int i = 0; i<n; i++){
		fprintf(fp,"%d\t", rand()%100);
	}
	fprintf(fp,"\n");
	fclose(fp);
	return 0;
}
