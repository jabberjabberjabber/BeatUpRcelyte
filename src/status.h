#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/*static enum MHD_Result status_callback(void *cls, struct MHD_Connection *connection, const char *url, const char *method, const char *version, const char *upload_data, size_t *upload_data_size, void **con_cls) {
	if(strcmp(method, "GET") != 0)
		return MHD_NO;
	if(strcmp(url, "/status") == 0) {}
	const char r200[] = "{\"minimumAppVersion\":\"1.16.4\",\"status\":0,\"maintenanceStartTime\":0,\"maintenanceEndTime\":0,\"userMessage\":{\"localizedMessages\":[]}}";
	const char r404[] = "<html><body>404 not found</body></html>";

	struct MHD_Response *response = MHD_create_response_from_buffer(len, resp, MHD_RESPMEM_PERSISTENT);
	MHD_add_response_header(response, MHD_HTTP_HEADER_CONTENT_TYPE, "text/html; charset=utf-8");
	MHD_add_response_header(response, MHD_HTTP_HEADER_X_CONTENT_TYPE_OPTIONS, "nosniff");
	MHD_add_response_header(response, MHD_HTTP_HEADER_X_FRAME_OPTIONS, "DENY");
	enum MHD_Result ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
	MHD_destroy_response(response);
}*/
static void *status_handler(void *listenfd) {
	struct SS addr;
	int32_t csock;
	while((csock = accept((intptr_t)listenfd, &addr.sa, &addr.len))) {
		char buf[81920];
		ssize_t size = recv(csock, buf, sizeof(buf), 0);
		if(size < 0) {
			close(csock);
			continue;
		}
		const char *resp;
		if(size >= 6 && memcmp(buf, "GET / ", 6) == 0) {
			fprintf(stderr, "[HTTP] GET /\n");
			resp =
				"HTTP/1.1 200 OK\r\n"
				"Connection: close\r\n"
				"Content-Length: 182\r\n"
				"X-Frame-Options: DENY\r\n"
				"X-Content-Type-Options: nosniff\r\n"
				"Content-Type: application/json; charset=utf-8\r\n"
				"X-DNS-Prefetch-Control: off\r\n"
				"\r\n"
				"{\"minimumAppVersion\":\"1.16.4\",\"status\":0,\"maintenanceStartTime\":0,\"maintenanceEndTime\":0,\"userMessage\":{\"localizedMessages\":[{\"language\":\"en\",\"message\":\"Test message from server\"}]}}";
		/*} else if(size >= 32 && memcmp(buf, "GET /.well-known/acme-challenge/", 32) == 0) {
			resp =
				"HTTP/1.1 200 OK\r\n"
				"Connection: close\r\n"
				"Content-Length: 0\r\n"
				"X-Frame-Options: DENY\r\n"
				"X-Content-Type-Options: nosniff\r\n"
				"Content-Type: text/plain; charset=utf-8\r\n"
				"X-DNS-Prefetch-Control: off\r\n"
				"\r\n";*/
		} else {
			resp =
				"HTTP/1.1 404 Not Found\r\n"
				"Connection: close\r\n"
				"Content-Length: 39\r\n"
				"X-Frame-Options: DENY\r\n"
				"X-Content-Type-Options: nosniff\r\n"
				"Content-Type: text/html; charset=utf-8\r\n"
				"X-DNS-Prefetch-Control: off\r\n"
				"\r\n"
				"<html><body>404 not found</body></html>";
		}
		send(csock, resp, strlen(resp), 0);
		close(csock);
	}
	return NULL;
}
static pthread_t status_thread;
static int32_t listenfd = -1;
static _Bool status_init() {
	listenfd = socket(AF_INET6, SOCK_STREAM, 0);
	{
		int32_t iSetOption = 1;
		setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char*)&iSetOption, sizeof(iSetOption));
		struct sockaddr_in6 serv_addr = {
			.sin6_family = AF_INET6,
			.sin6_port = htons(80),
			.sin6_flowinfo = 0,
			.sin6_addr = IN6ADDR_ANY_INIT,
			.sin6_scope_id = 0,
		};
		if(bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
			fprintf(stderr, "Cannot bind socket: %s\n", strerror(errno));
			close(listenfd);
			listenfd = -1;
			return 1;
		}
	}
	if(listen(listenfd, 128) < 0) {
		close(listenfd);
		listenfd = -1;
		return 1;
	}
	return pthread_create(&status_thread, NULL, (void*)&status_handler, (void*)(intptr_t)listenfd) != 0;
}
static void status_cleanup() {
	if(listenfd >= 0)
		close(listenfd);
}