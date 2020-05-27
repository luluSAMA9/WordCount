#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char file[128]; 
	int word = 0;          // ������
	int	character = 0;     // �ַ���
	int flag = 0;          // �ж�����
	FILE *f;
	// ������֤
	if (argc != 3)          
	{
		printf("parameter error!");
		exit(-1);
	}
	// �ļ���֤
	if ((f = fopen(argv[2], "r")) == NULL)
	{
		printf("file error!");
		exit(-1);
	}
	// ��ȡ�ļ��ַ�
	while (fscanf(f, "%c", &file[character]) != EOF)
	{
		if (file[character] == ',' || file[character] == ' ') {
			flag = 0;
		}
		else
		{
			if (flag == 0)
			{
				word++;
				flag = 1;
			}
			else
			{
				flag = 1;
			}
		}
		character++;
	}
	// ���������
	if (strcmp(argv[1], "-w") == 0)
	{
		printf("��������%d", word);
	}
	// ����ַ���
	else if (strcmp(argv[1], "-c") == 0)
	{
		printf("�ַ�����%d", character);
	}
	// ����
	else 
	{
		printf("error!");
	}
	return 0;
}
