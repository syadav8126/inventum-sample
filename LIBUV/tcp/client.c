#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

uv_loop_t *loop;
uv_tcp_t* server;
void on_connect(uv_connect_t *req, int status);
void on_write_end(uv_write_t *req, int status);
static void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t* buf);
void echo_read(uv_stream_t *server, ssize_t nread, const struct uv_buf_t* buf);
void echo_read(uv_stream_t *server, ssize_t nread, const struct uv_buf_t* buf) {

	if (nread == -1) {fprintf(stderr, "error echo_read");}
	printf("result: %s\n", buf->base);
}

static void alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
  buf->base = malloc(65536575);
  buf->len = 65536575;
}


void on_write_end(uv_write_t *req, int status) {
	if (status == -1) {
		fprintf(stderr, "error on_write_end");
		return;
	}
	uv_read_start(req->handle, alloc_buffer, echo_read);
}
void on_connect(uv_connect_t *req, int status) {
	if (status == -1) {
		fprintf(stderr, "error on_write_end");
		return;
	}
	char *message = "pcap.c";
	int len = strlen(message);
	char buffer[100];
	uv_buf_t buf = uv_buf_init(buffer, sizeof(buffer));
	buf.len = len;
	buf.base = message;
	printf("len=%ld,base=%s",buf.len,buf.base);
	uv_stream_t* tcp = req->handle;
	uv_write_t write_req;
	int buf_count = 1;
	uv_write(&write_req, tcp, &buf, buf_count, on_write_end);
}

int main(void) {
	loop = uv_default_loop();
	struct sockaddr_in addr;
	uv_tcp_t client;
	uv_tcp_init(loop, &client);
	uv_ip4_addr("127.0.0.1", 20, &addr);
	uv_connect_t connect_req;
	uv_tcp_connect(&connect_req, &client, (const struct sockaddr*)&addr, on_connect);
	return uv_run(loop,UV_RUN_DEFAULT);
}
