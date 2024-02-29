#include <stdio.h>

#define  MAX_LEN  1024

int main(void){
    FILE *stream;
    char string[MAX_LEN], table[3][3];
    int count, i, j;
 
    stream = fopen("input.txt","rb");
 
    for(i = 0; i < 3; i++) {
        fgets(string, MAX_LEN, stream);
        for(j = 0; j < 3; j++) {
            table[i][j] = string[j];
        }
    }
 
    if (fclose(stream))
        perror("fclose error");
    
    count = 0;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (table[i][j] == 'x') {
                break;
            } else if (j == 2) {
                count++;
            }
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (table[j][i] == 'x') {
                break;
            } else if (j == 2) {
                count++;
            }
        }
    }
    
    for (i = 0; i < 3; i++) {
        if (table[i][i] == 'x') {
            break;
        } else if (i == 2) {
            count++;
        }
    }
    
    for (i = 0; i < 3; i++) {
        if (table[i][2-i] == 'x') {
            break;
        } else if (i == 2) {
            count++;
        }
    }
    
    if (count >= 1) {
        printf("%d BINGO!!", count);
    }else{
        printf("No BINGO...");
    }
}
