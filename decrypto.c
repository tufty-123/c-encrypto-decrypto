#include<stdio.h>

struct encrypto {
	int c;
};

char decryptor(char c){

	return (c-5);
}

int main() {

	FILE *fpi,*fpo;
	fpi = fopen("output","rb");
	fpo = fopen("decryped.txt","w");
	struct encrypto instance;
	while(fread(&instance, sizeof(struct encrypto), 1,fpi) == 1) {
		fprintf(fpo,"%c",decryptor(instance.c));
	}

	fclose(fpi);
	fclose(fpo);
	return 0;
	}
