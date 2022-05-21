#include <stdio.h>

int compress(FILE *in, FILE *out) {
  int count = 0;
  char save, current;

  current = fgetc(in);
  do {
    save = fgetc(in);
    if (save == current && count < 9) {
      count++;
    } else if (count == 1) {
      fputc(current, out);
      fputc(current, out);
      count=0;
    } else if (!count){
      fputc(current, out);
    } else{
        fputc(current, out);
        fputc('$', out);
        fprintf(out, "%i", count);
        count = 0;
        }
    current=save;
    }while (!feof(in));
  return count;
}

int decompress(FILE *in, FILE *out) {
  int count = 0, rip;
  char save, current, tmp;

  current = fgetc(in);
  do {
    save = fgetc(in);
    if (save != '$') {
      fputc(current, out);
      count++;
      current = save;
    } else {
      tmp = fgetc(in);
      rip = tmp - '0';
      for (int i = 0; i < rip +1; i++) {
        fputc(current, out);
        count++;
      }
      current = fgetc(in);
    }
  } while (!feof(in));
  return count;
}

int main(void) {
  char mod;
  FILE *file_in, *file_out;
  printf("Select mode: Compress(C) o Decompress(D): ");
  scanf("%c", &mod);
  switch (mod) {
  case 'C':
    file_in = fopen("Source.txt", "r");
    file_out = fopen("Compressed.txt", "w");
    compress(file_in, file_out);
    fclose(file_in);
    fclose(file_out);
    break;
  case 'D':
    file_in = fopen("Compressed.txt", "r");
    file_out = fopen("Decompressed.txt", "w");
    decomprimi(file_in, file_out);
    fclose(file_in);
    fclose(file_out);
    break;
  default:
    printf("Error Invalid Charter!");
    break;
  }
}
