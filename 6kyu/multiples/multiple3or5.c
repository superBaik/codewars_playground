

#include <stdio.h>
#include <stdlib.h>

int solution(int number) {
    if (number < 0) return 0; // 

    int sum = 0;

    for (int i = 1; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) { // 3,5 multiple
            sum += i;
        }
    }

    return sum;
}





int main(){

    solution(10);
    printf("\n%d\n",solution(10));
    printf("======\n");
    return 0;
}