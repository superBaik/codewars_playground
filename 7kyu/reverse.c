#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 


char* reverseWords(const char* text){

    if(text==NULL) return NULL;

    int len = strlen(text);
    char* result = (char*)malloc(len+1);
    if(!result) return NULL;

    strcpy(result, text);  //Original(text) copy -> then, edit(result) 
    
    
    char* start = NULL;
    for(int i=0; i<=len ; i++){
        if(!isspace(result[i]) && start == NULL){  //this is an idea 
            start = &result[i]; // word start point 
            printf("%p", start);
        }
        if ((isspace(result[i]) || result[i] == '\0') && start){
            char* end = &result[i-1];
            while (start<end)
            {
                printf("%p", start);
                char temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end --;
            }
            start=NULL; //for next word searching 
            
        }
    }

    printf("%s\n", result);
    return result;
}


int main(){
    const char* str = "this is an example";
    char* reversed = reverseWords(str);
    if(reversed){
        printf("%s \n", reversed);
        free(reversed);
    }
    return 0;
}