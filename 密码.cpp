#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ReplacePassword()
{
	char password[50]; //��Ҫ���ܵ����� 
	int i;//ѭ������ 
	int offset;
	printf("���������룺");
	scanf("%s", password);
	for(i = 0; i < strlen(password); i++)//���������ҽ�����λ��λ���� 
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
	printf("������ܺ������Ϊ��%s\n", password);
	for(i = 0; i < strlen(password); i++)//�����ܺ�����븴ԭ 
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
	printf("���ܺ��ԭ����Ϊ��%s\n", password);
	return 0;
}

int ReplacementPassword()
{
	char password[10][6]={0}, password_copy[10][6];//��Ҫ���ܵ����� 
	char key[10], key_copy[10];//��Կ
	int key_num[10];//��Կ��������û�˳�� 
	char temp;//�м���� 
	printf("���������룺");
	scanf("%s", password);
	printf("��������Կ��������ĸ��ÿ����ĸ��ͬ����");
	scanf("%s", key);
	int i, j, k;//ѭ������
	strcpy(key_copy,key);
	memcpy(password_copy, password, sizeof(password));
	//����Կð������ 
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
	//��Կ˳�� 
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
	/*�����Կ˳�� 
	for(i = 0; i < strlen(key); i++)
	{
		printf("%d", key_num[i]);
	}
	printf("\n");
	*/
	//���� 
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

	printf("�õ��������ǣ�"); 
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
	
	//����
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
	printf("���ܵ����ģ��������ǣ�%s\n", password);
	
	
}



int main()
{
	int a;//ѡ�����
	printf("��ѡ����ܷ�ʽ��\n1���������ܣ�\n2�û��������\n");
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
		printf("�����������������\n");
		goto compare;
	}
	return 0;
}