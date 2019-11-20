#include <uv.h>
#include <stdlib.h>
#include <stdio.h>
uv_fs_t read_req;
uv_fs_t open_req;
uv_fs_t close_req;
uv_fs_t write_req;

uv_buf_t buffer ;
int c =0;
void on_read(uv_fs_t* req);
void on_open(uv_fs_t* req);
void on_write(uv_fs_t* req);

void on_open(uv_fs_t* req){
	if(req->result != -1) 
	{
		 c = uv_fs_read(uv_default_loop(), &read_req, req->result,(const uv_buf_t *) buffer.base, buffer.len, -1, on_read);
	
	}
}


void on_read(uv_fs_t* req){
	printf("c=%d\n",c);
	//uv_fs_req_cleanup(req);
	printf("%ld",req->result);
//	if(req->result < 0){
//	fprintf(stderr,"read error");
//	}
//	else if(req->result == 0){
//	uv_fs_close(uv_default_loop(), &close_req,open_req.result, NULL);
//}
//	else {
	uv_fs_write(uv_default_loop(), &write_req, 1,(const uv_buf_t*) buffer.base, req->result, -1, on_write);
//}
}

void on_write(uv_fs_t* req){
	uv_fs_req_cleanup(req);
	if(req->result < 0){
	fprintf(stderr,"write error");}
	else {
	uv_fs_read(uv_default_loop(), &write_req, open_req.result,(const uv_buf_t*) buffer.base, buffer.len, -1 , on_read);
}
}


int main(){
	

	unsigned int len = 1000*sizeof(char);
	char *base = (char *)malloc(len);
	buffer = uv_buf_init(base, len);
	int a = uv_fs_open(uv_default_loop(),&open_req, "hello.txt", O_RDONLY, 0 , on_open);
	printf("%d\n",a);
	int b = uv_run(uv_default_loop(),UV_RUN_DEFAULT);
	printf("b=%d",b);
	free(buffer.base);
}
