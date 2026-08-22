/* _____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

Infix Expressions

Infix expressions are mathematical expressions where the operator is placed between its operands. 
This is the most common mathematical notation used by humans.

For example, 
the expression "2 + 3" is an infix expression, where the operator "+" is placed between the operands "2" and "3".

Infix notation is easy to read and understand for humans, but it can be difficult for computers to evaluate efficiently. 
This is because the order of operations must be taken into account, 
and parentheses can be used to override the default order of operations.

--------------------------------------------------------------------------------------------------------------------

Common way of writing Infix expressions:
Infix notation is the notation that we are most familiar with. For example, the expression "2 + 3" is written in infix notation.
In infix notation, operators are placed between the operands they operate on. For example, in the expression "2 + 3", 
the addition operator "+" is placed between the operands "2" and "3".
Parentheses are used in infix notation to specify the order in which operations should be performed. 

For example, 
In the expression "(2 + 3) * 4", 
the parentheses indicate that the addition operation should be performed before the multiplication operation.

--------------------------------------------------------------------------------------------------------------------

Operator precedence rules:
Infix expressions follow operator precedence rules, which determine the order in which operators are evaluated. 

For example, multiplication and division have higher precedence than addition and subtraction. 
This means that in the expression "2 + 3 * 4", 
the multiplication operation will be performed before the addition operation.

--------------------------------------------------------------------------------------------------------------------

Here's the table summarizing the operator precedence rules for common mathematical operators:
__________________________________
| Operator Precedence | Priority |
| ------------------- | -------- |
| Parentheses ()      | Highest  |
| Exponents ^         | High     |
| Multiplication *    | Medium   |
| Division /          | Medium   |
| Addition +          | Low      |
| Subtraction -       | Low      |

--------------------------------------------------------------------------------------------------------------------
Advantages of Infix Expressions :
More natural and easier to read and understand for humans.
Widely used and supported by most programming languages and calculators.

Disadvantages Infix Expressions :
Requires parentheses to specify the order of operations.
Can be difficult to parse and evaluate efficiently.

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

Prefix Expressions (Polish Notation)

Prefix expressions are also known as Polish notation, are a mathematical notation where the operator precedes its operands. 
This differs from the more common infix notation, where the operator is placed between its operands.
Evaluating prefix expressions can be useful in certain scenarios, such as when dealing with expressions 
that have a large number of nested parentheses or when using a stack-based programming language.

In prefix notation, the operator is written first, followed by its operands. 

For example, the infix expression "a + b" would be written as "+ a b" in prefix notation.


Advantages of Prefix Expressions : 
No need for parentheses, as the operator always precedes its operands.
Easier to parse and evaluate using a stack-based algorithm.
Can be more efficient in certain situations, such as when dealing with expressions that have a large number of nested parentheses.

Disadvantages of Prefix Expressions :
Can be difficult to read and understand for humans.
Not as commonly used as infix notation.

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

Postfix Expressions (Reverse Polish Notation) 

Postfix expressions are also known as Reverse Polish Notation (RPN), are a mathematical notation where the operator follows its operands. This differs from the more common infix notation, where the operator is placed between its operands.

In postfix notation, operands are written first, followed by the operator. For example, the infix expression "5 + 2" would be written as "5 2 +" in postfix notation.

Evaluating Postfix Expressions (Reverse Polish Notation)
Evaluating postfix expressions can be useful in certain scenarios, such as when dealing with expressions that have a large number of nested parentheses or when using a stack-based programming language.

Advantages of Postfix Notation :
Also eliminates the need for parentheses.
Easier to read and understand for humans.
More commonly used than prefix notation.

Disadvantages of Postfix Expressions :
Requires a stack-based algorithm for evaluation.
Can be less efficient than prefix notation in certain situations.

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

Comparison of Infix, Prefix and Postfix Expressions :

Let's compare infix, prefix, and postfix notations across various criteria:
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
| Aspect                       | Infix Notation                                                     | Prefix Notation (Polish Notation)                                 | Postfix Notation (Reverse Polish Notation)                        |
| ---------------------------- | ------------------------------------------------------------------ | ----------------------------------------------------------------- | ----------------------------------------------------------------- |
| Readability                  | Human-readable                                                     | Less human-readable, requires familiarity                         | Less human-readable, requires familiarity                         |
| Operator Placement           | Between operands                                                   | Before operands                                                   | After operands                                                    |
| Parentheses Requirement      | Often required                                                     | Not required                                                      | Not required                                                      |
| Operator Precedence Tracking | Required, parentheses determine precedence                         | Not required, operators have fixed precedence                     | Not required, operators have fixed precedence                     |
| Evaluation Method            | Left-to-right                                                      | Right-to-left                                                     | Left-to-right                                                     |
| Ambiguity Handling           | May require explicit use of parentheses                            | Ambiguity rare, straightforward evaluation                        | Ambiguity rare, straightforward evaluation                        |
| Unary Operator Handling      | Requires careful placement                                         | Simplified handling due to explicit notation                      | Simplified handling due to explicit notation                      |
| Computer Efficiency          | Less efficient due to precedence tracking and parentheses handling | More efficient due to fixed precedence and absence of parentheses | More efficient due to fixed precedence and absence of parentheses |
| Usage                        | Common in everyday arithmetic and mathematical notation            | Common in computer science and programming languages              | Common in computer science and programming languages              |
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ */