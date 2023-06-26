#include <stdio.h>
#include <mm_malloc.h>
#include <errno.h>
#include <string.h>

#include <sys/sysctl.h>

void print_ostype() {
  int mib_len = 2;
  int mib[mib_len];
  mib[0] = CTL_KERN;
  mib[1] = KERN_OSTYPE;

  size_t len;
  if (sysctl(mib, mib_len, NULL, &len, NULL, 0) == -1) {
    printf("Error %s\n", strerror(errno));
  }

  char *ostype = malloc(len);
  if (sysctl(mib, mib_len, ostype, &len, NULL, 0) == -1) {
    printf("Error %s\n", strerror(errno));
  }

  printf("kern.ostype = %s\n", ostype);
}

int main() {
  print_ostype();

  return 0;
}
