#include <iostream>

int main()
{
    int a, b, c, y;
    int one = 1;
    int ndiv, nmod, temp, mult;
    std::cout << "Enter a, b, c, y: ";
    std::cin >> a >> b >> c >> y;
    _asm
    {
        mov eax, b;
        mov ebx, y;
        imul ebx;
        mov ecx, c;
        add eax, ecx;
        mov ebx, eax;   // ebx == by + c


        mov eax, a;
        mov esi, 3;
        imul esi;
        mov temp, eax;
        mov ecx, eax;   // ecx == 3a, temp == 3a


        neg ebx;
        mov mult, ebx;
        mov eax, ebx;
        cdq;
        idiv ecx;
        mov ndiv, eax;
        cmp edx, 0;
        jnl _less1_end;
        neg edx;
        _less1_end:;
        mov nmod, edx;  // остаток всегда неотрицательный
    }

    std::cout << mult << " : " << temp << " = " << ndiv << " (ostatok: " << nmod << ")" << std::endl;


    _asm
    {
        mov eax, temp;
        cdq;
        mov ebx, 2;
        idiv ebx;
        cmp eax, 0;
        jnl _less2_end;
        neg eax;        // eax == 3a / 2 (not a negative)
        _less2_end:;
        mov temp, eax;


        mov ebx, nmod;
        cmp eax, ebx;

        jnl _less3_end;
        cmp ndiv, 0;
        jnl _less4_end;
        mov eax, ndiv;
        mov ebx, one;
        sub eax, ebx;
        mov ndiv, eax;
        jmp _end_method1;
        _less4_end:;
        mov eax, ndiv;
        mov ebx, one;
        add eax, ebx;
        mov ndiv, eax;
        jmp _end_method1;
        _less3_end:;

        jne _eq1_end;
        cmp ndiv, 0;
        jl _less6_end;
        mov eax, ndiv;
        mov ebx, one;
        sub eax, ebx;
        mov temp, eax;
        cdq;
        mov esi, 2;
        idiv esi;
        cmp edi, 0;
        jne _eq2_end;
        mov ndiv, eax;
        jmp _end_method1;
        _eq2_end:;

        mov eax, ndiv;
        mov ebx, one;
        add eax, ebx;
        mov temp, eax;
        cdq;
        mov esi, 2;
        idiv esi;
        cmp edi, 0;
        jne _eq3_end;
        mov ndiv, eax;
        jmp _end_method1;
        _eq3_end:;

        _end_method1:
        _eq1_end:;
        _less6_end:;
    }

    std::cout << "\"x\" after rounding = " << ndiv << std::endl;
    return 0;
}