#include <stdio.h>
#include <errno.h>

#include <sys/utsname.h>

int main() {
  struct utsname* data;

  int res = uname(data);
  if (res == -1) {
    printf("Error: %d\n", errno);
    return 1;
  }

  printf("uname function fill the following structure:\n");
  printf("sysname: %s\n", data->sysname);
  printf("nodename: %s\n", data->nodename);
  printf("release: %s\n", data->release);
  printf("version: %s\n", data->version);
  printf("machine: %s\n", data->machine);

  return 0;
}

