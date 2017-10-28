#include<stdio.h>
#include<stdlib.h>

int main(){
    int result = fatorial(5);
    printf("result of fatorial: %d", result);
    exit(0);
}

int fatorial(int number){
    printf("called with number: %d \n",number);
    if(number <= 1 ){
        printf("minor");
        return 1;
    }
    printf("%d\n", number);
    return number * fatorial(number - 1);
    exit(0);
}
