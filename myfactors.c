#include "myfactors.h"

/**
 * main - Entry point
 * @argc: Number of program arguments
 * @argv: List or program argmuments
 *
 * Return: EXIT_SUCCESS on success
 * EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *pfile = NULL;
	char numstring[128], len;
	unsigned long int num, iter;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pfile = fopen(argv[1], "r");
	if (!pfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	memset(numstring, 0, sizeof(numstring));
	while (fgets(numstring, sizeof(numstring), pfile))
	{
		len = strlen(numstring);
		if (len < 19)
		{
			num = atol(numstring);
			for (iter = 2;
			     iter < (unsigned long int) (num / 2) + 1;
			     iter++)
			{
				if (num % iter == 0)
				{
					printf("%lu=%lu*%lu\n", num,
					       (num / iter), iter);
					break;
				}
			}
		}
		else
		{
			numstring[len - 1] = '\0';
			factor_bignum(numstring);
		}

		memset(numstring, 0, sizeof(numstring));
	}
	exit(EXIT_SUCCESS);
}

/**
 * factor_bignum - Find two factor of a very large number
 * @numsring: Very large number in form of string
 *
 * Return: Void (Nothing)
 */
void factor_bignum(const char *numstring)
{
	unsigned long int dvdend, iter;
	char endval[128], check;
	unsigned char index, ind, len = strlen(numstring);

	for (iter = 2; (unsigned long int) pow(10, 18); iter++)
	{
		index = 0;
		ind = 0;
		dvdend = 0;
		check = 0;
		memset(endval, 0, sizeof(endval));
		while (index < len)
		{
			dvdend *= 10;
			dvdend += (numstring[index] - '0');
			if (dvdend / iter)
				check++;
			endval[ind] = '0' + (dvdend / iter);
			dvdend %= iter;
			if (check)
				ind++;
			index++;
		}
		if (!dvdend)
		{
			printf("%s=%s*%lu\n", numstring, endval, iter);
			break;
		}
	}
	if (dvdend)
		printf("%s has no factor\n", numstring);
}
