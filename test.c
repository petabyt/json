#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "json.c"

int main() {
	FILE *f = fopen("c.txt", "rb");
	if (!f) {
		puts("File err");
		return 1;
	}

	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *data = (char *)malloc(size + 1);
	fread(data, 1, size, f);
	fclose(f);
	data[size] = '\0';

	struct Parse p;
	json_get(&p, data, "['amendments'][10]");

	char *buf = malloc(p.str_len);
	strncpy(buf, p.str, p.str_len + 1);
	buf[p.str_len] = '\0';
	printf("Result: %s\n", buf);

	return 0;
}
