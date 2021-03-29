.686
.model flat

.data
pi dd 180
eps dd ?
result dd 0
count dd 1
iks dd 0
fact dd 1.0
item dd 0
.code


_Arcsin proc
FINIT
FLD dword ptr [esp+4]
FLD dword ptr [esp+4]
FMUL 
FLD1
FSUBR
FSQRT
FLD dword ptr [esp+4]
FDIVR
FLD1
FPATAN
FILD pi
FMUL
FLDPI
FDIV
FRNDINT
FIST pi
mov eax, pi

ret
_Arcsin endp




_Task2 proc
FINIT
FLD dword ptr[esp+8]
FSTP eps
FLD dword ptr[esp+4]
FST iks
FST item
FSTP result
FINIT

_begin:
FLD fact
FLD iks
FLD item
FLD eps
FCOM 
FSTSW AX
SAHF
jnbe _end
FSTP eps
FSTP item
FLD dword ptr[esp+4]
FLD dword ptr[esp+4]
FMULP
FMULP
FST iks
lea eax, iks
FXCH
inc count
FILD count
inc count
FILD count
FMUL
FMUL
FST fact
FDIV
FST item
FLD result
FADD
FST result
FINIT
jmp _begin

_end:
FLD result
ret
_Task2 endp

end