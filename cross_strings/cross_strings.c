#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//function declacration
char* i_th_word(char *sentence, int i);
int cross_strings(char *s1,char *s2);
//function declacration--------------------------------------------------
//main
int main ()
{
    char *s1,*s2;
    printf("please enter 2 strings to check\n");
    printf("1:");
    gets(s1);
    printf("\n2:");
    gets(s2);
    int result = cross_strings(s1,s2);
    printf(" %d= num of words that appear in the first string also appear in the second string", result);
    return 0;
}
//main--------------------------------------------------



//function implementation

/* returns index of beginning of i-th word in sentence */
char* i_th_word(char *sentence, int i)
{
	int pos = 1, count = 0,flag=0,j=0;
	char *subword = (char *)calloc(strlen(sentence), sizeof(char));

	while (count<i)
	{
		if (count == i - 1)
			flag = 1;
		if (flag && sentence[pos - 1]!=' ')
			subword[j++] = sentence[pos-1];
		if (sentence[pos] == '\0') break;
		pos++;
		if (sentence[pos - 1] == ' ' && sentence[pos] != ' ')
			count++;
	}

	subword[j] = '\0';
	subword = (char *)realloc(subword, strlen(subword) + 1);
	return subword;
}

int cross_strings(char *s1,char *s2)
{
	int i=0, j=0, k = 1, size=0;
	char *str1=s1;
	char *str2 = NULL;
	char *word = (char *)calloc(strlen(s1), sizeof(char));

	while (str1[i] != '\0')
	{
		if (str1[i] != ' ')
		{
			word[j] = str1[i];
			j++;
		}
		else
		{
			word[j] = '\0';
			while ((str2 = i_th_word(s2, k)) != NULL)
			{
				if (strlen(str2) == 0)
					break;
				if (strcmp(word, str2) == 0)
					size++;
				free(str2);
				k++;
			}
			k = 1;
			j = 0;
		}
		i++;
	}

	free(word);
	return size;
}
//function implementation--------------------------------------------------