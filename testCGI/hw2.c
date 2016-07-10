#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>


main (int argc, char **argv, char **envp)
{
	char *qptr, sep;
	header("text/html");
	start_page("C programing traning");
	printf("<p>They clicked on our form");

	if (qptr = getenv("QUERY_STRING"))
	{
		char buffer[256];
		char *token;
		char firstname[80], lastname[80], nickname[80];
		strncpy(buffer,qptr,255);

		token = strtok(buffer,"&");
		sscanf(token,"firstname=%s",firstname);
		printf("<p>The firstname entered was %s", firstname);

		token = strtok(NULL,"&");
		sscanf(token,"lastname=%s",lastname);
		printf("<p>The lastname entered was %s", lastname);

		token = strtok(NULL,"&");
		sscanf(token,"nickname=%s",nickname);
		printf("<p>The nickname entered was %s", nickname);
	}
	
	else
	{
		printf("<p>Opps. We didn't get a QUERY_STRING");
	}

	end_page();
}

header(char *MIME_Type)
{
	printf("Content-type:%s\n\n", MIME_Type);
	return 0;
}

start_page(char *Title)
{
	printf("<html>");
	printf("<head>");

	printf("<title>%s</title>", Title);

	printf("</head>");
	printf("<body>");

	return 0;
}

end_page()
{
	printf("</body>");
	printf("</html>");
	return 0;
}
