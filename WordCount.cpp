#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char file[128]; 
	int word = 0;          // 单词数
	int	character = 0;     // 字符数
	int flag = 0;          // 判断条件
	FILE *f;
	// 参数验证
	if (argc != 3)          
	{
		printf("parameter error!");
		exit(-1);
	}
	// 文件验证
	if ((f = fopen(argv[2], "r")) == NULL)
	{
		printf("file error!");
		exit(-1);
	}
	// 读取文件字符
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
	// 输出单词数
	if (strcmp(argv[1], "-w") == 0)
	{
		printf("单词数：%d", word);
	}
	// 输出字符数
	else if (strcmp(argv[1], "-c") == 0)
	{
		printf("字符数：%d", character);
	}
	// 出错
	else 
	{
		printf("error!");
	}
	return 0;
}
