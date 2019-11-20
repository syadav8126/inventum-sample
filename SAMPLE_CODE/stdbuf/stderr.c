#include <stdio.h>
void just_print(){
	fprintf(stderr,"First line in function with new line \n");
	fprintf(stderr,"Second line in function without new line");
	fprintf(stderr,"Third  line in function\n");

}


int main(){
	fprintf(stderr,"First line with new line\n");
	just_print();
	fprintf(stderr,"Second line without new line");
	just_print();
	fprintf(stderr,"Third line with new line\n");
	just_print();
}
