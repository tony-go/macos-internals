#include <stdio.h>
#include <mm_malloc.h>
#include <errno.h>
#include <string.h>

#include <sys/sysctl.h>

void print_ostype() {
  char *name = "kern.ostype";

  size_t len;
  if (sysctlbyname(name, NULL, &len, NULL, 0) == -1) {
    printf("Error %s\n", strerror(errno));
  }

  char *ostype = malloc(len);
  if (sysctlbyname(name, ostype, &len, NULL, 0) == -1) {
    printf("Error %s\n", strerror(errno));
  }

  printf("kern.ostype = %s\n", ostype);
}

int main() {
  print_ostype();

  return 0;
}
