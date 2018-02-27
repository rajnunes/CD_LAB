#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct symbol
{
	char name[100];
	char type[100];
	int id;
	char size[100];
}symbol;

int main()
{

	FILE *fp1, *fp2;
	symbol s[100];
	char file[100];
	printf("\nEnter Input File : ");
	scanf("%s",file);
	fp1 = fopen(file, "r");
	printf("Enter Output File : ");
	scanf("%s",file);
	printf("\n\n");
	fp2 = fopen(file, "w");

	if(fp1==NULL || fp2==NULL)
		{
			printf("File not found.\n");
			exit(0);
		}

	char c;
	char buf[10],sizebuf[10];
	int ctr,previd=-1;
	char used [20][20],usednum[20][20];
	int usedcur=0,usednumcur=0;
	char key [20][20]={"char","int","long","double","float","if","else","switch","case","for","while","break","return","FILE","struct","NULL","typedef","EOF"};
	char typesize[20][20]={"1","4","16","8","8","","","","","","","","","",""};
	int id[100];

	c = fgetc(fp1);

	while(c!=EOF)
	{
		int i=0,func=0,arr=0;
		buf[0]='\0';

		if(c==' '||c=='\t') 
			c=getc(fp1);

		else if(c=='#')
		{
			while(c!='\n')
				c=getc(fp1);
			c=getc(fp1);
		}

		else if(c=='\'')
		{
			c=getc(fp1);
			while(c!='\'')
				c=getc(fp1);
			c=getc(fp1);
		}

		else if(c=='\"')
		{
			c=getc(fp1);
			while(c!='\"')
				c=getc(fp1);
			c=getc(fp1);
		}

		else if(c=='\n')
		{
			fprintf(fp2, "\n");
			c=getc(fp1);
		}
		
		else if(c=='=')
		{
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='=')
			{
				buf[i++]=c;
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
				c=fgetc(fp1);
			}
			else
			{
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c=='+')
		{
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='+')
			{
				buf[i++]=c;
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
				c=fgetc(fp1);
			}
			else
			{
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c=='<'||c=='>')
		{
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='=')
			{
				buf[i++]=c;
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
			}
			else
			{
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c=='!')
		{
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='=')
			{
				buf[i++]=c;
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
				c=fgetc(fp1);
			}
			else
			{
				buf[i]='\0';
				fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c>='A'&&c<='Z'||c>='a'&&c<='z')
		{
			buf[i++]=c;
			c=fgetc(fp1);
			while(c>='A'&&c<='Z'||c>='a'&&c<='z'||c>='0'&&c<='9')
			{
				buf[i++]=c;
				c=fgetc(fp1);
			}
			if(c=='(')
				func=1;
			if(c=='[')
			{
				fprintf(fp2, "<%c> ", c);
				int s=0;
				arr=1;
				c=fgetc(fp1);
				while(c!=']')
				{
					sizebuf[s++]=c;
					c=fgetc(fp1);
				}
				sizebuf[s]='\0';
			}
			buf[i]='\0';
			int keyflag=0;
			for(int k=0;k<18;k++)
				if(strcmp(buf, key[k])==0)
				{
					keyflag=1;
					previd=k;
					break;
				}

			if(keyflag==1)
				fprintf(fp2, "<%s> ", buf);
			else
			{
				int usedflag=0;int pos=0;
				for(int k=0;k<usedcur;k++)
				{	if(strcmp(buf, used[k])==0)
					{
						usedflag=1;
						pos=k;
						break;
					}
				}
						

				if(usedflag==1)
					fprintf(fp2, "<id,%d>", pos+1);

				else
				{
					strcpy(used[usedcur], buf);
					strcpy(s[usedcur].name,buf);
					if( func==0 && arr==0 )
					{
						strcpy(s[usedcur].type,key[previd]);
						strcpy(s[usedcur].size,typesize[previd]);
					}
					else if( func==1 && arr==0 )
					{
						strcpy(s[usedcur].type,"FUNC");
						strcpy(s[usedcur].size,"");
					}
					else if( arr==1 && func==0 )
					{
						char temp[100];
						strcpy(temp,key[previd]);
						strcat(temp," array");
						int sz=atoi(sizebuf);
						int ts=atoi(typesize[previd]);
						sz=sz*ts;
						sprintf(sizebuf,"%d",sz);
						strcpy(s[usedcur].type,temp);
						strcpy(s[usedcur].size,sizebuf);
					}
					s[usedcur].id=usedcur;
					usedcur++;
					fprintf(fp2, "<id,%d> ", usedcur);
				}
			}
		}
		else if(c>='0'&&c<='9')
		{
			buf[i++]=c;
			c=fgetc(fp1);
			while(c>='0'&&c<='9')
			{
				buf[i++]=c;
				c=fgetc(fp1);
			}
			buf[i]='\0';
			int usedflag=0;int pos=0;
			for(int k=0;k<usedcur;k++)
			{	if(strcmp(buf, usednum[k])==0)
				{
					usedflag=1;
					pos=k;
					break;
				}
			}		

			if(usedflag==1)
				fprintf(fp2, "<%s,%d>",buf, pos+1);
			else
			{
				strcpy(usednum[usednumcur++], buf);
				fprintf(fp2, "<%s,%d> ",buf, usednumcur);
			}
		}
		
		else
		{	
			fprintf(fp2, "<%c> ", c);
			c=fgetc(fp1);
		}
	}
	for(int i=0;i<usedcur;i++)
	{
		printf("|Name : %-10s  |  ID : %-3d  |  Type : %-10s  |  Size : %-4s|\n",s[i].name,s[i].id,s[i].type,s[i].size);
	}
	printf("\n\n");
	fclose(fp1);
	fclose(fp2);
return(0);
}
