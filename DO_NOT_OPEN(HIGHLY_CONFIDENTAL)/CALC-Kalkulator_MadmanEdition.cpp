#include <iostream>

using namespace std;

#define EXPERIMENTAL


#ifdef EXPERIMENTAL
//AT&T
int calc(int a, int b, int op) {
    asm volatile(
        "mov $0, %%eax;"

        "cmp $43, %%ecx;"
        "je _ADD;"

        "cmp $45, %%ecx;"
        "je _SUBTRACT;"

        "cmp $42, %%ecx;"
        "je _MULTIPLY;"

        "cmp $47, %%ecx;"
        "je _DIVIDE;"

        "cmp $37, %%ecx;"
        "je _MODULO;"

        "jmp _RETURN;"

        "_ADD:"
        "mov %%edx, %%eax;"
        "add %%ebx, %%eax;"
        "jmp _RETURN;"

        "_SUBTRACT:"
        "mov %%edx, %%eax;"
        "sub %%ebx, %%eax;"
        "jmp _RETURN;"

        "_MULTIPLY:"
        "mov %%edx, %%eax;"
        "imul %%ebx;"
        "jmp _RETURN;"

        "_DIVIDE:"
        "mov %%edx, %%eax;"
        "mov $0, %%edx;"
        "cdq;"
        "idiv %%ebx;"
        "jmp _RETURN;"

        "_MODULO:"
        "mov %%edx, %%eax;"
        "mov $0, %%edx;"
        "cdq;"
        "idiv %%ebx;"
        "mov %%edx, %%eax;"
        "jmp _RETURN;"

        "_RETURN:"
        :
        :"d" (a), "b" (b), "c" (op)
    );
}
#endif // EXPERIMENTAL


#ifndef EXPERIMENTAL
int calc(int a, int b, int op) {

    switch ((char)op) {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;
        break;

    case '/':
        return a / b;
        break;

    case '%':
        return a % b;
        break;

    default:
        return 0;
    }
    return 0;
}
#endif // NOT EXPERIMENTAL


int main()
{
    while (true) {
        char op;
        int a, b;
        cin >> op;
        cin >> a >> b;
        cout << calc(a, b, (int)op) << '\n';
    }

    return 0;
}
