#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
  int i, size, shift;

  if ( argc != 2 ){
    printf("Type in the string you want to transform\n");
    return 0;
  }
  
  char *input = argv[1];
  size = strlen(input);
  char result[size];
  
  printf("Enter the integer you would  like to shift your string\n\n\t%s\n\nEnter Here:\t", input);
  scanf("%d", &shift);

  for( i = 0; i < size; i++){
    if ( input[i] >= 65 && input[i] <= 90)
      input[i] += 32;
    else if ( input[i] >= 97 && input[i] <= 122)
      result[i] = (input[i] - 97 + shift) % 26 + 97;   
    else
      result[i] = input[i];
  }

  printf("Original string: \t\t %s\n", input);
  printf("String size: \t\t %d\n", size);
  printf("String shift(%d):\t\t %s\n", shift, result);
  return 0;
}
