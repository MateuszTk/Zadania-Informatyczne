#include <iostream>

using namespace std;

int calc(int a, int b, int op, int* cmem) {
     asm volatile(R"as(
        cmp $43, %[op];
        je _ADD;

        cmp $45, %[op];
        je _SUBTRACT;

        cmp $42, %[op];
        je _MULTIPLY;

        cmp $47, %[op];
        je _DIVIDE;

        cmp $37, %[op];
        je _MODULO;

        cmp $122, %[op];
        je _MEMADD;

        jmp _RETURN;

        _ADD:
        call _GET_VALUES;
        addl %[y], %%eax;
        jmp _RETURN;

        _SUBTRACT:
        call _GET_VALUES;
        subl %[y], %%eax;
        jmp _RETURN;

        _MULTIPLY:
        call _GET_VALUES;
        imul %[y];
        jmp _RETURN;

        _DIVIDE:
        call _GET_VALUES;
        movl $0, %%edx;
        cdq;
        idiv %[y];
        jmp _RETURN;

        _MODULO:
        call _GET_VALUES;
        movl $0, %%edx;
        cdq;
        idiv %[y];
        movl %%edx, %%eax;
        jmp _RETURN;

        _MEMADD: //replaces memory at adress indicated by x with the value of y
        push %[cmem];
        shll $2, %[x];
        addl %[x], %[cmem];
        movl %[y], (%[cmem]);
        pop %[cmem];
        movl $0, %%eax;
        jmp _RETURN;

        _GET_VALUES: //overwrites the eax and y registers with values indicated by x and y
        push %[cmem];
        shll $2, %[y];
        addl %[y], %[cmem];
        movl (%[cmem]), %[y];
        pop %[cmem];
        shll $2, %[x];
        addl %[x], %[cmem];
        movl (%[cmem]), %%eax;
        ret;

        _RETURN:

        )as"
        :
        :[x] "r" (a), [y] "r" (b), [op] "r" (op), [cmem] "r" (cmem)
        :"memory", "%eax", "%edx"
    );
}


int main()
{
    int* cmem = new int[10];
    for(int i = 0; i < 10; i++) cmem[i] = 0;

    while (true) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        int r = calc(a, b, (int)op, cmem);
        if(op != 'z') cout << r << '\n';
    }
    return 0;
}

