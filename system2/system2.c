#include<stdio.h>
#include<stdlib.h>



void ext(FILE* ptr)
{
	FILE * fptr = fopen("sysfile2.txt","w");
	char s;
	char * c;
	int i =0;
	while( (s=fgetc(ptr))!=EOF)
        {
//              putchar(s);

        // char s = fgetc(ptr);
		 
       		 if( s =='*' && fgetc(ptr)== '/')
       		 {
			 return;
       		 }
 		 putchar(s);
		 fputc( s, fptr);

		 
		 
        }

}
int main()
{
	FILE * fptr1 = fopen("error.c","r");
	FILE * fptr2 = fopen("sysfile2.txt","w");
	char s;

	while( (s=fgetc(fptr1))!=EOF)
	{
//		putchar(s);

	//	char s = fgetc(fptr1);
		if( s =='/' && fgetc(fptr1)== '*')
		{	
			 ext(fptr1);
		}
		
	}
	fclose(fptr1);
	fclose(fptr2);
}






