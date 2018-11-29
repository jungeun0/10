#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int is_whitespace(char c){
	if( c == ' '||
		c == '\t'||
		c == '\n'||
		c == '\r'||
		c == '(' ||
		c == ')')
	{
	
		return 1; // 공백글자
	}
	
	return 0; // 유의미한 글자 
	
} 

int fget_word(FILE *fp,char* word){
	char c;
	int cnt;
	
	while((c=fgetc(fp)) != EOF)
	{
		if(is_whitespace(c) == 0){
			break;
		}
	}
		if (c == EOF){
			return 0;
		}
	
	//본격적ㅇ로 단어를 한 글자씩 읽음 
		cnt=0;
		word[cnt++]= c; //아까 읽은 첫 글자 입력
		word[cnt] = '\0'; //혹시 뒤에서 못 읽을 수 있으므로 
	
	while ((word[cnt]=fgetc(fp)) != EOF){
	
		if(is_whitespace(word[cnt]) == 1){
		
			word[cnt] = '\0';
			break;
		
		}
	
		cnt++;

	}
	return cnt;
}
	
int main(int argc, char *argv[]) {

	
	FILE* fp;
	char name[100];
	char word[100];
	
	
	printf("input the file name : ");
	scanf("%s",name);
	
	fp = fopen(name,"r");
	if(fp == NULL){
		printf("ERROR! CHECK THE FILE NAME : %s\n",name);
		return -1;//정상적으로 종료하지 않음 
	}
	
	
	while (fget_word(fp,word) != 0){
		count_word(word);
		
		
	}	
	print_word();
	
	fclose(fp);

	 
	return 0;
}
