#include<stdio.h>
#include <stdlib.h>

//Hàm nhập mảng
void nhapmang(int n,int *ptr){
    for(int i=0;i<n;i++){
        printf("Nhap vao phan tu thu %d :\n ",i+1);
        scanf("%d",ptr+i);
    }
}

//Hàm tra cứu phần tử x trong chuỗi.
void tracuumang(int n,int *ptr,int x)
{   
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(x==*(ptr+i))
        {
            printf("Trong mang co phan tu %d ",x);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Khong tim thay phan tu %d trong mang",x);
    }
}

int main(){
    int n1,n2,n,sum,i,j,*ptr1,*ptr2,*ptr3;

    printf("Nhap vao so phan tu mang 1 :\n"); scanf("%d",&n1); 
    ptr1 = (int *)malloc(n1 * sizeof(int));
    nhapmang(n1,ptr1);
    if (ptr1 == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }

    printf("Nhap vao so phan tu mang 2 :\n"); scanf("%d",&n2);
    ptr2 = (int *)malloc(n2 * sizeof(int));
    nhapmang(n2,ptr2);
    if (ptr2 == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }

    sum=n1+n2;
    ptr3 = (int *)malloc(sum * sizeof(int));
    if (ptr3 == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
    //Copy giá trị mảng 1 vào mảng 3
    for( i=0;i<n1;i++)
    {
        *(ptr3+i)=*(ptr1+i);
    }
    //Copy giá trị mảng 2 vào mảng 3 tiếp theo.
    for( j=n1, i=0 ;j< sum ;j++,i++)
    {   
        
        *(ptr3+j)=*(ptr2+i);
        
    }

    //In mảng sau ghi nối hai mảng 1 và 2
    printf("Mang sau khi ghep la: ");
    for (i  = 0; i < sum; i++)
    {
        printf("%3d ",*(ptr3+i));
    }
    int temp;
    //Sắp xếp mảng theo thứ tự từ nhỏ đến lớn.
    for( i=0;i<sum-1;i++)
    {
        for( j=i+1;j<sum;j++)
        {
            
            if(*(ptr3+i)>*(ptr3+j))
            {
                temp=*(ptr3+i);
                *(ptr3+i)=*(ptr3+j);
                *(ptr3+j)=temp;
            }

        }
    }
    //In mảng từ nhỏ đến lớn.
    printf("\nMang tu nho den lon la : ");
    for ( i = 0; i < sum; i++)
    {
        printf("%3d ",*(ptr3+i));
       
    }
     printf("\n");

     //In mảng từ lớn đến nhỏ.
    printf("\nMang tu lon den nho la : ");
    for ( i = sum-1; i >=0; i--)
    {
        printf("%3d ",*(ptr3+i));
       
    }
     printf("\n");

    printf("Nhap vao so can tim trong mang  : ");
    scanf("%d",&n);

    tracuumang(sum,ptr3,n);
         
    free(ptr1);
    free(ptr2);
    free(ptr3);
    
    return 0;
}
