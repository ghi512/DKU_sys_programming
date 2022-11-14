#include <stdio.h>
int a = 10;

int func1(int arg1) {
	printf("func1에서의 arg1 = %d\n", arg1);
}
int main() {
	int *pa;
    int (*func_ptr)(int);
    
    pa = &a;
    printf("a의 주소를 가리키는 포인터 pa = %p\n", pa);
    printf("포인터 pa안에 들어있는 값 *pa = %d\n", *pa);
    func1(3);
    
    func_ptr = func1;
    func_ptr(5);
    
    printf("종료\n");
	return 0;
}
