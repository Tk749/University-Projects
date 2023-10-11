#include <stdio.h>
#include <stdlib.h>

#define x_size 512
#define y_size 512

void island_finder(); // find the island start
void path_finder(int x , int y); // find land path and mark 
void writer(); // write island cordinate in output.txt
void reader();// read inpul.txt 

int array[x_size][y_size];

int flag =-1; // island flag (flag = -1 ---> island1  , flag =-2 ---> island 2 ...)
int Water_Height = 0;//water height
int counter=0;//number of islands;

int main(){

	reader();
	island_finder();
	writer();	

}

void reader(){

	FILE *fp;
	fp=fopen("input.txt","r");

	fscanf(fp,"%d",&Water_Height);
	
	for(int i=0;i<x_size;i++){
	
		for(int j=0;j<y_size;j++){
		
			fscanf(fp,"%d",&array[i][j]);
		}
	}
	fclose(fp);
	return ;
}

void island_finder(){
	
	for(int  i=0;i<x_size;i++) {
	
		for(int  j=0;j<y_size;j++){
			
			if(array[i][j]>Water_Height){ // look for Water_Height than send path_finder function and add one to counter(number of islands)
				
				++counter;
				path_finder(i,j);
				flag=flag-1;
			}
		}
	}
	return;
}

void path_finder(int x, int y){

	if( x<0 || x > (x_size -1) || y<0 || y > (y_size -1) ) // control
		return;
	
	else if(array[x][y]>Water_Height) // if point greater than Water_Height change with island number
		array[x][y]=flag;
		
	else
		return ;
	
	path_finder(x+1,y);
	path_finder(x,y+1);
	path_finder(x-1,y);
	path_finder(x,y-1);
}

void writer(){ // write cordinate 

	FILE *fp;
	fp=fopen("output.txt","w");
	
	flag=-1;

	//fprintf(fp,"%d\n",counter);
	
	for (int  i = 0; i < x_size; i++){
	
		for(int  j=0;j< y_size;j++){
		
			if(array[i][j]==flag){ //print cordinate and flag add -1 than search another flag
			
				fprintf(fp,"x_coordinate:%d y_coordinate:%d\n",j ,i );
				flag=flag-1;
			}
		}
	}
	fclose(fp);
	return;
}
