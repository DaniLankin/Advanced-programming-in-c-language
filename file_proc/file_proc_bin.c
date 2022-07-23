#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define NUM 7

/* clientData structure definition */
typedef struct clientData {
	char id[10];
	char name[31];
	double total;
} clientData;

void addItem(char*);
int UpdateItem(char*, char[], double);
void Display(char*);

void main()
{
	char fName[20] = "test_bin.dat";

	addItem(fName);

	printf("command update %d\n", UpdateItem(fName, "06842151", 20.7));
	printf("command update %d\n", UpdateItem(fName, "330578795", 200.0));
	printf("command update %d\n", UpdateItem(fName, "30578786", 170.7));

	Display(fName);
}

int UpdateItem(char* fName, char* idClient, double addTotal)
{
	clientData client;
	FILE* f = fopen(fName, "rb+");
	if (!f)
	{
		printf("File not found!\n");
		return 0;
	}

	fread(&client, sizeof(clientData), 1, f);
	while (!feof(f))
	{
		if (strcmp(client.id, idClient) == 0) // id equals idClient
		{
			client.total += addTotal;
			fseek(f, -(int)sizeof(clientData), SEEK_CUR); // 1 record to the left to beginning of the record to be updated
			fwrite(&client, sizeof(clientData), 1, f);
			fclose(f);
			return 1;
		}
		fread(&client, sizeof(clientData), 1, f);
	}
	fclose(f);
	return 0;
}

/* Auxiliary function: creating the source file*/
void addItem(char* fName)
{
	char* id[NUM] = { "0123456", "0324354", "30215468", "31205431", "06842151", "20051546", "330578795" };
	char* name[NUM] = { "Yoal", "Moshe", "Gila", "Pinhas", "Aelet", "Dina", "Miriam" };
	double total[NUM] = { 28.6, 31.8, 127, 684.7, 98.5, 560.1, 800 };
	int i;
	clientData client;
	FILE* f = fopen(fName, "wb");

	if (f)
	{
		for (i = 0; i < NUM; i++)
		{
			strcpy(client.id, id[i]);
			strcpy(client.name, name[i]);
			client.total = total[i];
			fwrite(&client, sizeof(clientData), 1, f);
		}
		fclose(f);
	}
}

/* Auxiliary function: displaying the updated file*/
void Display(char* fName)
{
	clientData client;
	FILE* f = fopen(fName, "rb");
	if (f)
	{
		printf("\n");
		fread(&client, sizeof(clientData), 1, f);
		while (!feof(f))
		{
			printf("%9s %30s %8.2lf\n", client.id, client.name, client.total);
			fread(&client, sizeof(clientData), 1, f);
		}
		fclose(f);
	}
}