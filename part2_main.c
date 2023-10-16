#include <stdio.h>

int main() {
    while (1) {
        int score;
        printf("Enter a score (<= 2 to terminate): "); //Get initial input
        scanf("%d", &score);
        if (score <= 2) { // If the score is less than 2 break the main game loop
            break;
        }
        printf("Possible combinations of scoring plays:\n");
        // Loop through checking all the possible cominations 
        for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
            for (int tdFg = 0; tdFg * 7 + td2pt * 8 <= score; tdFg++) {
                for (int td = 0; td * 6 + tdFg * 7 + td2pt * 8 <= score; td++) {
                    for (int fg = 0; fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 <= score; fg++) {
                        int safety = (score - (fg * 3 + td * 6 + tdFg * 7 + td2pt * 8)) / 2;
                        if (fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 + safety * 2 == score) {
                            // Print all the cominbations
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
