#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{   char voco[26],vocr[26],key[50],content[100],output[100],vocn[26];
    int  ascii=97,i,count,k,j,length;
    for(i=0;i<26;i++)//��˳��������ĸ
	{
		voco[i]=ascii;
		ascii++;
	}
	ascii=97+25;
	for(i=0;i<26;i++)//��˳��������ĸ
	{
		vocr[i]=ascii;
		ascii--;
	}
	gets(key);//�õ���Կ
	FILE *fp=fopen("encrypt.txt","r");
	if(fp==NULL)//�ж��Ƿ��
		{
			exit(1);
		}
	for(i=0;i<100;i++){
		fscanf(fp,"%c",&content[i]);
	}//��������
	printf("%c",content);
	fclose(fp);
	count=strlen(key);
	for(i=0;i<count-1;i++)//ɾ��ͬ������ĸ�����µ���Կ
		{
		for(j=i+1;j<count;j++)//��������������Ƚ�
		{
				if(key[j]==key[i])
		{
					for(k=j;k<count-1;k++)//ÿ����ǰ�ƶ�һλ
					{
						key[k]=key[k+1];
					}
					count--;//���鳤��-1
					i--;//��i-1λ���¿�ʼ�Ƚ�
				}
			}
		}
	for(i=0;i<count;i++)//ȥ����ĸ�����ظ�����ĸ
		{
		for(j=0;j<26;j++)
		{
			if(vocr[j]==key[i])
				{
					for(k=j;k<26;k++)
					{
						vocr[k]=vocr[k+1];
					}
				}
			}
		}
	for(i=count;i<26;i++)//����ĸ������봦������Կ
		{
		vocn[i]=vocr[i-count];
		}//vocn	Ϊ�µ���Կ
	length=strlen(content);
	for(i=0;i<length;i++)//������ĸ��Ƚ�
		{   if(content[i]<97||content[i]>122)
			{
				output[i]=content[i];
				continue;
			}
			else
			{
				for(j=0;j<26;j++)
				{
					if(content[i]==voco[j])
					{
						output[i]=vocn[j];
					}
				}
			}
		}
	fp=fopen("output.txt","w");
		for(i=0;i<length;i++)
		{
			fprintf(fp,"%c",output[i]);
		}
		fclose(fp);
	return 0;
	
	
}











 
