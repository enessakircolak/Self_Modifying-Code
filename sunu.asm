
.code

MySegment segment read write execute

sunu proc
	mov eax, ecx  ;

	mov dword ptr deli, 9005e883h


deli:
	add eax, 5	  
	nop
	ret


sunu endp

MySegment ends

end
