#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
    int pos = -1;
	
	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line); 
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket b;
            b.position = position;
            switch(next){
                case '(':
                    b.type = ROUND;
                    break;
                case '[':
                    b.type = SQUARE;
                    break;
                case '{':
                    b.type = CURLY;
                    break;
            }
            push(opening_brackets_stack, b);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(isEmpty(opening_brackets_stack)){
                pos = position + 1;
                break;
            }
            Bracket b = pop(opening_brackets_stack);
            if(next == ')' && b.type != ROUND){
                pos = position + 1;
                break;
            }
            else if(next == ']' && b.type != SQUARE){
                pos = position + 1;
                break;
            }
            else if(next == '}' && b.type != CURLY){
                pos = position + 1;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if(pos == -1){
        printf("Success!\n");
    }
    else{
        printf("My result is:%d\n", pos);
    }
    return 0;
}
