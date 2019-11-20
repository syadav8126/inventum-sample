#include <stdio.h>
#include <stdlib.h>
#define op_t unsigned long int
#define OPSIZ sizeof(op_t)
struct abc{
	int ab;
	int ac;
};
void *mem1(void * dstpp, int c, size_t len)
{
		long int dstp = (long int) dstpp;
		printf("dstpp:%p\n",dstpp);
		if (len >= 8)
		{
				printf("memset by c : %d\n",c);
				size_t xlen;
				unsigned long int  cccc;
				cccc = (unsigned char) c;
				printf("cccc1 is : %ld\n",cccc);
				cccc |= cccc << 8;
				printf("cccc2 is : %ld\n",cccc);
				cccc |= cccc << 16; 
				printf("cccc3 is : %ld\n",cccc);
				if (OPSIZ > 4){
						cccc |= (cccc << 16) << 16;
				printf("cccc4 is : %ld\n",cccc);
				}
				printf("dstp : %ld, dstp/OPSIZ is : %ld\n",dstp,dstp%OPSIZ);
				while (dstp % OPSIZ != 0)
				{
						((unsigned char  *) dstp)[0] = c;
						dstp += 1;
						len -= 1;
				}
				xlen = len / (OPSIZ * 8);
				printf("xlen : %d\n",xlen);
				while (xlen > 0)
				{
						((op_t *) dstp)[0] = cccc;
						((op_t *) dstp)[1] = cccc;
						((op_t *) dstp)[2] = cccc;
						((op_t *) dstp)[3] = cccc;
						((op_t *) dstp)[4] = cccc;
						((op_t *) dstp)[5] = cccc;
						((op_t *) dstp)[6] = cccc;
						((op_t *) dstp)[7] = cccc;
						dstp += 8 * OPSIZ;
						xlen -= 1;
				}
				len %= OPSIZ * 8;
				xlen = len / OPSIZ;
				while (xlen > 0)
				{
						((op_t *) dstp)[0] = cccc;
						dstp += OPSIZ;
						xlen -= 1;
				}
				len %= OPSIZ;
		}
		while (len > 0)
		{
				((unsigned char *) dstp)[0] = c;
				printf("c in while loop : %d  len:: %ld \n",c,len);
				printf("dstp: %d\n",((unsigned char *)dstp)[0]);
				dstp += 1;
				len -= 1;
		}
		dstp = (long int) dstpp;

		printf("dstp is ::%ld\n",dstp);
		return dstpp;   
}
int main(){
		struct abc* p;
		p  = (struct abc *)malloc ( sizeof( struct abc ) );
		p->ab = 299;
		p->ac = 22;
		mem1(p,0,7);
		printf("p:%d\n",p->ab);
		return 0;
}
