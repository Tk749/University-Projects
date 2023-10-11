#include <stdio.h>
#define max 250

void fx(char c[],int i,int a,void *fpr);//recursive function
int main(){  
char c[max];
int i =0;  //array location
int a=0;  //keeps short line size

	FILE *fp;
	FILE *fpr;
	fp = fopen ("input.txt", "r");
	fpr = fopen ("output.txt", "w");
	
	fgets (c, max, fp);
	fx(c,i,a,fpr);
	
	fclose(fp);
	fclose(fpr);
}


void fx(char c[],int i,int a,void *fpr){
	
	
	if(c[i] == '\0' || c[i] == 10) return;	

	if(!(c[i] == '(' || c[i] == ',' || c[i] == ')')) //for letter
	{
	
		if(ftell(fpr) != 0)// blocks extra line
			fprintf(fpr,"\n");
	
		if(i == 0)//blocks c[-1](in else if)
			fprintf(fpr,"%c",c[i]);
	
		else if(c[i-1] == '(' || c[i-1] == ',')
		{
	
			for(int j=0;j<a;++j)
				fprintf(fpr,"-");
			
			
			fprintf(fpr,"%c",c[i]);
		}
	}
	
	else if(c[i] =='(') ++a;
	else if(c[i] ==',');
	else if(c[i] == ')') --a;
	
	fx(c,i+1,a,fpr);//recursive function
}
