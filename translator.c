#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{

    FILE* in;
    long int size;
    char * buffer;
    in=fopen("in.txt","r");
    fseek (in , 0 , SEEK_END);
    size = ftell (in);
    rewind (in);
    buffer = (char*) malloc (sizeof(char)*size);
    fread(buffer,1,size,in);



    FILE* out;
    out=fopen("out.c","w");
    fputs("#include <stdio.h>\n#include <stdlib.h>\nint main(int argc,char* argv[]){\n",out);
    fputs("char mem[1000]= {0};\nchar* p=mem;\n",out);
    for(int i=0; i<size; i++){
        switch(buffer[i])
        {
        case'+':
            fputs("(*p)++;\n",out);
            break;
        case'-':
            fputs("(*p)--;\n",out);
            break;
        case'<':
            fputs("p--;\n",out);
            break;
        case'>':
            fputs("p++;\n",out);
            break;
        case'.':
            fputs("putchar(*p);\n",out);
            break;
        case',':
            fputs("*p=getchar();\n",out);
            break;
        case'[':
               fputs("while(*p){\n",out);
            break;

        case']':
           fputs("}\n",out);
            break;
        default:
            break;
        }
    }
fputs("}\n",out);

 printf("Brainfuck code:\n");
    for(int i=0; i<size; i++)
        putchar(buffer[i]);
rewind (out);
 printf("C code:\n");
    for(int i=0; i<size; i++){

        printf("%d",fgetc(out));
        }
fclose(in);
fclose(out);
    }
