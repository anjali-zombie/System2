#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char buffer[1000];
	char *data;
       	char *lasttoken=NULL;	//strtok will return pointer
	char *target = "Degree";
	printf("\n*******************************\n");
	printf("hello, world!\n");


	FILE *studentdatafile = fopen("student.csv","r");
	if(studentdatafile == NULL)
	{
		printf("error:could not open file\n");
		exit(-1);
	}
	printf("i was able to open the file\n");


	//read in the first line
	
	fgets(buffer, sizeof(buffer), studentdatafile);
	fgets(buffer , sizeof(buffer), studentdatafile);
	printf("%s\n",buffer);
	// remove the  newline chracter if present
	
	size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
	}
	//tokenize the data
	data = strtok(buffer ,",");
	printf("%s",data);

	while(data !=NULL)
	{
		lasttoken = data;
		data = strtok(NULL,",");
		
	}

	if(lasttoken =="MSc")
	{
		while(fgets(buffer , sizeof(buffer),studentdatafile))
		{
			data =strtok(buffer,",");
		}
	}

	return 0;
}



