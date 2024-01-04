# json
API is python-like:
```
struct Parse p;
json_get(&p, data, "['amendments'][10]");
```

It skips lexing and goes straight through the syntax recursive-descent style.
At the same time, it loops through a JSON-like "intent" (which uses the same tokenizer) to get a desired value.

Advantages:
- The entire structure doesn't have to be lexed/parsed for a single read
- Easy to use
- No memory allocation
- Very simple implementation

Disadvantages:
- May not throw error on invalid syntax
- Have to parse the entire structure for multiple reads
- Doesn't parse into a tree for reformatting back to text
