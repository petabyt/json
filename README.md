# json
~200LoC. It has one function:
```
int json_get(struct Parse *p, char *text, char *intent);
```
The output of the JS-like 'intent' will be stored in `p.str` with length `p.str_len`. This will just point to an offset in the buffer you gave the parser.
Optionally, you can call `char *json_fixup_string(struct Parse *p)` to get a formatted output.
```
char *data = ... see c.txt ...;
struct Parse p;
json_get(&p, data, "['amendments'][10]");
```

Advantages:
- Very fast lexer & recursive descent parser
- Simple API
- No memory allocation required
- Correct (?) It parsed the entire [bible](https://github.com/heb12/gratis.json/blob/master/en/web.json).

Disadvantages:
- May not throw error on invalid syntax / invalid accesses
- Not memory safe
- Doesn't parse into a tree for reformatting back to text
