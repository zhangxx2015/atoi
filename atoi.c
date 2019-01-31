// 试着写了一下
#include <stdio.h>
int atoi(char* pstr) {
    int intVal = 0;              // 返回值
    int sign = 1;                // 符号, 正数为 1, 负数为 -1
    if(pstr == 0) return 0;      // 判断指针是否为空 pstr == NULL
    while(' '== *pstr) pstr++;   // 跳过前面的空格字符 ' ' 的 ascii 值 0x20
    if('-'==*pstr) sign = -1;    // 判断正负号
    if('-'==*pstr || '+'==*pstr) pstr++;// 如果是符号, 指针后移
    while(*pstr >= '0' && *pstr <= '9') {// 逐字符转换成整数
        // 转换说明
        // ascii 的 '0' = 0x30 转换为int以后 - 0x30即为整型的0
        // ascii 的 '1' = 0x31 转换为int以后 - 0x30即为整型的1
        // ...
        intVal = intVal * 10 + (((int)*pstr)-0x30);// 十进制即每位乘10, 结果累加保存
        pstr++;// 指针后移
    }
    intVal *= sign;// int32 范围是: 2147483647 ~ -2147483648, 此片会进行溢出运算
    return intVal;// 返回结果
}
 
void main(){
    const int count = 4;
    char inputs[count][13] = {"2147483647\0","-2147483648\0","9999999999\0","-9999999999\0"};
    int i=0;
    int ret=0;
    for(i=0;i<count;i++){
        ret=atoi(inputs[i]);
        printf("\"%s\" value is %d\n",inputs[i],ret);
    }
    getchar();
}
