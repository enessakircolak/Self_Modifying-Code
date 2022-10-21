.code

MySegment segment read write execute

SomeFunction proc
	mov eax, ecx  ;

	mov dword ptr MyFunc, 9005e883h
	mov dword ptr MyFunc[+4h],9090c0ffh	
	;mov dword ptr MyFunc[+8h],90c39090h
	mov dword ptr func , 9005e883h
	mov dword ptr func[+4h],90c39090h

MyFunc:
	add eax, 5	  ; sub eax,5
	nop			  ;nop
	nop				;inc eax
	add eax,5		;nop nop
	add eax,5		;add eax,5
	mov dword ptr func2,9090c031h
	jmp oyuk
func2:
	add eax,10   ;xor eax 
	nop
func:
    mov eax, 10  ;sub eax 5  ; inc eax
	nop			
    add eax, 5  ; ret
    ret
	ret
oyuk:
	dec eax 
	dec eax
	mov dword ptr func , 9090c0ffh
	mov dword ptr func2[+4h] ,9005e883h
	;mov dword ptr func2[+950h] ,9005e883h
	add eax,5
	sub eax,5
	jmp func2
SomeFunction endp

MySegment ends

end