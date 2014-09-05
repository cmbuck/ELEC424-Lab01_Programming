#include<stdio.h>
#include<stdlib.h>


//#define CHECK if(a > 128){system("clear");}
void CHECK( unsigned char a){
	if(a > 128){
		system("clear");
		char *x = "error or not?";
		x[0] = 'E';
	}
}
/* this program does simple operation on an input 8-bit integer
 * on specific condition, the screen will be cleared*/
unsigned char operation(unsigned char a){
	/*right shift one bit*/
	a = a >> 1;
	/*mask a by the lowest four bits*/
	a = a & 0x0f;
	/*left shift four bits*/
	a = a << 4;
	CHECK(a);
	return a;
}


int main(int args, char ** argv){

	if(args != 2){
		printf("operation usage: %s <integer>\n",argv[0]);
		perror("inputs are not correct");
		return -1;
	}
	/*sanity check*/
	if(atoi(argv[1]) < 0 || atoi(argv[1]) > 255){
		printf("input integer is not allowed...\nthink about why your input value is not allowed ???\n");
		return 0;
	}
	unsigned char a = (unsigned char)atoi(argv[1]);
	printf("result of operation on value %d is %d \n", a, operation(a));
	return 0;
}
