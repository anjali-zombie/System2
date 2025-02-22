#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buffer[1000];
	char *data;
	FILE *file = fopen("student.csv","r");
//	fgets(buffer,sizeof(buffer),file);
	while(fgets(buffer ,sizeof(buffer),file))
	{
		buffer[strcspn(buffer,"\n")] = 0;
		char* roll_no = strtok(buffer,",");
		char* first_name = strtok(NULL," ");
		char* middle_name = strtok(NULL," ");
		char* last_name = strtok(NULL,",");
		char* gender = strtok(NULL,",");
		char* year = strtok(NULL,",");
		char* degree = strtok(NULL,",");	
		if (!roll_no || !first_name || !middle_name || !last_name || !gender || !year || !degree)		 {
			continue;
		}	
		if( strcmp(degree,"MSc")==0 && strcmp(gender,"F")==0 && strcmp(year,"2024")==0)
		{
			printf("%s\n",first_name);
		}
	}
	fclose(file);
	return 0;
}



	

