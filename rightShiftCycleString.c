// daniel lankin 
#include <stdio.h>
#include <string.h>
/* input one two three four, output => four one two three */
void rightShiftCycleString(char* str);
int main()
{
    char str[50];
    printf("enter string\n");
    gets(str);
    rightShiftCycleString(str);
    puts(str);
    return 0;
}
void rightShiftCycleString(char* str)
{
    int i, j, k;
    char* tmp;
    k = j = strlen(str);
    --k;//k is the last char of str
    tmp = (char*)malloc((j+1)*sizeof(char));//j+1->\0+j
    tmp[j]='\0';//end of string
    --j;
    i = j;
    while (i >= 0 && str[i] != ' ')
    {//backward until the first char of last word
        --i;
    }
    if(i<0)
        return;
    while (str[i] == ' ')//run back all spaces
        --i;
    while (i >= 0)//copying the strings
    {
        tmp[j] = str[i];
        --j, --i;
    }
    tmp[j] = ' ';//need at least one space between the first and last word
    --j;
    while (j >= 0)//copying the last word
    {
        tmp[j] = str[k];
        --j, --k;
    }
    strcpy(str, tmp);//copy to origin
    free(tmp);
}