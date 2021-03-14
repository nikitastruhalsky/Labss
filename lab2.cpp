#include <iostream>

int main()
{

    ////////////////    TASK 1      /////////////////////////

    long long int a = 3000000000, b = 3000000000, c = 2000000000, res = 0;
    int result = 0;
    _asm
    {
        mov eax, dword ptr a
        add eax, dword ptr b;           вычесть младшие половинки чисел
        mov dword ptr res, eax;         младшая часть результата
        mov eax, dword ptr a + 4;
        adc eax, dword ptr b + 4;       вычесть старшие половинки чисел
        mov dword ptr res + 4, eax;     старшая часть результата


        mov eax, dword ptr res;
        mov edx, dword ptr res + 4;
        cmp edx, dword ptr c + 4;
        jne _islater;
            cmp eax, dword ptr c;
        _islater:;
        jbe _later;
            mov eax, 1;
            mov result, eax;
        _later:;
    }

    if (result != 1)
    {
        std::cout << "No!" << std::endl;
    }
    else
    {
        _asm
        {
            mov eax, dword ptr b
            add eax, dword ptr c;           вычесть младшие половинки чисел
            mov dword ptr res, eax;         младшая часть результата
            mov eax, dword ptr b + 4;
            adc eax, dword ptr c + 4;       вычесть старшие половинки чисел
            mov dword ptr res + 4, eax;     старшая часть результата


            mov eax, dword ptr res;
            mov edx, dword ptr res + 4;
            cmp edx, dword ptr a + 4;
            jne _islater1;
                cmp eax, dword ptr a;
            _islater1:;
            jbe _later1;
                mov eax, 1;
                mov result, eax;
            _later1:;
        }

        if (result != 1)
        {
            std::cout << "No!" << std::endl;
        }
        else
        {
            _asm
            {
                mov eax, dword ptr b
                add eax, dword ptr c;           вычесть младшие половинки чисел
                mov dword ptr res, eax;         младшая часть результата
                mov eax, dword ptr b + 4;
                adc eax, dword ptr c + 4;       вычесть старшие половинки чисел
                mov dword ptr res + 4, eax;     старшая часть результата


                mov eax, dword ptr res;
                mov edx, dword ptr res + 4;
                cmp edx, dword ptr a + 4;
                jne _islater2;
                    cmp eax, dword ptr a;
                _islater2:;
                jbe _later2;
                    mov eax, 1;
                    mov result, eax;
                _later2:;
            }
            if (result != 1)
            {
                std::cout << "No!" << std::endl;
            }
            else
            {
                std::cout << "Yes!" << std::endl;
            }
        }
    }




    ////////////////    TASK 2  ///////////////////

    int res2[3] = {0, 0, 0};
/*    res2[0] = 0;
    res2[1] = 0;
    res2[2] = 0;*/
    int n;
    std::cout << "Enter a number of elements: ";
    std::cin >> n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr1[i];
        std::cin >> arr2[i];
    }

    __asm
    {
        mov edi, arr1;
        mov esi, arr2;
        mov ecx, 0;
        _begin:;
        cmp ecx, n;
        je _end;
        mov ebx, dword ptr[edi];
        mov eax, dword ptr[esi];
        imul ebx;
        add edi, 4;
        add esi, 4;
        mov edx, 0;
        add [res2], eax;
        adc [res2 + 4], edx;
        adc [res2 + 8], 0;
        inc ecx;
        jmp _begin;
        _end :;
    }
    std::cout << res2[0] << std::endl;
    return 0;
}
