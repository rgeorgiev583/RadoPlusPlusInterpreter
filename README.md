# LambdaRadoInterpreter
An interpreter for a functional programming language; this is my course project for the Data Structures and Programming course at FMI.


## Formal grammar for custom syntax
**NOTE:** Whitespace is not significant except when specified otherwise (i.e. in a literal).

	<program> ::= <compound-statement>
	<compound-statement> ::= '{' <statement>* '}'
	<statement> ::= <simple-statement> ';'* | <compound-statement>
	<simple-statement> ::= <assignment> | <return> | <output> | <input>
	<assignment> ::= <lhs> '=' <rhs>
	<lhs> ::= <identifier>
	<rhs> ::= <expression>
	<digit> ::= [0-9]
	<alpha> ::= [A-Za-z_]
	<identifier> ::= <alpha> (<digit> | <alpha>)*
	<placeholder> ::= <identifier> | <call>
	<calculable> ::= <integer> | <placeholder>
	<expression-string-atom> ::= <quoted-string> | <placeholder>
	<expression-string> ::= <expression-string-atom> | <expression-string> '+' <expression-string-atom>
	<expression-calculable> ::= <calculable> | <expression-calculable> '+' <calculable> | <expression-calculable> '-' <calculable> | 
					   							    <expression-calculable> '*' <calculable> | <expression-calculable> '/' <calculable> |
					   							    <expression-calculable> '^' <calculable>
	<expression> ::= <value> | <expression-string> | <expression-calculable>
	<value> ::= <integer> | <quoted-string> | <lambda> | <identifier> | <call>
	<integer> ::= '-'? <digit>*
	<quoted-string> ::= '"' <string> '"'
	<string> ::= <ascii-character>*
	<ascii-character> ::= [\x00-\x7F]
	<lambda> ::= '\' <identifier-tuple> <statement>
	<call> ::= <identifier> <expression-tuple>
	<separated-identifier> ::= <identifier> ','*
	<separated-expression> ::= <expression> ','*
	<identifier-tuple> ::= '(' <identifier> | <separated-identifier>* ')'
	<expression-tuple> ::= '(' <expression> | <separated-expression>* ')'
	<return> ::= 'return ' <expression>
	<output> ::= 'print ' <expression>
	<input> ::= 'input ' <expression>
	
	
## Language tokens and their corresponding implementations (header and source files)

* `<program>` - `main.cpp::main()`: is the base token (expands to everything)
* `<compound-statement>` - `compound.{h,cpp}::CompoundStatement`: like a compound statement in the C-like languages (sequence of statements)
* `<statement>` - `statement.{h,cpp}::Statement`: like a statement in the C-like languages (atomic and semicolon-terminated)
* `<simple-statement>` - `simple.{h,cpp}::SimpleStatement`: a statement without a semicolon
* `<assignment>` - `simple.{h,cpp}::SimpleStatement`: C-like assignment (`lhs = rhs`)
* `<lhs>` - left-hand side of assignment
* `<rhs>` - right-hand side of assignment
* `<identifier>` - `identifier.{h,cpp}::Identifier`: C-like identifier (only alphanumeric characters and `_` allowed, must not start with a digit)
* `<placeholder>` - an identifier or a function call (i.e. something to be evaluated before being used in an expression)
* `<calculable>` - an integer or a placeholder (i.e. something that can be calculated)
* `<expression-string-atom>` - string expressions are composed of these: a string or a placeholder
* `<expression-string>` - a string expression (e.g. string concatenation with `+`)
* `<expression-calculable>` - an expression with numbers (or calculable things, including placeholders)
* `<expression>` - `exprtree.{h,cpp}::ExpressionTree`: a generic expression (implemented as an abstract syntax tree)
* `<value>` - `value.{h,cpp}::Value`: something which can be evaluated (i.e. the atom of an expression):
   an integer, string, lambda expresion, identifer, or a function call
* `<integer>` - `integer.{h,cpp}::Integer`: an integer (with an optional minus sign)
* `<quoted-string>` - a string surrounded by quotes (`"`); when parsed the quotes are removed
* `<string>` - `string.{h,cpp}::String`: only ASCII characters are permitted (no Unicode support)
* `<lambda>` - `lambda.{h,cpp}::Lambda`: a lambda expression (an anonymous function that otherwise behaves like a normal function
   (i.e. has parameters, body, etc.) except that it has no name and can be assigned to variables (expression-like)
* `<call>` - `call.{h,cpp}::Call`: a function call (obviously, to a lambda): accepts arguments (which are actually expressions)
* `<separated-identifier>` - identifier followed by a comma
* `<separated-expression>` - expression followed by a comma
* `<identifier-tuple>` - a list of comma-separated identifiers wrapped in parentheses
* `<expression-tuple>` - a list of comma-separated expressions wrapped in parentheses
* `<return>` - a return statement (interrupts the currently running procedure)


## What does this program do?
It parses a program entered from the standard input and then interprets it.


## How to use this program
Just run it and enter the program, followed by EOF (Ctrl-D on Unix-based OSes, Ctrl-Z on Windows).
