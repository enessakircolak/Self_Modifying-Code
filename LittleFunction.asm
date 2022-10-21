.code

MSegment segment read write execute

LittleFunction proc
	mov eax, ecx  ;

	mov dword ptr MyFunc, 900ae883h
	mov dword ptr MyFunc[+4h],9090c8ffh
	;mov dword ptr MyFunc[+8h],90c39090h
	mov dword ptr func , 900ae883h
	mov dword ptr func[+4h] , 9090c031h
	mov dword ptr func[+8h],90c39090h

MyFunc:
	add eax, 5	  
	nop
	nop
	add eax,5
	add eax,5
func:
    mov eax, 10
	nop
    add eax, 5
    ret
LittleFunction endp

MSegment ends

end