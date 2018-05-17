#include<stdio.h>

struct encrypto {
	int c;
};

char encryptor(char c){

	return (c+5);
}
int main() {
	
	FILE *fpi,*fpo;
	fpi = fopen("input.txt","r");
	fpo = fopen("output","wb");
	struct encrypto instance;
	char c = getc(fpi);
	while(c != EOF)
	{
		instance.c = encryptor(c);
		fwrite(&instance, sizeof(struct encrypto), 1,fpo);
		c = getc(fpi);
	}

	fclose(fpi);
	fclose(fpo);
	return 0;
}