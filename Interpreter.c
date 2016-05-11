#include <stdio.h>
#include <stdlib.h>
#define MEM_S 100

void print(char*);
void execute(char** mem_ptr,char** buffer_ptr);
int main(int argc,char* argv[])
{

    FILE* data;
    long int size;
    char * buffer;
    char * buffer_ptr;

    data=fopen(argv[1],"r");

    fseek (data , 0 , SEEK_END);
    size = ftell (data);
    rewind (data);

    buffer = (char*) malloc (sizeof(char)*size);

    fread(buffer,1,size,data);

printf("Your code:\n");
    for(int i=0; i<size; i++)
        putchar(buffer[i]);

    char mem[MEM_S]= {0};
    char* mem_ptr=mem;
    print(mem);
buffer_ptr=buffer;
printf("Output:\n");

execute(&mem_ptr,&buffer_ptr);

 putchar('\n');
 print(mem);
putchar('\n');
    return 0;
}

void execute(char** mem_ptr,char** buffer_ptr)
{
while(1){
int k=0;
    char task;
    task=(*(*buffer_ptr));
    (*buffer_ptr)++;

    switch(task)
    {
    case'+':
        (*(*mem_ptr))++;
        break;
    case'-':
        (*(*mem_ptr))--;
        break;
    case'<':
        (*mem_ptr)--;
        break;
    case'>':
        (*mem_ptr)++;
        break;
    case'.':
    printf("%d ",(*(*mem_ptr)));
    // putchar(*mem_ptr);
        break;
    case',':
       (*(*mem_ptr))=getchar();
        break;
    case'[':


        while((*(*mem_ptr))){
        k++;
         char* mem_temp=*mem_ptr;
        char* buffer_temp=*buffer_ptr;
        execute(&mem_temp,&buffer_temp);
       // buffer_ptr=&buffer_temp;
                }
                (*buffer_ptr)+=k;
                k=0;
        break;

    case']':
    return;
        break;
        default:
        break;
    }
    }
return;
}


void print(char* mem)
{
    for(int i=0; i<MEM_S; i++)
        printf("%d",mem[i]);
        putchar('\n');
}
