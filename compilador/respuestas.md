Pasos compilación:
1  Pre-procesador: make preprocessing

Se encarga de las directivas como #include, #define. Lee los archivos donde las fcs de stdio están declaradas. Copia código de los archivos de las librería calculator.h y stdio.h arriba del código escrito en c calculator.c y crea file calculator.pp_c

2  Compilacion I: make assembler

Genera código assembler y realiza las optimizaciones de hardware. Funciones main y add_numbers.
Crea file calculator.asm


3  Compilacion II: make object

Genera el objeto en código binario, crea file calculator.o

ctpc17@debian:~/Vane/HOcompiled/compilador$ nm calculator.o
000000000000003e T add_numbers
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U printf

T: Funciones globales
U:undefined reference to printf in fuction main, se define durante el linkeo.

4  Linkeo: make executable

Crea el ejecutable calculator.e

ctpc17@debian:~/Vane/HOcompiled/compilador$ nm calculator.e
00000000000006ee T add_numbers
0000000000201030 B __bss_start
0000000000201030 b completed.6963
                 w __cxa_finalize@@GLIBC_2.2.5
0000000000201020 D __data_start
0000000000201020 W data_start
00000000000005b0 t deregister_tm_clones
0000000000000640 t __do_global_dtors_aux
0000000000200de0 t __do_global_dtors_aux_fini_array_entry
0000000000201028 D __dso_handle
0000000000200df0 d _DYNAMIC
0000000000201030 D _edata
0000000000201038 B _end
0000000000000784 T _fini
0000000000000680 t frame_dummy
0000000000200dd8 t __frame_dummy_init_array_entry
0000000000000928 r __FRAME_END__
0000000000201000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000000007bc r __GNU_EH_FRAME_HDR
0000000000000530 T _init
0000000000200de0 t __init_array_end
0000000000200dd8 t __init_array_start
0000000000000790 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
0000000000200de8 d __JCR_END__
0000000000200de8 d __JCR_LIST__
                 w _Jv_RegisterClasses
0000000000000780 T __libc_csu_fini
0000000000000710 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
00000000000006b0 T main
                 U printf@@GLIBC_2.2.5
00000000000005f0 t register_tm_clones
0000000000000580 T _start
0000000000201030 D __TMC_END__
    
¿En qué se diferencian los símbolos del objeto y del ejecutable?
En el ejecutable se definen funciones de las librerías copiadas por el preprocesador. Por ejemplo en el ejecutable printf f aparece definida por la librería incluída en el soname GLIBC.
