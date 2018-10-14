
#include <stdio.h>
void convertToBase(int base, int number)
{
    //Mảng chứa các chữ số của hệ 16  [hex]
    char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char output[100];
    int i=0;
    while(number>0)
    {
        output[i++] = digits[number%base];
        number = number/base;
    }
    i--;
    //Xuất ra kết quả
    for(;i>=0;i--) printf("%c",output[i]);
}
void convertToBaseRec(int base, int number)
{
    char digits[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(number<=0)
    {
        return;
    }
    //Gọi đệ quy hàm convertToBaseRec()
    convertToBaseRec(base,number/base);
    //Xuất kết quả ra màn hình
    printf("%c",digits[number%base]);
}
void chuyendoi(int so,int he)
{
    if (so>=he) chuyendoi(so/he,he);
    printf("%c",(so%he)["0123456789ABCDEF"]);

}

int main()
{
    int base = 1 ; int number;
    printf("Nhap so muon chuyen doi : ");
    scanf("%d",&number);

    // Chỉ chấp nhận hệ cơ số từ 2 (bit) tới 16 (HEX)

    while(base>16 || base<2)
    {
        printf("Nhap co so: ");
        scanf("%d",&base);
    }

    //Theo phương pháp lặp while
    //printf("\nKet qua chuyen doi (su dung ham tuan tu) : ");
    //convertToBase(base,number);

    //Theo phương pháp đệ quy
    printf("\nKet qua chuyen doi (su dung ham de quy) : ");
    convertToBaseRec(base,number);
}

