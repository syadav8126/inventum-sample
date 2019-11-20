#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/ether.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

void pcap_dump(u_char *pd, const struct pcap_pkthdr *pkthdr,const  u_char *packet);



int main()
{	

	char *filename= "savefile";       /* name of savefile for dumping packet data */
	const char *device;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t *descr;
	int disc1=0;
	pcap_dumper_t *pd;       /* pointer to the dump file */
	device = pcap_lookupdev(errbuf);
	if(device == NULL)
	{
	 printf("ERROR in reading device");
	}	
	printf("DEV:%s\n",device);
	
int 	pcap_lookupnet(const char *device, bpf_u_int32 *netp, bpf_u_int32 *maskp, char *errbuf);
	descr =  pcap_open_live(device, BUFSIZ, 1, 0, errbuf);
	if(descr == NULL)
	{
	 printf("ERROR");
	}
	 pd = pcap_dump_open(descr,filename);

	pcap_loop(descr,-1, pcap_dump, (char *)pd); //cnt =-1 for infinte times of loop

        pcap_dump_close(pd);     
        pcap_close(descr);	



	fprintf(stdout,"\nfinished\n");
        return 0;

}
