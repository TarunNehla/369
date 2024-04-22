import re
# Define token types using regular expressions
token_specification = [
    ('NUMBER',   r'\d+(\.\d*)?'),  # Integer or decimal number
    ('ASSIGN',   r'='),             # Assignment operator
    ('PLUS',     r'\+'),            # Addition operator
    ('MINUS',    r'-'),             # Subtraction operator
    ('TIMES',    r'\*'),            # Multiplication operator
    ('DIVIDE',   r'/'),             # Division operator
    ('LPAREN',   r'\('),            # Left parenthesis
    ('RPAREN',   r'\)'),            # Right parenthesis
    ('ID',       r'[A-Za-z_][A-Za-z0-9_]*'),  # Identifier
    ('COMMENT',  r'#.*'),           # Comment
    ('WS',       r'\s+'),           # Whitespace
]


# Join the regular expressions for tokenization
tok_regex = '|'.join('(?P<%s>%s)' % pair for pair in token_specification)


# Define a function to tokenize the input code
def tokenize(code):
    for mo in re.finditer(tok_regex, code):
        token_type = mo.lastgroup
        token_value = mo.group(token_type)
        if token_type != 'WS' and token_type != 'COMMENT':  # Skip whitespace and comments
            yield token_type, token_value


# Example code to tokenize
code = '''
# This is a comment
x = 42 + 3.14
Y =     25-0
'''
for token in tokenize(code):
    print(token)
