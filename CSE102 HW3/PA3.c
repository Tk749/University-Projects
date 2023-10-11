#include <stdio.h>
#include <math.h>

int main()
{

    FILE *file = fopen("polynomial.txt", "r");
    FILE *fp = fopen("values.txt", "r");
    FILE *fpr = fopen("evaluations.txt","w");
    
    char operator='+',x;
    double coefficient=0,result=0,value,sum;
    int power;
    
    while(fscanf(fp, "%lf", &value) != EOF)      /* reads value from values.txt*/
    {
    	sum=0;
    	result =0;
    	fseek(file,0,SEEK_SET);    /*back to the beginning of polynomial.txt*/
    	operator = '+';
    	
    	while(1)
    	{
    	    if(operator == '+') result = 1;    /*operator between the terms of the polynomial*/
    	    else result = -1;
    
    	    if(fscanf(file,"%lf",&coefficient)); /*coefficients of polynomial terms*/
    	    else coefficient=1;
    
    	    fscanf(file,"%c",&x);
    	    fscanf(file,"%c",&operator);
    	    
    	    if(operator ==  '^')     /*power of polynomial terms*/
    	    {
    	        fscanf(file,"%d",&power);
    	        fscanf(file,"%c",&operator);
    	    }
    	    else power=1;
   
    	    result *= coefficient * pow(value,power);/*value of the term for x value*/
    	    sum += result;   /*value of the polynomial for x value*/

    	    if(!(operator == '+' || operator == '-')) break;/* polynomial.txt EOF control*/
    	}
    	fprintf(fpr,"%.2lf \n",sum);
    }
    fclose(file);
    fclose(fp);
    fclose(fpr);
    
    return (0);
}
