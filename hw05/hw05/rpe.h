#pragma once
// обратная польская запись
// дано ( 8 + 2 * 5 ) / ( 1 + 3 * 2 — 4 )
// на выходе - 8 2 5 * + 1 3 2 * + 4 — /

#include "stack.h"
#include <stdbool.h>

int prior(char v)
{
	switch (v) {
		case '(': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 3;
		default: return 0;
	}
}

bool is_op(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_digit(char c)
{
	return c >= '0' && c <= '9';
}

void rpe(char *a, char *out)
{
	TStack st01;
	st01.size = 0;
	st01.maxsize = 100;

	int i = 0, j = 0;
	for (; a[i] != '\0'; ++i) {
		if (is_digit(a[i]))
		{
			out[j] = a[i];
			++j;
		}
		else {
			if (j != 0 && out[j - 1] >= '0' && out[j - 1] <= '9' || (j != 0 &&
					(out[j - 1] == '-' || out[j - 1] == '+' ||
					 out[j - 1] == '/' || out[j - 1] == '*'))) {
				out[j] = ' ';
				++j;
			}
			if (is_op(a[i])) {
				if (stkEmpty(&st01) || prior(stkTop(&st01)) < prior(a[i])) {
					stkPush(a[i], &st01);
				}
				else {
					while (!stkEmpty(&st01) && (prior(stkTop(&st01)) >= prior(a[i]))) {
						out[j++] = stkTop(&st01);
						stkPop(&st01);
					}
					stkPush(a[i], &st01);
				}
			}
			else {
				if (a[i] == '(') {
					stkPush(a[i], &st01);
				}
				else {
					if (a[i] == ')') {
						if (stkEmpty(&st01) || stkTop(&st01) == '(') {
							printf("Wrong character. Exit.\n");
							exit(-1);
						}
						else {
							while (stkTop(&st01) != '(') {
								out[j] = stkTop(&st01);
								stkPop(&st01);
								j++;
							}
						}
						stkPop(&st01);
					}
				}
			}
		}
	}
	while (!stkEmpty(&st01)) {
		if (stkTop(&st01) == '(')
		{
			printf("Wrong character. Exit.\n");
			exit(-1);
		}
		else {
			out[j] = stkTop(&st01);
			stkPop(&st01);
			j++;
		}
	}
	out[j++] = '\0';
}

/*int rpeCalc(char *out)
{
	int j = 0, c = 0, r1 = 0, r2 = 0;
	TStack st01;
	st01.maxsize = 100;
	//Stack st02;
	char num[16];
	char* pEnd = NULL;

	while (out[j] != '\0') {
		if (out[j] == '_') {
			++j;
			continue;
		}
		if (out[j] >= '0' && out[j] <= '9') 	{
			long iNum = strtol(&out[j], &pEnd, 10);
			stkPush(iNum, &st01);
			j += pEnd - &out[j];
		}
		else {
			if (is_op(out[j])) {
				r1 = stkTop(&st01); 
				stkPop(&st01);
				r2 = stkTop(&st01); 
				stkPop(&st01);
				switch (out[j]) 	{
					//case '+': stkPush(r2 + r1); break;
					//case '-': stkPush(r2 - r1); break;
					//case '*': stkPush(r2*r1); break;
					//case '/': stkPush(r2 / r1); break;
				}
			}
			++j;
		}
	}
	return (stkTop(&st01));
}*/