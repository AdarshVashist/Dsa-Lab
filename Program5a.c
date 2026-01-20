#include <stdio.h>
#include <math.h>

int stack[50];
int top = -1;

void push(int x);
int pop();

int main()
{
    char postfix[50];
    int i, a, b;

    printf("Enter postfix expression:\n");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '%': push(a % b); break;
                case '^': push((int)pow(a, b)); break;
            }
        }
    }

    printf("Result = %d", pop());
    return 0;
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}
