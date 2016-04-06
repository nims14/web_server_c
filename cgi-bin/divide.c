/*
 * divide.c - a minimal CGI program that divides two numbers
 */
#include "webserver.h"

int main(void) {
    char *buf;
    char msg[MAXLINE], content[MAXLINE];
    int n1=1, n2=1;

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
      if (sscanf(buf, "num=%d&div=%d\n", &n1, &n2) != 2) {
	sprintf(msg, "Can't parse buffer '%s'", buf);
      } else if (n2 == 0) {
	sprintf(msg, "Attempt to divide %d by zero", n1);
      } else {
	sprintf(msg, "%d / %d -> %d, remainder %d\n",
		n1, n2, n1/n2, n1%n2);
      }
    } else {
      sprintf(msg, "Can't find query string");
    }
    /* Make the response body */
    sprintf(content, "Welcome to divide.com:<p>%s<p>Bye!\n", msg);
    /* Generate the HTTP response */
    printf("Content-length: %d\r\n", (int) strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    exit(0);
    }

