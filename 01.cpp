#include <stdio.h>
//https://dev.to/mikkel250/pointers-const-void-and-arrays-28gc

int get_pointer();
void volatile_func_1();
void volatile_func_2();
	
int main(int argc, char *argv[]) {
    int num = 10;
	printf("Value of variable num is : %d \n" , num);
	printf("Address of variable num is : %p \n",&num);
	
	const int *p;
    int var  =10;
	int b = 10 ;
	int c= 15;
	p = &var;
	
	//*p = 6; this cant happen because is const , the value of a p  can´t get changed through the pointer.
	
	//define the pointer as const , this is like read only 
	printf("Value of variable var is: %d \n", var);
	printf("\nValue of variable var is: %d", *p);
	printf("\nAddress of variable var is: %p", &var);
	printf("\nAddress of variable var is: %p", p);
	printf("\nAddress of pointer p is: %p", &p);
	
	// The value of the direction can be change but the value no
	p = &b;
	printf("\nAddress of variable var is: %p", p);
	printf("\nAddress of pointer p is: %p", &p);
	//
	int *const bar = &c;
	*bar = 16; // the value of c can be changed through the pointer. , but the direcction cant change.
	//bar = &var; // this cant happen 
	

	return 0;
}

/*
Volatile means that the value is subject to sudden change (possibly from outside the program).
*/
int get_pointer()
{
  unsigned int const volatile *status_reg; // with const only we read but cant modify the value 
  unsigned char const volatile *recv_reg;
  static const int value =5 ; // this is only read value cant be modified.
  
  while (*status_reg) {
	  // do nothing but spin
  }
  
  return *recv_reg;
}

void volatile_func_1()
{
	const int local = 10;
	int *ptr = (int*)&local;
	
	printf("Initial value of local : %d \n", local);
	*ptr = 100;
	printf("Modified value of local: %d \n", local);
}


void volatile_func_2()
{
	const volatile int local = 10;
	int *ptr = (int*)&local;
	
	printf("Initial value of local : %d \n", local);
	*ptr = 100;
	printf("Modified value of local: %d \n", local);
}

