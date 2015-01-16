# LambdaRadoInterpreter
An interpreter for a functional programming language; this is my course project for the Data Structures and Programming course at FMI.


## Formal grammar for custom syntax
**NOTE:** Whitespace is not significant except when specified otherwise (i.e. in a literal).

	<program> ::= <compound-statement>
	<compound-statement> ::= '{' <statement>* '}'
	<statement> ::= <simple-statement> ';' | <compound-statement>
	<simple-statement> ::= <assignment> | <return> | <output> | <input>
	<assignment> ::= <lhs> '=' <rhs>
	<lhs> ::= <identifier>
	<digit> ::= [0-9]
	<alpha> ::= [A-Za-z_]
	<identifier> ::= <alpha> (<digit> | <alpha>)*
	<rhs> ::= <expression>
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
	<separated-identifier> ::= <identifier> ','
	<separated-expression> ::= <expression> ','
	<identifier-tuple> ::= '(' <identifier> | <separated-identifier>+ <identifier> ')'
	<expression-tuple> ::= '(' <expression> | <separated-expression>+ <expression> ')'
	<return> ::= 'return ' <expression>
	<output> ::= 'print ' <expression>
	<input> ::= 'input ' <expression>
	
	

## What does this program do?
It parses a program entered from the standard input and then interprets it.


## How to use this program
Just run it and enter the program, followed by EOF (Ctrl-D on Unix-based OSes, Ctrl-Z on Windows).
