
int main()
{
    int a, b;
    int A, B, C, D;
    int rs1, rs2, rs3;
    scanf("%d %d", &a, &b);
    A = b % 10;
    B = (b % 100 - A)/10;
    D = b / 100;
    C = a * b;
    rs1 = a * A;
    rs2 = a * B;
    rs3 = a * D;
    printf("%d \n%d \n%d \n%d", rs1, rs2, rs3, C);
    return 0;
}