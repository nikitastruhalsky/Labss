.686
.model flat

.data

.code

_Triangle proc
        mov eax, dword ptr [esp + 4];
        mov ebx, dword ptr [esp + 8];
        add eax, ebx;
        jc _next1;
            cmp eax, dword ptr [esp + 12];
            jle _false;
        _next1:;
        mov eax, dword ptr [esp + 12];
        add eax, ebx;
        jc _next2;
            cmp eax, dword ptr [esp + 4];
            jle _false;
        _next2:;
        mov eax, dword ptr [esp + 4];
        mov ebx, dword ptr [esp + 12];
        add eax, ebx;
        jc _true;
            cmp eax, dword ptr [esp + 8];
            jle _false;
        _true:;
        mov eax, 1;
        ret;
        jmp _end;
            _false:;
            mov eax, 0;
        _end:;
        ret;
_Triangle endp

end