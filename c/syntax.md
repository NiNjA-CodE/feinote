#SYNTAX of C/C++

 This file record strange C/C++ syntax entercounted

##Contents
 - 01 static 
 - 02 const
 - 03 explicit
 - 04 friend
 - 05 inline
 - 06 namespace
 - 07 boost::noncopyable
 - 08 boost::array
 - 09 boost::function




##01.static

**reference**

- [stackoverflow1](http://stackoverflow.com/questions/177437/const-static)
- [stackoverflow2](http://stackoverflow.com/questions/1312241/using-a-static-const-int-in-a-struct-class)

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

##02.const

##03.explicit
used only for constructor of class

**reference**
- [stackoverflow](http://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-in-c-mean)
- [IBM](http://publib.boulder.ibm.com/infocenter/comphelp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8a.doc%2Flanguage%2Fref%2Fexplicit_keyword.htm)
- [visual studio](http://msdn.microsoft.com/en-us/library/vstudio/h1y7x448.aspx)

##04.friend

##05.inline

##06.namespace

##07.boost::noncopyable

**reference**

- [CSDN](http://blog.csdn.net/huang_xw/article/details/8248960)

##08.boost::array

**reference**

- [CSDN](http://blog.csdn.net/huang_xw/article/details/8248361)

##09.boost::function

**reference**

- [CSDN](http://blog.csdn.net/huang_xw/article/details/8249278)
