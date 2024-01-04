struct Parse {
	char *b;
	char *intent;
	char intent_type;
	char intent_key[16];
	int intent_i;

	char type;
	char *str;
	int str_len;
	unsigned int value;
};

int json_get(struct Parse *p, char *text, char *intent);

char *json_fixup_string(struct Parse *p);
