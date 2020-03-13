#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* a, char* b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

char* strrev(char* s){
	char* p = s;
	int len = strlen(s);
	char* t = &s[len - 1];
	int i;
	for (i = 0; i < len/2; ++i){
		swap(s++,t--);
	}
	return p;
}

char * base2a (size_t n, int base){
	if(base > 10){
		fprintf(stderr,"base %zu is less than 10");
	}
  static char buffer[100];
  size_t index = 0;
  memset(buffer, 0 ,sizeof(buffer));

  while (n>0){
    size_t rem = n % base;
    n /= base;
    buffer[index++] = rem + '0';
  }
  size_t len = strlen(buffer);
  for (size_t i = 0; i < 8 - len; ++i){
    buffer[len + i ] = '0';
  }
  strrev(buffer);
  return buffer;
}



int main(int argc, const char * argv[]){
	if (argc != 2){
		fprintf(stderr,"Usage: ./bingen BaseNumber fileout\n");
		exit(1);
	}
	FILE * fout = fopen(argv[1], "w");
	
	int base = 2;
	
	for (base; base <= 10;++base){
		fprintf(fout,"Base %zu ------------------------\n",base);
	for (size_t i = 0 ; i <= 127; ++i){
		fprintf(fout, "%8s ", base2a(i,base) );
		if (i % 8 == 7){
			fprintf(fout, "\n");
		}
	}
	}
	fclose(fout);
	return 0;
}
