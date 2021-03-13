#include <iostream>

int main()
{
    int a, b, c, y;
    int one = 1;
    int ndiv, nmod, temp, mult, ndiv1, nmod1, temp1, mult1;
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
        mov temp1, eax;
        mov ecx, eax;   // ecx == 3a, temp == 3a


        neg ebx;
        mov mult, ebx;
        mov mult1, ebx;
        mov eax, ebx;
        cdq;
        idiv ecx;
        mov ndiv, eax;
        mov ndiv1, eax;
        mov nmod1, edx;
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
        add eax, ebx;
        mov temp, eax;
        mov ebx, eax;
        cdq;
        mov esi, 2;
        idiv esi;
        cmp edx, 0;
        jne _eq2_end;
        mov ndiv, ebx;
        jmp _end_method1;
        _eq2_end:;
        _less6_end:;

        jnl _less7_end;
        mov eax, ndiv;
        mov ebx, one;
        sub eax, ebx;
        mov temp, eax;
        mov ebx, eax;
        cdq;
        mov esi, 2;
        idiv esi;
        cmp edx, 0;
        jne _eq3_end;
        mov ndiv, ebx;
        jmp _end_method1;
        _eq3_end:;
        _less7_end:;

        _end_method1:
        _eq1_end:;



        mov eax, mult1;
        mov ebx, temp1;
        cmp eax, 0;
        jnl _less100_end;
        cmp ebx, 0;
        jng _great100_end;
        mov eax, ndiv1;
        cmp eax, 0;
        jne _eq100_end;
        mov eax, nmod1;
        imul eax, -2;
        cmp eax, temp1;
        jng _great101_end;
        mov eax, -1;
        mov ndiv, eax;
        _great101_end:;
        jnl _less_101_end;
        mov eax, 0;
        mov ndiv, eax;
        _less_101_end:;
        _great100_end:;
        _less100_end:;
        _eq100_end:;

        mov eax, mult1;
        mov ebx, temp1;
        cmp eax, 0;
        jng _great102_end;
        cmp ebx, 0;
        jnl _less102_end;
        mov eax, ndiv1;
        cmp eax, 0;
        jne _eq101_end;
        mov eax, nmod1;
        imul eax, 2;
        cmp eax, temp1;
        jnl _less103_end;
        mov eax, -1;
        mov ndiv, eax;
        _less103_end:;
        jng _great_103_end;
        mov eax, 0;
        mov ndiv, eax;
        _great_103_end:;
        _less102_end:;
        _great102_end:;
        _eq101_end:;
    }

    std::cout << "\"x\" after rounding = " << ndiv << std::endl;
    return 0;
}