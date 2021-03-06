#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct address
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct database
{
	struct address rows[MAX_ROWS];
};

struct connection
{
	FILE *file;
	struct database *db;
};

void database_close(struct connection *conn)
{
	if(conn)
	{
		if(conn->file)
		{
			fclose(conn->file);
		}
		if(conn->db)
		{
			free(conn->db);
		}
		free(conn);
	}
}

void die(const char *message, struct connection *conn)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR: %s\n", message);
	}
	if(conn)
	{
		database_close(conn);
		printf("Free:X\n");
	}
	exit(1);
}

void address_print(struct address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void database_load(struct connection *conn)
{
	int rc = fread(conn->db, sizeof(struct database), 1, conn->file);
	if(rc != 1)
	{
		die("Failed to load database.", conn);
	}
}

struct connection *database_open(const char *filename, char mode)
{
	struct connection *conn = malloc(sizeof(struct connection));
	if(!conn)
	{
		die("Memory error", conn);
	}
	
	conn->db = malloc(sizeof(struct database));
	if(!conn->db)
	{
		die("Memory error", conn);
	}	
	if(mode == 'c')
	{
		conn->file = fopen(filename, "w");
	}
	else
	{
		conn->file = fopen(filename, "r+");
		if(conn->file)
		{
			database_load(conn);
		}
	}

	if(!conn->file)
	{
		die("Failed to open the file", conn);
	}

	return conn;

}

void database_write(struct connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct database), 1, conn->file);
	if(rc != 1)
	{
		die("Failed to write database.", conn);
	}

	rc = fflush(conn->file);
	if(rc == -1)
	{
		die("Cannot flush database", conn);
	}
}

void database_create(struct connection *conn)
{
	int i = 0;

	for(i = 0; i < MAX_ROWS; i++)
	{
		struct address addr = {.id = i, .set = 0 };
		conn->db->rows[i] = addr;
	}
}

void database_set(struct connection *conn, int id, const char *name, const char *email)
{
	struct address *addr = &conn->db->rows[id];
	if(addr->set)
	{
		die("Already set, delete it first", conn);
	}
	
	addr->set = 1;

	char *res = strncpy(addr->name, name, MAX_DATA);
	if(!res)
	{
		die("Name copy failed", conn);
	}

	res = strncpy(addr->email, email, MAX_DATA);
	if(!res)
	{
		die("Email copy failed", conn);
	}
}

void database_get(struct connection *conn, int id)
{
	struct address *addr = &conn->db->rows[id];
	
	if(addr->set)
	{
		address_print(addr);
	}
	else
	{
		die("ID is not set", conn);
	}
}

void database_delete(struct connection *conn, int id)
{
	struct address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void database_list(struct connection *conn)
{
	int i = 0;
	struct database *db = conn->db;

	for(i=0; i < MAX_ROWS; i++)
	{
		struct address *cur = &db->rows[i];

		if(cur->set)
		{
			address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	
	if(argc < 3)
	{
		die("USAGE: ex17 <dbfile> <action> [action params]", NULL);
	}

	char *filename = argv[1];
	char action = argv[2][0];
	struct connection *conn = database_open(filename, action);
	int id = 0;

	if(argc > 3)
	{
		id = atoi(argv[3]);
	}
	if(id >= MAX_ROWS)
	{
		die("There's not that many records.", conn);
	}

	switch (action)
	{
		case 'c':
			database_create(conn);
			database_write(conn);
			break;
		
		case 'g':
			if(argc != 4)
			{
				die("Need id, name, email to set", conn);
			}
			database_get(conn, id);
			break;
	
		case 's':
			if(argc != 6)
			{
				die("Need id, name, email to set", conn);	
			}
			database_set(conn, id, argv[4], argv[5]);
			database_write(conn);
			break;

		case 'd':
			if(argc != 4)
			{
				die("Need id to delete", conn);
			}
			database_delete(conn, id);
			database_write(conn);
			break;
	
		case 'f':				

		case 'l':
			database_list(conn);
			break;

		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list", conn);
	}

	database_close(conn);
	return 0;

}
