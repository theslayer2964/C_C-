#include <stdio.h>
#include <string.h>
void xuatchuoi(char s[]);

int main()
{
	char s[30];// = "Ngo Thuy Mien";
	printf("Nhap chuoi: ");
	gets(s);
	printf("Chuoi: ");
	puts(s);

	xuatchuoi(s);

	int vttu[10];
	int sotu = 0;
	vttu[0] = 0;
	sotu++;

	for (int i=0; i<strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			vttu[sotu] = i+1;
			sotu++;
		}
	}

	printf("\nMang vi tri bat dau: ");
	for (int i=0; i<sotu; i++)
	{
		printf("%4d", vttu[i]);
	}

	/////Mang do dai cac tu
	int dodai[10];
	int len_dodai=0;
	for (int i=0; i<sotu-1; i++)
	{
		dodai[i] = vttu[i+1] - vttu[i] - 1;
	}
	dodai[sotu-1] = strlen(s) - vttu[sotu-1];

	//Tim tu co vi tri max
	int vtmax = 0;
	for (int i=1; i<sotu; i++)
	{
		if (dodai[i] > dodai[vtmax])
			vtmax = i;
	}
	printf("\nVi tri max: %d", vtmax);

	//Xuat tu co do dai la dodai[vtmax]
	int dodaitu = dodai[vtmax];
	int vtbatdautu = vttu[vtmax];
	printf("\nTu dai nhat la: ");
	for (int i=vtbatdautu; i<vtbatdautu+dodaitu; i++)
	{
		printf("%c", s[i]);
	}

	printf("\n\n");
	return 0;
}

void xuatchuoi(char s[])
{
	printf("\n");
	for (int i=0; i<strlen(s); i++)
	{
		printf("\ns[%d] = %c", i, s[i]);
	}
}
