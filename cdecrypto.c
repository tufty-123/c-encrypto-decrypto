#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct encrypto {
	int c;
	int random_hash;
};

char decryptor(char c,char ecode){

	return (c-ecode);
}

int main(int argc,char *argv[]) {

	if (argc != 3) {
	printf("Two arguments expected.\n");
	printf("./cdecrypto <input file> <output file>\n");
	exit(1);
	}

	char inputfile[100], outputfile[100];
	strcpy(inputfile,argv[1]);
	strcpy(outputfile,argv[2]);	

	char password[100];
	printf("Enter the password: ");
	scanf("%s",password);

	FILE *fpi,*fpo;
	//Todo : add error handling, if file operation fails.
	fpi = fopen(inputfile,"rb");
	fpo = fopen(outputfile,"w");
	struct encrypto instance;
	int passindex = 0;
	while (fread(&instance, sizeof(struct encrypto), 1,fpi) == 1) {
		fprintf(fpo,"%c",decryptor(instance.c,password[passindex]));
		passindex = (passindex+1)%strlen(password);
	}
	printf("Decryption Completed!\n");
	fclose(fpi);
	fclose(fpo);
	return 0;
	}
