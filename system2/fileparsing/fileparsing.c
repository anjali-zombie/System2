/*
 * file parsing 
 * Code which should display all First names where the Degree is MSc followed by Gender to be 'F' and the Year as 2024
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp =fopen("data.csv","r");
	if(fp ==NULL)
	{
		printf("error!");
		exit(0);
	}
	else 
	{
		char line[1000];
		fgets(line,1000,fp);
		printf("students with degree as MSC, gender as F and  year 2024:\n");
		/*
		 * fgets to read each line from the CSV file and strtok to parse it.
		 * The strtok function extracts fields from the CSV line and splits the full name to get the first name.
		 */
		while(fgets(line,1000,fp))
		{
			char *rno = strtok(line,",");
			char *name = strtok(NULL,",");
			char *gender = strtok(NULL,",");
			char *year = strtok(NULL,",");
			char *degree = strtok(NULL,",");

			char *fname = strtok(name," ");


			/*
			 *  Remove the newline if it's present
			 */
   		 	degree[strcspn(degree, "\n")] = 0;// count no of char till occurance of second string first char in first string
   		 	gender[strcspn(gender, "\n")] = 0;
   		 	year[strcspn(year, "\n")] = 0;

			/*
			 * filtering  students based on the criteria (MSc, F, 2024).
			 */
			if (strcmp(degree,"MSc") == 0 && strcmp(gender,"F")==0 && (atoi(year)==2024))      //strcmp(year,"2024")==0)
			{
				printf("%s\n",fname);
			}
			

		}
	}
	fclose(fp);
	return 0;

}

