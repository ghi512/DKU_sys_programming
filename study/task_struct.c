#include <stdio.h>
#include <stdlib.h>

int glob1, glob2;
int func2() {
	int f2_local1, f2_local2;
	printf("func2함수 내 지역변수의 주소: \n\t%p, \n\t%p\n", &f2_local1, &f2_local2);
}
int func1() {
	int f1_local1, f1_local2;
	printf("func1함수 내 지역변수의 주소: \n\t%p, \n\t%p\n", &f1_local1, &f1_local2);	
	func2();
}
int main(){
	int m_local1, m_local2;
	int *dynamic_addr;
	
	printf("main함수 내 지역변수의 주소 : \n\t%p, \n\t%p\n", &m_local1, &m_local2);
	func1();
	
	dynamic_addr = malloc(16);
	printf("동적할당 변수의 주소 : \n\t%p\n", dynamic_addr);
	printf("전역변수의 주소 : \n\t%p, \n\t%p\n", &glob1, &glob2);
	printf("함수들의 주소 : \n\t%p, \n\t%p, \n\t%p\n", main, func1, func2);

	return 0;
}
