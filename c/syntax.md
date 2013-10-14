#SYNTAX

 this file record strange C/C++ syntax entercounted

##Contents
 - static const int foo = 42







##01.static

A lot of people gave the basic answer but nobody pointed out that const 
defaults to static (and some gave wrong information). See the C++98 standard 
section 3.5.3.

First some background:

- Translation unit: A source file after the pre-compiler (recursively) included 
all its include files.

- Static linkage: A symbol is only available within its translation unit.

- External linkage: A symbol is available from other translation units.

**At namespace level**

This includes the global namespace aka global variables

```
static const int sci = 0; // sci is explicitly static
const int ci = 1;         // ci is implicitly static
extern const int eci = 2; // eci is explicitly extern
extern int ei = 3;        // ei is explicitly extern
int i = 4;                // i is implicitly extern
static int si = 5;        // si is explicitly static
```

**At function level**

static means the value is maintained between function calls.
The semantics of function static variables is similar to global variables in 
that they reside in the program's data-segment (and not the stack or the heap),
see this question for more details about static variables' lifetime.

**At class level**

static means the value is shared between all instances of the class and const 
means it doesn't change (and can be initialized inline) this is the only case 
in which neither the static nor the const are redundant.
