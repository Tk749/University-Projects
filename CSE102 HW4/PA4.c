#include <stdio.h>
#include <string.h>

#define size 100

double recursive(char material_name[size]);

int main(){
	char object_name[size];
	
	printf("\nDefine the object:\n" );
	fgets(object_name,size,stdin);
	
	printf("Total cost of %s is %lf ",object_name,recursive(object_name));
}

double recursive(char material_name[size]){ 
	char  arr[size][size],*temp;
	int i=0,material_quantity[size];
	double sum=0;

	printf("\nWhat is %s\n",material_name);

	fgets(material_name,size,stdin);

	temp = strtok(material_name,"+*"); // for pieces of the string 
	
	while(temp!=NULL){
	
		sscanf(temp,"%d",&material_quantity[i]);//take  material quantity
	
		temp = strtok(NULL,"*+");// for pieces of the string 
	
		if(temp == NULL)    
			return material_quantity[0];//if input is alone number it returns (material price) 
	
		sscanf(temp,"%s",arr[i]);// take material name
	
		temp = strtok(NULL,"+*");// for pieces of the string 
		
		++i;
	}
	for(int j = 0; j<i; ++j)    
		sum += (double)material_quantity[j] * recursive(arr[j]);//sum the prices of each material of the object
	
	return sum;
}
