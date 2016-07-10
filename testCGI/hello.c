#include <stdio.h>

main ()
{
	header("text/html");

	start_page("TAto Programing in functions");

	printf("Hello Tato");

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
