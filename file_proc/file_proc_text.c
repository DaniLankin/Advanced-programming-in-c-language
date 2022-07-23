#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define NUM 7

void addItem(char*);
int UpdateItem(char*, char[], double);

void main()
{
	char fName[20] = "test.txt";

	addItem(fName);

	printf("command update %d\n", UpdateItem(fName, "06842151", 20.7));
	printf("command update %d\n", UpdateItem(fName, "330578795", 200.0));
	printf("command update %d\n", UpdateItem(fName, "30578786", 170.7));
}

int UpdateItem(char* fName, char* idClient, double addTotal)
{
	char id[10], name[31];
	double total;
	FILE* f = fopen(fName, "r+");
	if (!f)
	{
		printf("File not found!\n");
		return 0;
	}

	fscanf(f, "%9s%30s%lf", id, name, &total);
	while (!feof(f))
	{
		if (strcmp(idClient, id) == 0) // id equals idClient
		{
			total += addTotal;
			fseek(f, -8, SEEK_CUR); // 8 positions to the left to beginning of the double number
			fprintf(f, "%8.2lf\n", total);
			fclose(f);
			return 1;
		}
		fscanf(f, "%9s%30s%lf", id, name, &total);
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
	FILE* f = fopen(fName, "w");

	if (f)
	{
		for (i = 0; i < NUM; i++)
			fprintf(f, "%9s %30s %8.2lf\n", id[i], name[i], total[i]);
		fclose(f);
	}
}