#include <stdio.h>
#include <mm_malloc.h>
#include <errno.h>
#include <string.h>

#include <sys/sysctl.h>

void print_str_kern_info(int second_level_name, char* label) {
  int mib_len = 2;
  int mib[mib_len];
  mib[0] = CTL_KERN;
  mib[1] = second_level_name;

  size_t len;
  if (sysctl(mib, mib_len, NULL, &len, NULL, 0) == -1) {
    printf("Error %s\n", strerror(errno));
  }

  char *ostype = malloc(len);
  if (sysctl(mib, mib_len, ostype, &len, NULL, 0) == -1) {
    printf("Error %s\n", strerror(errno));
  }

  printf("%s = %s\n", label, ostype);
  free(ostype);
}

int main() {
  print_str_kern_info(KERN_OSTYPE, "kern.ostype");
  print_str_kern_info(KERN_VERSION, "kern.version");

  return 0;
}
