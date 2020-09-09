/*******************************************************************/
/* AUTRHOR	:	Itsarawut Saengsanan    	                       */
/* ID		:	1-60-07-0144-3	                                   */
/* SECTION	:	1451	                                           */
/* Std. No. :	16	                                               */
/* COURSE	:	CS310 Computer Programming                         */
/* INSTRUCTOR   : A.Sirinthorn Cheyasak                            */
/* TUTOR	:	A.Sirinthorn Cheyasak                              */
/* DATE    	:	October 24, 2017	                               */
/* LAB NUMBER   : 9	                                               */
/* DESCRIPTION  : This program was made for learning about fprintf */
/*				  , fscanf , while-loop , Text_File , fgets ,fopen */
/*       		  , fclose , FILE                                  */
/*******************************************************************/
#include<stdio.h>
int main ()
{
	char code[10],list,name[30];
	int price,amount,listA=0,listB=0;
	FILE *Store = fopen("Store.txt","r");
	FILE *itemA = fopen("itemA.txt","w");
	FILE *itemB = fopen("itemB.txt","w");
	fprintf(itemA,"List of item A\n"); fprintf(itemA,"===================\n");
	fprintf(itemB,"List of item B\n"); fprintf(itemB,"===================\n");
	fscanf(Store,"%s",&code);
	fgets(name,30,Store);
	fscanf(Store,"%d %d  %c",&price,&amount,&list);
	
	while(!feof(Store))
	{
		
		if(list == 'A' )
		{
			fprintf(itemA,"%s %s %d %d %c\n",code,name,price,amount,list);
			listA++;
		}
		else if (list == 'B')
		{
			fprintf(itemB,"%s %s %d %d %c\n",code,name,price,amount,list);
			listB++;	
		}
		fscanf(Store,"%s",&code);
		fgets(name,30,Store);
		fscanf(Store,"%d %d  %c",&price,&amount,&list);
	}
	
	fprintf(itemB,"-----\n"); fprintf(itemB,"Total list = %d",listB);
	fprintf(itemA,"-----\n"); fprintf(itemA,"Total list = %d",listA);
	fclose(Store);
	fclose(itemA);
	fclose(itemB);
}
