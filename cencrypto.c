#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct encrypto {
	int c;
	int random_hash;
};

char encryptor(char c,char ecode){

	//Todo : Add a better encryption algorithm
	return (c+ecode);
}

int hash(char c,char ecode) {
	/*A random_hash is used to make the output
	more complicated to decrypt. */

	//Todo : Improve this random hash function
	return (int)pow(c,ecode);
}

int main(int argc, char *argv[]) {

	if(argc != 3) {
		printf("Two arguments expected.\n");
		printf("./cencrypto <input file> <output file>\n");
		exit(1);
	}

	char inputfile[100], outputfile[100];
	strcpy(inputfile,argv[1]);
	strcpy(outputfile,argv[2]);

	char password[100];
	printf("Enter the password(Set up your encryption key) : ");
	//Todo : Password should not be echoed back
	scanf("%s",password);
	
	FILE *fpi,*fpo;
	//Todo : add error handling, if file operation fails.
	fpi = fopen(inputfile,"r");
	fpo = fopen(outputfile,"wb");

	struct encrypto instance;
	char c = getc(fpi);
	int passindex = 0;
	while(c != EOF) {

		instance.c = encryptor(c,password[passindex]);
		instance.random_hash = hash(c,password[passindex]);
		fwrite(&instance, sizeof(struct encrypto), 1,fpo);
		c = getc(fpi);
		passindex = (passindex+1)%strlen(password);
	}
	printf("encryption Completed!\n");
	fclose(fpi);
	fclose(fpo);
	return 0;
}