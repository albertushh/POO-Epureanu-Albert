#include <iostream>
#include <errno.h>
#include <fstream>
using namespace std;

int main()
{
	int sum = 0, i = 0, res = 0;
	char s[100];
	FILE* filepoint;
	errno_t err;
	err = fopen_s(&filepoint, "hello.txt", "r");
	if (err != 0)
	{
		cout << "mai incearca " << err;
		return 0;
	}
	while (fgets(s, sizeof(s), filepoint))
	{
		res = 0; i = 0;
		while (s[i] != '\0')
		{
			res = res * 10 + (s[i] - '0');
			i++;
		}
		sum += res;
	}
	printf("%d", sum);

	fclose(filepoint);

	return 0;
}
