#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ReplacePassword()
{
	char password[50]; //需要加密的密码 
	int i;//循环变量 
	int offset;
	printf("请输入密码：");
	scanf("%s", password);
	for(i = 0; i < strlen(password); i++)//将密码向右进行三位移位加密 
	{
		if(password[i]=='x'||password[i]=='y'||password[i]=='z'||
		   password[i]=='X'||password[i]=='Y'||password[i]=='Z')
		{
			password[i] = password[i] - 23;
		} 
		else
		{
			password[i] = password[i] + 3;
		}
	}
	printf("替代加密后的密码为：%s\n", password);
	for(i = 0; i < strlen(password); i++)//将加密后的密码复原 
	{
		if(password[i]=='a'||password[i]=='b'||password[i]=='c'||
		   password[i]=='A'||password[i]=='B'||password[i]=='C')
		{
			password[i] = password[i] + 23;
		} 
		else
		{
			password[i] = password[i] - 3;
		}
	}
	printf("解密后的原密码为：%s\n", password);
	return 0;
}

int ReplacementPassword()
{
	char password[10][6]={0}, password_copy[10][6];//需要加密的密码 
	char key[10], key_copy[10];//密钥
	int key_num[10];//密钥对密码的置换顺序 
	char temp;//中间变量 
	printf("请输入密码：");
	scanf("%s", password);
	printf("请输入密钥（六个字母，每个字母不同）：");
	scanf("%s", key);
	int i, j, k;//循环变量
	strcpy(key_copy,key);
	memcpy(password_copy, password, sizeof(password));
	//将密钥冒泡排序 
	for(i = 0; i < strlen(key)-1; i++)
	{
		for(j = 0; j < strlen(key)-1; j++)
		{
			if(key[j] > key[j+1])
			{
				temp = key[j];
				key[j] = key[j+1];
				key[j+1] = temp;
			}
		}
	} 
	//密钥顺序 
	for(i = 0; i < strlen(key); i++)
	{
		for(j = 0; j < strlen(key); j++)
		{
			if(key[i] == key_copy[j])
			{
				key_num[j] = i+1;
			}
		}
	}
	/*输出密钥顺序 
	for(i = 0; i < strlen(key); i++)
	{
		printf("%d", key_num[i]);
	}
	printf("\n");
	*/
	//加密 
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 6; j++)
		{
			if(password[i][j] != 0)
			{
				for(k = 0; k < 6; k++)
				{
					if(key_num[k] == j+1)
					{
						password[i][j] = password_copy[i][k];
					}
				}
			}
		}
	}

	printf("得到的密文是："); 
	for(j = 0; j < 6; j++)
	{
		for(i = 0; i < 10; i++)
		{
			if(password[i][j] != 0)
			{
				printf("%c", password[i][j]);
			}
		}
	}
	printf("\n");
	
	//解密
	 for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 6; j++)
		{
			if(password[i][j] != 0)
			{
				for(k = 0; k < 6; k++)
				{
					if(key_num[k] == j+1)
					{
						password[i][j] = password_copy[i][key_num[k]-1];
					}
				}
			}
		}
	}
	printf("解密的密文，即明文是：%s\n", password);
	
	
}



int main()
{
	int a;//选择变量
	printf("请选择加密方式：\n1替代密码加密；\n2置换密码加密\n");
	compare:
	scanf("%d", &a);
	if(a == 1)
	{
		ReplacePassword();
	} 
	else if(a == 2)
	{
		ReplacementPassword();
	}
	else
	{
		printf("输入错误，请重新输入\n");
		goto compare;
	}
	return 0;
}