#include <stdio.h> 
#include <string.h> 
 
int main(void) { 
  char ap[100]; 
  gets(ap); 
  int cnt = strlen(ap); 
  int i; 
  for(i=0; i<strlen(ap); i++) { 
    if(ap[i] == '=') { 
      if(ap[i-1] == 'c') cnt--; 
      if(ap[i-1] == 's') cnt--; 
      if(ap[i-1] == 'z') { 
        cnt--; 
        if(ap[i-2] == 'd') cnt--; 
     } 
  } 
  if(ap[i] == '-') { 
    if(ap[i-1] == 'c') cnt--; 
    if(ap[i-1] == 'd') cnt--; 
 } 
 if(ap[i] == 'j') { 
   if(ap[i-1] == 'l') cnt--; 
   if(ap[i-1] == 'n') cnt--; 
} 
} 
printf("%d\n", cnt); 
}