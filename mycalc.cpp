#include <bits/stdc++.h>
using namespace std;

void help();                                 /* help information */
int check_number(const char* const number);  /* check number */
int get_num(const char* const number);       /* get operator     */
char get_op(const char* const op);           /* translate a char to a int number */
int my_calc(int num1, int num2, char op);    /* calculator */
void print(int result);

int main(int argc, char* argv[]){
	if(argc != 4){
		help();
		return 0;
	}
	int num1 = get_num(argv[1]);
	int num2 = get_num(argv[3]);
	char op = get_op(argv[2]);
	int result = my_calc(num1, num2, op);
	print(result);
	return 0;
}

/* print help information */
void help(){
	cout << "*****************************" << endl;
	cout << "**** ------------------- ****" << endl;
	cout << "**** hex number calc     ****" << endl;
	cout << "**** mycalc num1 op num2 ****" << endl;
	cout << "**** ------------------- ****" << endl;
	cout << "*****************************" << endl;
}

/* check number is valid? */
int check_number(const char* const number)
{
	int i;
	unsigned int len = strlen(number);
	if( len == 0 )
		return 0;
	int count = 0;
	for(i = 0; i < len; ++i){
		if( number[i] >= 'a' && number[i] <= 'f')
			count++;
		if( number[i] >= 'A' && number[i] <= 'F')
			count++;
		if( isdigit(number[i]) != 0)
			count++;
	}
	if( count < len )
		return 0;
	return 1;
}
/* resolve number */
int get_num(const char* const number)
{
	if( check_number(number) == 0 ) {
		exit(0);
	}
	unsigned int i, len;
	len = strlen(number);
	int ret = 0;
	for(i = 0; i < len; ++i){
		int digit = 0;
		if( number[i] >= 'a' && number[i] <= 'f' )
			digit = number[i] - 'a' + 10;
		if( number[i] >= 'A' && number[i] <= 'f' )
			digit = number[i] - 'A' + 10;
		if( number[i] >= '0' && number[i] <= '9' )
			digit = number[i] - '0';
		ret = ret*16 + digit;
	}
	return ret;
}

/* get operator */
char get_op(const char* const op)
{
	unsigned int len = strlen(op);
	assert(len == 1);
	char oper[] = { '+', '-', '*', '/', '%' };
	int i;
	int flag = 0;
	for(i = 0; i < strlen(oper); ++i)
		if( op[0] == oper[i] ){
			flag = 1;
			break;
		}	
	if( flag == 0 ){
		cout << "operator is invalid" << endl;
		return '=';
	}	
	return op[0];
}

int my_calc(int num1, int num2, char op)
{
	int ret;
	switch(op){
		case '+':
			ret = num1 + num2;
			break;
		case '-':
			ret = num1 - num2;
			break;
		case '*':
			ret = num1 * num2;
			break;
		case '/':
			ret = num1 / num2;
			break;
		case '%':
			ret = num1 % num2;
			break;
		default:
			ret = 0;
	}
	return ret;
}
void print(int result)
{
	cout << "   0x";
	cout << hex << result;
	cout << "    ";
}
