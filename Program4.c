#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x);
char pop();
int priority(char x);

int main()
{
    char infix[50], postfix[50];
    int i = 0, k = 0;
    char ch;

    printf("Enter infix expression:\n");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(ch))
                postfix[k++] = pop();
            push(ch);
        }
        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix expression:\n%s", postfix);
    return 0;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}
