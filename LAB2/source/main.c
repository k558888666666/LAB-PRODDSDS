
#include <stdio.h>
#include <stdlib.h>

typedef struct _student
{
	int acctNum;
	char lastName[15];
	char fristName[10];
	double balance;
}Date;
int main()
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int cnt = 0;
	int err,err2,err3;
	Date client = { 0,"","",0.0 };
	err = fopen_s(&pRead, "C://Users/User/Desktop/credit.txt", "r");
	if (pRead == NULL)
	{
		return 0;
	}
	err2 = fopen_s(&pWrite, "C://Users/User/Desktop/credit_bin.txt", "wb");
	if (pWrite == NULL)
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf_s(pRead, "%d", &client.acctNum );
		fscanf_s(pRead, "%s", client.lastName,15);
		fscanf_s(pRead, "%s",  client.fristName,10);
		fscanf_s(pRead, "%lf", &client.balance);
		fwrite(&client, sizeof(Date), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.fristName, client.balance);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("以讀取ACSSLL\n\n");
	system("pause");
	printf("\n讀取二進位\n");
	if ((err3=fopen_s(&cfPtr,"C://Users/User/Desktop/credit_bin.txt","rb")) != 0 )
	{
		printf("File could not be open\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "acct", "last name", "Firstname","balence");
		cnt = fread(&client, sizeof(Date), 1, cfPtr);
		while (cnt>0)
		{
			printf("%-6d", client.acctNum);
			printf("%-16s",  client.lastName,7);
			printf("%-11s",  client.fristName,7);
			printf("%10.2f\n",  client.balance);
			cnt = fread(&client, sizeof(Date), 1, cfPtr);
		}
		fclose(cfPtr);
	}
	system("Pause");
	return 0;
}