# Template
1. Use two stack to maintain numbers and operators.
2. If current candidate is a number, push it into the stack
3. If current candidate is a left paranthesis, push it into the stack
4. If current candidate is a right paranthesis, eval all operators until it's empty or the top is "("
5. If current candidate is a operator, 
    1. If position is 0 or its front position is a operator character, add an additional 0 to make the unary operator a binary one.
    2. If that operator has equal or lower priority than the stack top, eval the top
    3. If that operator has higher priority than the stack top, push it into stack
6. Finally, if there is any operator remaining, eval them.
