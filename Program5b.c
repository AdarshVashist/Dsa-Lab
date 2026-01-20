#include <stdio.h>

void toh(int n, char src, char aux, char dest);

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    toh(n, 'A', 'B', 'C');
    return 0;
}

void toh(int n, char src, char aux, char dest)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }

    toh(n - 1, src, dest, aux);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    toh(n - 1, aux, src, dest);
}
