.686
.model flat

.data

.code

_Mult proc
        mov edi, dword ptr [esp + 8];
        mov esi, dword ptr [esp + 4];
        mov ecx, 0;
        _begin:;
        cmp ecx, dword ptr [esp + 12];
        je _end;
        mov ebx, dword ptr[edi];
        mov eax, dword ptr[esi];
        imul ebx;
        add edi, 4;
        add esi, 4;
        mov edx, 0;
        mov ebx, dword ptr [esp + 16]
        add dword ptr [ebx + 0], eax;
        adc dword ptr [ebx + 4], edx;
        adc dword ptr [ebx + 8], 0;
        inc ecx;
        jmp _begin;
        _end:;
        ret;
_Mult endp

end