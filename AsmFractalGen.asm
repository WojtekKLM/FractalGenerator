.CODE

mandelbrot_calculation PROC C
    ; Obliczenie punktu Mandelbrota dla danego punktu (x, y)
    ; w przestrzeni o szerokoœci WIDTH i wysokoœci HEIGHT
    ; rcx = x
    ; rdx = WIDTH
    ; r8 = y
    ; r9 = HEIGHT
    ; xmm0 = result

    mov R10, RDX        ; przekopiuj pointer na tablicê wyników do R10
    mov RDX, [RCX+4]    ; przekopiuj wartoœæ, na któr¹ wskazuje pointer
    mov R8D, [RCX+8]
    mov R9D, [RCX+12]
    mov ECX, [RCX]      ; na koñcu zast¹p pointer w rejestrze RCX wartoœci¹m na któr¹ wskazuje
                        ; ten pointer. Pointer na strukturê intów nie bêdzie ju¿ potrzebny

    ; x = x - WIDTH / 2
    mov eax, edx        ; rax = WIDTH
    sar rax, 1          ; rax = WIDTH/2
    sub rcx, rax        ; rdi = x - WIDTH/2

    ; x = x * 4.0
    mov rax, rcx        ; rax = x - WIDTH/2
    shl rax, 2          ; rax = (x - WIDTH/2) * 4
    cvtsi2sd xmm1, rax  ; xmm1 = (double) (x - WIDTH/2) * 4.0

    ; x = x / WIDTH
    mov eax, edx        ; rax = WIDTH
    cvtsi2sd xmm2, rax  ; xmm2 = (double) WIDTH
    divsd xmm1, xmm2    ; xmm1 = xmm1 / xmm2 (x - WIDTH/2) * 4.0 / WIDTH

    movq rax, xmm1      ; przekopiuj wartoœci z rejestru do akumulatora 
    mov [r10], rax      ; przekopiuj wartoœci z akumulatora na wartoœæ wskazywan¹ przez pinter

    ; y = y - HEIGHT / 2
    mov rax, r9         ; rax = HEIGHT
    sar rax, 1          ; rax = HEIGHT/2
    sub r8, rax         ; rdx = y - HEIGHT/2

    ; y = y * 4.0
    mov rax, r8         ; rax = y - HEIGHT/2
    shl rax, 2          ; rax = (y - HEIGHT/2) * 4
    cvtsi2sd xmm3, rax  ; xmm3 = (double) (y - HEIGHT/2) * 4.0
    ;mulsd xmm3, xmm0   ; xmm3 = xmm0 * (y - HEIGHT/2) * 4.0

    ; y = y / HEIGHT
    mov rax, r9         ; rax = HEIGHT
    cvtsi2sd xmm4, rax  ; xmm4 = (double) HEIGHT
    divsd xmm3, xmm4    ; xmm3 = xmm3 / xmm4 (y - HEIGHT/2) * 4.0 / HEIGHT

    movq rax, xmm3      ; przekopiuj wartoœci z rejestru do akumulatora 
    mov [R10+8], rax    ; przekopiuj wartoœci z akumulatora na wartoœæ wskazywan¹ przez pinter

    ; Zwrócenie wyniku w xmm0 
    ret 

mandelbrot_calculation ENDP
end

