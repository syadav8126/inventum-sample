#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/ether.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


u_int16_t handle_ethernet (u_char* args,const struct pcap_pkthdr* pkthdr,const u_char* packet); // handling ethernet packet

u_char* handle_IP (u_char *args,const struct pcap_pkthdr* pkthdr,const u_char* packet);         //handling ip type packet

struct my_ip {
	u_int8_t        ip_vhl;
#define IP_V(ip)	(((ip)->ip_vhl & 0xf0) >> 4)
#define IP_HL(ip)       ((ip)->ip_vhl & 0x0f) 
	u_int8_t 	ip_tos;
	u_int16_t	ip_len; //total length of ip datagram, header + data
	u_int16_t	ip_id;   
	u_int16_t	ip_off;  
#define IP_DF 0x4000          
#define IP_MF 0x2000          
#define IP_OFFMASK 0x1fff     	
	u_int8_t	ip_ttl; 
	u_int8_t 	ip_p; 
	u_int16_t	ip_sum;
	struct  in_addr ip_src,ip_dst;
};

void callback(u_char* args, const struct pcap_pkthdr *pkthdr, const u_char* packet)
{

	u_int16_t type = handle_ethernet(args,pkthdr,packet);
	if(type == ETHERTYPE_IP)
	{
	  handle_IP(args,pkthdr,packet);
	}

	else if(type == ETHERTYPE_ARP)
	{
	 printf("\nARP\n \n \n \n");
	}
}

u_char* handle_IP(u_char *args,const struct pcap_pkthdr* pkthdr,const u_char* packet)

{
	const struct my_ip* ip;
	u_int length = pkthdr->len;
	u_int hlen,off,version, p;
	int i;
	int len;
	ip = (struct my_ip*)(packet + sizeof(struct ether_header));
	length -= sizeof(struct ether_header);
	if(length < sizeof(struct my_ip))
	{
	 printf("truncated IP %d\n",length);
	}
	len = ntohs(ip->ip_len);
	p=(ip->ip_p);
	hlen = ip->ip_vhl;   //ip header length
	version = IP_V(ip);
	printf("IPv%d",version);
	if(p ==6)
	{
	 printf("\nTCP");
	}

	else if(p == 17)
	{
	 printf("\nUDP");
	}
	else 
	{
	printf("\n %d", p);
	}
	printf("\nlength of IP datagram: %d",len);
	printf("\nIP packet header length: %d",hlen);
	printf("\nSource Ip %s", inet_ntoa(ip->ip_src));
	printf("\nDestination Ip %s\n \n \n \n ", inet_ntoa(ip->ip_dst));

	return NULL;
	
}


u_int16_t handle_ethernet(u_char *args, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
	bpf_u_int32 caplen = (pkthdr->caplen);
	bpf_u_int32 length = (pkthdr->len);

	struct ether_header* eptr;
	u_short ether_type;
	
	if(caplen < 14)
	{
	 printf("packet length is less than ethernet header leader length ");
	 exit(1);
	}
	eptr = (struct ether_header * )packet;
	ether_type=(ntohs(eptr->ether_type));

//	fprintf(stdout,"\nether type %x",ether_type);
	printf("\nsource mac:%s",ether_ntoa((struct ether_addr*)eptr->ether_shost));
	printf("\ndestination mac:%s",ether_ntoa((struct ether_addr*)eptr->ether_dhost));

 	printf("\nETHER packet length:%d",caplen);
	if(ether_type == ETHERTYPE_IP)
	{
	 printf("\nEther type : ");
	}
	else if(ether_type == ETHERTYPE_ARP)
	{
	 //fprintf(stdout,"\nEther type :ARP");
	}
	else
	{
	 printf("\n \n \n \n ?");
	}
	return ether_type;
}


int main()
{
	const char *device;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t *descr;
	int disc1;


	device = pcap_lookupdev(errbuf);
	if(device == NULL)
	{
	 printf("ERROR in reading device");
	}	
	printf("DEV:%s\n",device);
	
	int pcap_lookupnet(const char *device, bpf_u_int32 *netp, bpf_u_int32 *maskp, char *errbuf);
	descr =  pcap_open_live(device, BUFSIZ, 1, 0, errbuf);
	if(descr == NULL)
	{
	 printf("ERROR");
	}

	disc1 = pcap_loop(descr,-1, callback, NULL); //cnt =-1 for infinte times of loop
//	printf("\nNo of packets Captured : %d",disc1);


	fprintf(stdout,"\nfinished\n");
        return 0;

}
