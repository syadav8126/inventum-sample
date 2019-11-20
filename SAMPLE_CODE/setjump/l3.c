#include <setjmp.h>
#include <stdio.h>
int proc_4(jmp_buf env, int i)
{
  printf("proc_4\n");
  if (i == 0) longjmp(env, 1);
  printf("proc_5: i=%d\n",i);
  return 14 % i;
}
int proc_3(jmp_buf env, int i, int j)
{
  printf("proc_3\n");
  return proc_4(env, i) + proc_4(env, j);
}
int proc_2(jmp_buf env, int i, int j, int k)
{
  printf("proc_2\n");
  return proc_3(env, i, k) + proc_3(env, j, k);
}
int proc_1(jmp_buf env, int i, int j, int k, int l)
{
  printf("proc_1\n");
  return proc_2(env, i, j, k+1);
}
int main(int argc, char **argv)
{
  jmp_buf env;
  int sj;
  int i, j, k, l;
  sj = setjmp(env);
  printf("here 1\n");
  if (sj != 0) {
    printf("Error -- bad value of i (%d), j (%d), k (%d), l (%d)\n", 
           i, j, k, l);
    exit(0);
  }
  printf("here 2\n");
  i = atoi(argv[1]);
  j = atoi(argv[2]);
  k = atoi(argv[3]);
  l = atoi(argv[4]);
  printf("proc_1(%d, %d, %d, %d) = %d\n", i, j, k, l, proc_1(env, i, j, k, l));
}
