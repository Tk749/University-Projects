#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct tk{
	
	int value;
	char name[11];
};

int takestring(char s[11],void *fp);//take string

int findvalue(struct tk *t,char s[11]);

void increase_struct_size(struct tk **pt1,char temp[11],int n);//increase struct size with malloc and copy string to last element

void AND(void *fp,int n,struct tk *t,char s[11]);//AND operator

void OR(void *fp,int n,struct tk *t,char s[11]);//OR operator

void NOT(void *fp,int n,struct tk *t,char s[11]);//NOT operator

void FLIPFLOP(void *fp,int n,struct tk *t,char s[11]);//FLIPFLOP operator


int main(){

	FILE *fp = fopen("circuit.txt", "r");
	FILE *fpr = fopen("input.txt", "r");
	
	struct tk *t = malloc(sizeof(struct tk));
	
	char s[11];
	int n=0,flag=0,formerout;
	
	t[n].value=0;
	strcpy(t[n].name,"Formerout");
	++n;
	
	while(1){
	
		formerout = t[n-1].value;
	
		n=0;         //
		free(t);     //
		t = (struct tk*)malloc(sizeof(struct tk));
	
		t[n].value= formerout;
		strcpy(t[n].name,"Formerout");
		++n;
	
		rewind(fp);
		
		while(1){
	
			if( (takestring(s,fp)) == 1) break;//if fp(circuit.txt) is EOF Break while
			
			
			if(strcmp(s,"INPUT")==0){ 
	
				while(1){
		
					takestring(s,fp);
					
					if((strcmp(s,"AND")== 0) || (strcmp(s,"OR")== 0) || (strcmp(s,"NOT")== 0) || (strcmp(s,"FLIPFLOP")== 0)) break;
					
					increase_struct_size(&t,s,n);
					
					
					if(fscanf(fpr,"%d",&t[n].value) == EOF)//if fpr(input.txt) is EOF break all while
					{
						flag=1;
						break;
					}
					++n;
				}
			}
			
			
			if(flag == 1) break;//if fpr(input.txt) is EOF break all while
	
	
			/////////////////////////////////////////LOGÝC OPERATORS
			if(strcmp(s,"AND")== 0){		
								
				takestring(s,fp);		
				increase_struct_size(&t,s,n);
	
				AND(fp,n,t,s);
	
				++n;
			}
	
			else if(strcmp(s,"OR")==0){
	
	
				takestring(s,fp);
				increase_struct_size(&t,s,n);
	
				OR(fp,n,t,s);
	
				++n;
	
			}
	
			else if(strcmp(s,"NOT")==0){
	
				takestring(s,fp);
				increase_struct_size(&t,s,n);
	
				NOT(fp,n,t,s);
	
				++n;
	
			}
			else if(strcmp(s,"FLIPFLOP")==0){
	
				takestring(s,fp);
				increase_struct_size(&t,s,n);
			
				FLIPFLOP(fp,n,t,s);
	
				++n;
	
			}					
			////////////////////////////////////////
			
			
			
			
			
		}//second while end
		
		
		if(flag == 1) break;//if fpr(input.txt) is EOF break all while
		
		printf("%d\n",t[n-1].value);
	}
	
	
	
	
	fclose(fp);
	fclose(fpr);
	
}



int takestring(char s[11],void *fp){
	int a=0;
	
	for(int i =  0 ; i<11; ++i) s[i] = '\0';
	
	int i = 0;
	
	while (1){
	
		s[i]=getc(fp);
	
		if(s[i] == EOF){
			++a;// --> break second while in the main
			break;
		}
	
		if(s[i] == 10 || s[i] == 32) break;

		 ++i;
	}    
	s[i] = '\0';
	
    	if( i == 0 && a == 0) takestring(s,fp);

	return a;
}




void increase_struct_size(struct tk **pt1,char temp[11],int n){
	

	
	struct tk *pt2 = malloc((n+1)*sizeof(struct tk));
	
	
	for(int i = 0;i<n;++i){
	
		strcpy(pt2[i].name,(*pt1)[i].name);
		pt2[i].value = (*pt1)[i].value;
		
	}
	

	
	strcpy(pt2[n].name,temp);
	
	free(*pt1);
	
	(*pt1) = pt2;
	
	pt2 = NULL;
	
	return;
	}


int findvalue(struct tk *t,char s[11]){
	int i= 0;
	
	for(i = 0; i<33;++i){
	if((strcmp(t[i].name,s)) == 0) break;}
	
	return t[i].value;
	
	
	
}

void AND(void *fp,int n,struct tk *t,char s[11]){
	
	
	int a,b;
	
	takestring(s,fp);
	a = findvalue(t,s);
	takestring(s,fp);
	b = findvalue(t,s);
	
	if(a==1 && b == 1 ) t[n].value = 1;
	else if(a==1 && b == 0 ) t[n].value = 0;
	else if(a==0 && b == 1 ) t[n].value = 0;
	else if(a==0 && b == 0 ) t[n].value = 0;
	
	return;
	
}

void OR(void *fp,int n,struct tk *t,char s[11]){
	
	int a,b;
	takestring(s,fp);
	a = findvalue(t,s);
	takestring(s,fp);
	b = findvalue(t,s);
	
	if(a==1 && b == 1 ) t[n].value = 1;
	else if(a==1 && b == 0 ) t[n].value = 1;
	else if(a==0 && b == 1 ) t[n].value = 1;
	else if(a==0 && b == 0 ) t[n].value = 0;
	
	return;
	
}

void NOT(void *fp,int n,struct tk *t,char s[11]){
	
	int a;
	
	takestring(s,fp);
	a = findvalue(t,s);
	
	if(a==1) t[n].value = 0;
	else if(a==0) t[n].value = 1;
	
	return;
	
}
void FLIPFLOP(void *fp,int n,struct tk *t,char s[11]){
	
	int a;
	
	takestring(s,fp);
	a = findvalue(t,s);
	
	if(a==1 && t[0].value == 1 ) t[n].value = 0;
	else if(a==0 && t[0].value == 1 ) t[n].value = 1;
	else if(a==1 && t[0].value == 0 ) t[n].value = 1;
	else if(a==0 && t[0].value == 0 ) t[n].value = 0;
	
	return;
	
}



