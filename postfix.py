MAX = 100
stack = []
top = -1

def push(item):
    global top
    if top == MAX - 1:
        print("\nStack overflow")
    else:
        top += 1
        stack.append(item)

def pop():
    global top
    if top == -1:
        print("\nStack undeflow")
    else:
        item = stack[top]
        top -= 1
        return item

def is_op(symbol):
    if symbol == '+' or symbol == '-' or symbol == '*' or symbol == '/':
        return 1
    return 0

def evaluate(expression):
    op1, op2, result = 0, 0, 0
    i = 0
    symbol = expression[i]
    while symbol != '\0':
        if symbol.isdigit():
            num = int(symbol)
            push(num)
        elif is_op(symbol):
            op2 = pop()
            op1 = pop()
            if symbol == '+':
                result = op1 + op2
            elif symbol == '-':
                result = op1 - op2
            elif symbol == '*':
                result = op1 * op2
            elif symbol == '/':
                result = op1 / op2
            push(result)
        i += 1
        symbol = expression[i]
    result = pop()
    return result

expression = input("\nEnter the postfix expression: ")
result = evaluate(expression)
print("Result:", result)

