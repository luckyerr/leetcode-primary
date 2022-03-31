#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{   char voco[26],vocr[26],key[50],content[100],output[100],vocn[26];
    int  ascii=97,i,count,k,j,length;
    for(i=0;i<26;i++)//按顺序输入字母
	{
		voco[i]=ascii;
		ascii++;
	}
	ascii=97+25;
	for(i=0;i<26;i++)//反顺序输入字母
	{
		vocr[i]=ascii;
		ascii--;
	}
	gets(key);//得到密钥
	FILE *fp=fopen("encrypt.txt","r");
	if(fp==NULL)//判断是否打开
		{
			exit(1);
		}
	for(i=0;i<100;i++){
		fscanf(fp,"%c",&content[i]);
	}//输入内容
	printf("%c",content);
	fclose(fp);
	count=strlen(key);
	for(i=0;i<count-1;i++)//删除同样的字母构造新的密钥
		{
		for(j=i+1;j<count;j++)//与其后面的项逐项比较
		{
				if(key[j]==key[i])
		{
					for(k=j;k<count-1;k++)//每项向前移动一位
					{
						key[k]=key[k+1];
					}
					count--;//数组长度-1
					i--;//从i-1位重新开始比较
				}
			}
		}
	for(i=0;i<count;i++)//去掉字母表中重复的字母
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
	for(i=count;i<26;i++)//将字母表倒序放入处理后的密钥
		{
		vocn[i]=vocr[i-count];
		}//vocn	为新的密钥
	length=strlen(content);
	for(i=0;i<length;i++)//与新字母表比较
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











 
