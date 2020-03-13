#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define SLEN 8

void printParity(int num);
void printAscii(int num);
int calculateTotal(char c[]);

int main(int argc, const char* argv[]){	
	int i,index, total;
	char c;
	
	if(argc != 2){
		fprintf(stderr,"Usage: ./converter file in\n");
		exit(1);
	}
	FILE* fin;
	fin = fopen(argv[1], "r");
	
	total = 0;
	index = 0;
	char s[SLEN];
	memset(s,'0',sizeof(s));
	
	printf("Original || Base 10 || ASCII || Parity\n");
	c = fgetc(fin);
	while(c != EOF){
		if(c == ' ' || c == '\t' || c == '\n'){
			c = fgetc(fin);
		}
		else{
			s[index] = c;
			index++;
			c = fgetc(fin);
		}
		if (index == SLEN){

			total = calculateTotal(s);
			for ( i = 0; i < SLEN; i++){
				printf("%c", s[i]);
			}
			printf("\t%d\t",total);
			printAscii(total);
			printParity(total);
			memset(s,'0',sizeof(s));
			index = 0;
		}
	}
	fclose(fin);
	return 0;
}
int calculateTotal(char c[]){
	int len = 0;
	int total = 0;
	while (len < SLEN){
			total += (c[len] - '0') * pow(2,(SLEN - 1) - len);
			len++;
		}
			if (total >= 128){
				total = total - 128;
			}
	return total;
}
void printParity(int num){
	if((num % 2) == 1){
		printf("\tOdd\n");
	}
	else{
		printf("\tEven\n");
	}
}

void printAscii(int num){
	const char* name[] = {"NUL","SOH","STX","ETX","EOT","ENQ",
	"ACK","BEL","BS","TAB","LF","VT","FF","CR","SO","SI","DLE",
	"DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB",
	"ESC","FS","GS","RS","US"};
	
	if (num <= 31){
		printf("%s",name[num]);
	}
	
	else{
		printf("%c",num);
	}
}
