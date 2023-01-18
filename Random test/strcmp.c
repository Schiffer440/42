#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
 
 int main()
 {
	printf("%s\n", strnstr("salut come sta", "come", 14));
	return(0);
 }