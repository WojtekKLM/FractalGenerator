.CODE

mandelbrot_calculation PROC
    ; Obliczenie punktu Mandelbrota dla danego punktu (x, y)
    ; w przestrzeni o szerokoœci WIDTH i wysokoœci HEIGHT
    ; rcx = x
    ; rdx = WIDTH
    ; r8 = y
    ; r9 = HEIGHT
    ; xmm0 = result

    ; x = x - WIDTH / 2
    mov rax, rdx ; rax = WIDTH
    sar rax, 1   ; rax = WIDTH/2
    sub rcx, rax ; rdi = x - WIDTH/2

    ; x = x * 4.0
    mov rax, rcx ; rax = x - WIDTH/2
    shl rax, 2   ; rax = (x - WIDTH/2) * 4
    cvtsi2sd xmm1, rax ; xmm1 = (double) (x - WIDTH/2) * 4.0
    mulsd xmm1, xmm0  ; xmm1 = xmm0 * (x - WIDTH/2) * 4.0

    ; x = x / WIDTH
    mov rax, rdx ; rax = WIDTH
    cvtsi2sd xmm2, rax ; xmm2 = (double) WIDTH
    divsd xmm1, xmm2   ; xmm1 = xmm1 / xmm2 (x - WIDTH/2) * 4.0 / WIDTH

    ; y = y - HEIGHT / 2
    mov rax, r9 ; rax = HEIGHT
    sar rax, 1   ; rax = HEIGHT/2
    sub r8, rax ; rdx = y - HEIGHT/2

    ; y = y * 4.0
    mov rax, r8 ; rax = y - HEIGHT/2
    shl rax, 2   ; rax = (y - HEIGHT/2) * 4
    cvtsi2sd xmm3, rax ; xmm3 = (double) (y - HEIGHT/2) * 4.0
    mulsd xmm3, xmm0  ; xmm3 = xmm0 * (y - HEIGHT/2) * 4.0

    ; y = y / HEIGHT
    mov rax, r9 ; rax = HEIGHT
    cvtsi2sd xmm4, rax ; xmm4 = (double) HEIGHT
    divsd xmm3, xmm4   ; xmm3 = xmm3 / xmm4 (y - HEIGHT/2) * 4.0 / HEIGHT

    ; Zwrócenie wyniku w xmm0 
    ret 

mandelbrot_calculation ENDP
end
