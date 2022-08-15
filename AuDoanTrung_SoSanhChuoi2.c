#include <stdio.h>
int tinhdodaichuoi(char x[]){
	int dem = 0;
	while(x[dem]!='\0'){
		dem++;
	}
	return dem++;
}

void xoaXuongDong(char x[]){
	size_t len = tinhdodaichuoi(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}
 
int main() {
   char str1[50];     
   char str2[50];
    
   int n = 0;
   short status = 1;
    
    printf("Nhap chuoi s1: ");
    fgets(str1,sizeof(str1),stdin);
    xoaXuongDong(str1);

    printf("Nhap chuoi s2: ");
    fgets(str2,sizeof(str2),stdin);
    xoaXuongDong(str2);
     
   
   while (str1[n] != '\0') {
      if(str1[n] != str2[n]) {
         status = 0;
         break;
      }
      n++;
   }
     
   if(status == 1) {
      printf("Chuoi %s va chuoi %s la giong nhau.", str1, str2);
   }else {
      printf("Chuoi %s va chuoi %s la khac nhau.", str1, str2);
   }
 
   return 0;
}