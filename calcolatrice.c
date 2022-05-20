#include <stdio.h>

int main(void) {
    int x;
    char operando, mod;
    double op1, op2;
    char nome_file[50];
    FILE *file_read, *file_write;
    printf("Selezionare modalità programma: File o Input(F/I): ");
    scanf(" %c", &mod);
    switch (mod) {
        case 'I' :
            printf("Selezionare operando (/, *, -, +): ");
            scanf(" %c", &operando);
            printf("Inserire primo numero: ");
            scanf("%lf", &op1);
            printf("Inserire secondo numero: ");
            scanf("%lf", &op2);
            double risultato;
    switch (operando) {
        case '/':
            risultato = op1 / op2;
            printf("Il tuo risultato è: %.2lf", risultato );
            break;
        case '*':
            risultato = op1 * op2;
            printf("Il tuo risultato è: %.2lf", risultato);
            break;
        case '-':
            risultato = op1 - op2;
            printf("Il tuo risultato è: %.2lf", risultato);
            break;
        case '+':
            risultato = op1 + op2;
            printf("Il tuo risultato è: %.2lf", risultato);
            break;
        default:
            printf("Errore! Operatore invalido");
            break;
    }
  return 0;
            break;
        case 'F' :
            printf("Inserire nome file: ");
            file_read=scanf("%s", nome_file);
            printf("%s", nome_file);
            file_write= fopen("Result.txt", "w");
            file_read = fopen(nome_file,"r");
            if (file_read == NULL) { 
                printf("Errore nell'apertura del file! (nome invalido)");
                return 0;
            }else {
                do {
                    fscanf(file_read, "%c", &operando);
                    fscanf(file_read, "%lf", &op1);
                    fscanf(file_read, "%lf", &op2);
                    printf("%c %lf %lf", operando, op1, op2);
                    double risultato;
    switch (operando) {
        case '/':
            risultato = op1 / op2;
            fprintf(file_write,"%c %.2lf\n", operando, risultato);
            break;
        case '*':
            risultato = op1 * op2;
            fprintf(file_write,"%c %.2lf\n", operando, risultato);
            break;
        case '-':
            risultato = op1 - op2;
            fprintf(file_write,"%c %.2lf\n", operando, risultato);
            break;
        case '+':
            risultato = op1 + op2;
            fprintf(file_write,"%c %.2lf\n", operando, risultato);
            break;
        default:
            printf("Errore! Operatore invalido");
            break;
    }
                }while(!feof(file_read)&&fscanf(file_read, "%c", &operando)!='\n');
                return 0;
            }
        default:
            printf("Carattere digitato invalido!");
    }
    return 0;
}