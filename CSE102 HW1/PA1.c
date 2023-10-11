#include <stdio.h>
#include <stdlib.h>
//file with 10 different values will perform 9+8+..+1 operations If we call the result of this operation x. file with 100 different values will perform 99+98+..+1 operations. becomes 110x. There is a linear relationship between time and x 

int main (){
	FILE *fp;
	fp = fopen ("file.txt", "r+");

	int y=0,y1=0,a1=0,a2=0,i=0,b1=0,b2=0,as=0;
	char c;

	while(!feof(fp)){

		b1 = ftell(fp);// b1 and b2 cursors position tell you where the y value in the file.
		fscanf(fp,"%d",&y);
		b2 = ftell(fp);
		
		if(b1 == b2) break;//file end check

		while(!feof(fp)){
	
			a1 = ftell(fp);// a1 and a2 cursors position tell you where the y1 value in the file.
			fscanf(fp,"%d",&y1);
			a2 = ftell(fp);
		
			if(a1 == a2) break;//file end check
	
			as = a1;
	
			if(y1 == y){
	
	
				fseek(fp, -(a2-a1), SEEK_CUR);//placing the file cursor at beginning of y1
	
				for(i=0 ; i < (a2-a1) ; ++i){//swapping a1 if value \n is between cursors y1
	
				c = fgetc(fp);
		
				if (c == 10){
			
					as = ftell(fp);
					c = 32;
				}

			}
			
			a1 = as;
		
			fseek(fp,a1,SEEK_SET);
		
			for(i=0 ; i < (a2-a1) ; ++i) fprintf(fp," ");//Assign a space instead of  y value
			}
		}	
	fseek(fp,b2,SEEK_SET);
	}
return 0;
}
