#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

const int backlog = 128;
const int buffer_size = 1024;
uv_fs_t open_req;
uv_fs_t read_req;
uv_tcp_t *client; 
 uv_buf_t buffer;
uv_buf_t iov;
uv_fs_t write_req;

void on_new_connection(uv_stream_t *server, int status);
static void alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf);
void on_client_read(uv_stream_t *client, ssize_t nread, const struct uv_buf_t* buf);
void on_client_write(uv_write_t *req, int status);
void on_file_open(uv_fs_t *req);
void on_file_read(uv_fs_t *req);
int d;

void on_new_connection(uv_stream_t *server, int status) {
  if (status == -1) {
    fprintf(stderr, "error on_new_connection");
    uv_close((uv_handle_t*) client, NULL);
    return;
  }

  client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
  uv_tcp_init(uv_default_loop(), client);
  int result = uv_accept(server, (uv_stream_t*) client);
  if (result == 0) { 
	 uv_read_start((uv_stream_t*) client, alloc_buffer, on_client_read);
  } else {
    uv_close((uv_handle_t*) client, NULL);
  }
}

static void alloc_buffer(uv_handle_t* handle, size_t suggested_size,uv_buf_t* buf) {
  buf->base = malloc(65536);
  buf->len = 65536;
}

void on_client_read(uv_stream_t * client, ssize_t nread,const struct uv_buf_t* buf) {
  if (nread == -1) {
    fprintf(stderr, "error on_client_read");
    uv_close((uv_handle_t*) client, NULL);
    return;
  }
  char *filename = buf->base;
  printf("%s\n",buf->base);
  int mode = 0;
	printf("1\n");
   d = uv_fs_open(uv_default_loop(), &open_req, filename, O_RDONLY, mode, on_file_open); if(d){ printf("open_errord=%d",d);}

}

void on_client_write(uv_write_t *req, int status) {
  if (status == -1) {
    fprintf(stderr, "error on_client_write");
    uv_close((uv_handle_t*) client, NULL);
    return;
  }
  free(req);
  char *buffer = (char*) req->data;
  free(buffer);
  uv_close((uv_handle_t*) client, NULL);
}
void  on_file_open(uv_fs_t *req) {
//printf("d=%d\n",d);
  if (req->result == -1) {
    fprintf(stderr, "error on_file_open");
    uv_close((uv_handle_t*) client, NULL);
  }
  char *buffer = (char *) malloc(sizeof(char) * buffer_size);
  int offset = -1;
  read_req.data = (void*) buffer;
  //printf("req = %ld\n",req->result);
  iov = uv_buf_init(buffer,sizeof(buffer));
	printf("2\n");
  uv_fs_read(uv_default_loop(), &read_req, req->result,&iov, 1, -1, on_file_read);
  uv_fs_req_cleanup(req);
}

void on_write(uv_fs_t* req){
	if(req->result < 0 )
	{
	fprintf(stderr,"write error: %s \n", uv_strerror((int) req->result));
}
else{
uv_fs_read(uv_default_loop(), &read_req, open_req.result, &iov, 1, -1,on_file_read );
}
}

void on_file_read(uv_fs_t *req) {
  //printf("req1 = %ld\n ", req->result);
  if (req->result < 0) {
    fprintf(stderr, "error on_file_read");
    uv_close((uv_handle_t*) client, NULL);
  } else if (req->result == 0) {
    uv_fs_t close_req;
    uv_fs_close(uv_default_loop(), &close_req, open_req.result, NULL);
    uv_close((uv_handle_t*) client, NULL);
  } else { 
//    uv_write_t *write_req = (uv_write_t *) malloc(sizeof(uv_write_t));
    char *message = (char*) req->data;
    uv_buf_t iov = uv_buf_init(message, sizeof(message));
    iov.len = req->result;
    iov.base = message;
    int buf_count = 1;
    write_req.data = (void*) message;
    //uv_write(write_req, (uv_stream_t*) client, &buf, buf_count, on_client_write);
	uv_fs_write(uv_default_loop(), &write_req, 1, &iov, 1, -1, on_write);
  }
  uv_fs_req_cleanup(req);
}

int main(void) {
  uv_tcp_t server;
  struct sockaddr_in addr;
  int a =  uv_tcp_init_ex(uv_default_loop(), &server, AF_INET);                   if(a){printf("error uv_tcp_init\n");}
  int b =  uv_ip4_addr("0.0.0.0", 20 , &addr);                                  if(b){printf("error uv_tcp_bind\n");}
  int c =  uv_tcp_bind(&server, (const struct sockaddr* )&addr, 0 );              if(c){printf("error uv_tcp_bind\n");}
  int r = uv_listen((uv_stream_t*) &server, 100 , on_new_connection);
  if (r) {printf("error uv_listen"); }
  uv_run(uv_default_loop(),UV_RUN_DEFAULT);
  return 0;
}
