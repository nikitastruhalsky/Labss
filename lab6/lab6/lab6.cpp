#include <iostream>

extern "C"
{
    bool IsMagicSquare(short* square, int N);
}


int main()
{
    /*short* arr = new short [9];
    for (int i = 0; i < 9; i++)
    {
        arr[i] = 25;
    }
    std::cout << IsMagicSquare(arr, 3) << std::endl;*/


    int n = 3;
    short s1 = 0;
    int flag = 0;
    short res = 102;
    short** matrix = new short* [n];
    int count = 0;
    int s11 = 0;
    for (int i = 0; i < n; i++)
    {
        switch (i)
        {
         case 0:
            matrix[i] = new short[] {1, 1, 1};
            break;
         case 1:
             matrix[i] = new short[] {1, 1, 1};
             break;
         case 2:
             matrix[i] = new short[] {1, 1, 1};
             break;
        }
    }

    __asm
    {
        mov ax, 0;
        mov ebx, matrix;                адрес начала строки
        mov ecx, n;                     счетчик внешнего цикла по строкам
        begin_n:
        push ecx;                       сохранение счетчика внешнего цикла
        mov ecx, n;                     счетчик внутреннего цикла по
        ;                               элементам строки
        mov esi, dword ptr [ebx];       индекс текущего элемента строки
        begin_m:
        add ax, word ptr[esi];
        add esi, 2
        loop begin_m;


        mov edx, flag;
        cmp edx, 0;
        je _notcompare;
        cmp ax, s1;
        jne _end;
        mov s1, ax;
        mov ax, 0;
        jmp next;
        _notcompare:;
        mov s1, ax;
        mov edx, 1;
        mov flag, edx;
        next:;
        mov ax, 0;
        add ebx, 4;         переход к началу следующей строки
        pop ecx;            восстановление счетчика внешнего цикла
        loop begin_n
        jmp correct;
        _end:;
        pop ecx;
        mov ax, 0;
        mov res, ax;
        jmp _end1;
        correct:;
        mov ax, 1;
        mov res, ax;
        _end1:;
    }

    std::cout << res << std::endl;


    _asm
    {
        mov s1, 0;
        mov ax, 0;
        mov ebx, matrix;
        mov ecx, n;
        mov flag, 0;
        begin_0:;
        mov ebx, matrix;
        mov ax, 0;
        push ecx;
        mov ecx, n;
        begin_1:;
        mov esi, dword ptr[ebx];
        add esi, count;
        add ax, word ptr[esi];
        add ebx, 4;
        loop begin_1;
        cmp flag, 0;
        je _notcompare2;
        cmp s1, ax;
        jne _end20;
        mov s1, ax;
        add count, 2;
        pop ecx;
        loop begin_0;
        jmp pobeda;
        _notcompare2:;
        mov s1, ax;
        mov flag, 1;
        add count, 2;
        pop ecx;
        loop begin_0;

        _end20:;
        mov res, 0;
        pop ecx;
        jmp _end234;
        pobeda:;
        mov res, 1;
        _end234:;
    }

    std::cout << res << std::endl;
    
    
    _asm
    {
        mov count, 0;
        mov ax, 0;
        mov ebx, matrix;
        mov ecx, n;
        begin_007:;
        mov esi, dword ptr[ebx];
        add esi, count;
        add ax, word ptr[esi];
        add ebx, 4;
        add count, 2;
        loop begin_007;
        cmp s1, ax;
        jne _end2000;
        jmp pobeda12345;
        _end2000:;
        mov res, 0;
        jmp _end23400;
        pobeda12345:;
        mov res, 1;
        _end23400:;
    }

    std::cout << res << std::endl;

    _asm
    {
        sub n, 1;
        mov eax, n;
        mov ecx, 2;
        mul ecx;
        mov count, eax;
        mov ax, 0;
        mov ebx, matrix;
        add n, 1;
        mov ecx, n;
        begin_0078910:;
        mov esi, dword ptr[ebx];
        add esi, count;
        add ax, word ptr[esi];
        add ebx, 4;
        sub count, 2;
        loop begin_0078910;
        cmp s1, ax;
        jne _end20000000;
        jmp pobeda123456789;
        _end20000000:;
        mov res, 0;
        jmp _end234000000;
        pobeda123456789:;
        mov res, 1;
        _end234000000:;
    }

    std::cout << res << std::endl;
    return 0;
}
