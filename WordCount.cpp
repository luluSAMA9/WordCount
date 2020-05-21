#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char way[3], file_name[50];	char file[128];	int word = 0, i = 0, flag = 0;	FILE *f;	scanf("%s", way);	scanf("%s", file_name);	if ((f = fopen(file_name, "r")) == NULL)	{		printf("error!");		exit(-1);	}	while (fscanf(f, "%c", &file[i]) != EOF)	{		if (file[i] == ',' || file[i] == ' ') {			flag = 0;		}		else		{			if (flag == 0)			{				word++;				flag = 1;			}			else			{				flag = 1;			}		}		i++;	}	if (way[1] == 'w') 	{		printf("µ¥´ÊÊý£º%d", word);	}	else if (way[1] == 'c') 	{		printf("×Ö·ûÊý£º%d", i);	}	else 	{		printf("error!");	}	return 0;
}