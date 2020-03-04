#include <stdio.h> 
#include <string.h>


int main() {
  char * first_name = "John";
  char last_name[] = "Smith";

  char name[strlen(first_name) + strlen(last_name)];

  sprintf(name, "%s %s", first_name, last_name);
  puts(name);

  return 0;
}
