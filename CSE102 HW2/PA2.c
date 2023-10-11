#include <stdio.h>
#define max 100
int main(){
	FILE *fp;
	fp = fopen ("input.txt", "r");
	
	int flag=1,temporary,temporary2;
	int i=0, imax=0;
	int number, repetitions[max][2];//repetitions[max][0]--->integer repetitions[max][1]--->count of number
	
	fscanf(fp,"%d",&repetitions[0][0]);
	repetitions[0][1]=1;
	
	while(!feof(fp)){

	fscanf(fp,"%d",&number);
	
		for(int k=0; k<=i;++k){
			if(number == repetitions[k][0]){//increase repetitions[max][1](count of number) if the number already exists 
				repetitions[k][1]+=1;
					
				flag = 0;
				break;
			}
		
		
		}
		if(flag == 1){//locate if there is no number 
			i = i+1;
		
			repetitions[i][0]=number;
			repetitions[i][1]=1;
		}
		flag=1;
	}
	repetitions[i][1]-=1;//delete extra charecter
	if(repetitions[i][1] ==0) i-=1;
	
	
	fclose (fp);
	FILE *fpr;
	fpr = fopen ("output.txt", "w");
	
	for(int m=0;m<=i;++m){//sorting algorithm for integer
		for(int n=0;n<i;++n){
			if(repetitions[n][1]>repetitions[n+1][1]){
				temporary=repetitions[n][0];
				temporary2=repetitions[n][1];
		
				repetitions[n][0]=repetitions[n+1][0];
				repetitions[n][1]=repetitions[n+1][1];
		
				repetitions[n+1][0] = temporary;
				repetitions[n+1][1] = temporary2;
			}
		}
	}
	
	for(int m=0;m<=i;++m){//sorting algorithm for count of number
		for(int n=0;n<i;++n){
			if(repetitions[n][0]>repetitions[n+1][0] && repetitions[n][1]==repetitions[n+1][1]){
				temporary=repetitions[n][0];
				temporary2=repetitions[n][1];
			
				repetitions[n][0]=repetitions[n+1][0];
				repetitions[n][1]=repetitions[n+1][1];
		
				repetitions[n+1][0] = temporary;
				repetitions[n+1][1] = temporary2;
			}
		}
	}

	for(int n=0;n<=i;++n){
	fprintf(fpr,"%d:%d\n",repetitions[n][0],repetitions[n][1]);
	}
	
	fclose(fpr);
	
	return 0;

}
