// C Program for header file of a shared stack 
#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 
#include <sys/sem.h> 
#include <sys/shm.h> 
#include <sys/types.h> 
#include <unistd.h> 

#ifndef _MYLIB_H_ 
#define _MYLIB_H_ 

// structure for stack descriptor 
struct stack_desc { 
	key_t stkey; // key for the stack 
	int data_size; // integer or character 
	int stack_size; 
	int top; 
	int ele_no; 
	bool free; // stack is used by any process ot not 
}; 
typedef struct stack_desc stack_desc; 

extern void shstackget(key_t mykey, int data_size, int stack_size); 
extern void shstackpush(key_t key, int ele); 
extern void shstackpop(key_t key); 
extern void shstackrm(key_t key); 

#endif 

