#include<stdio.h>

int even_partiy(int value,int n_bits)
{
  int parity = 0;
  /*
   * 计算值中值为1的个数
   */
   while(n_bits>0){
    //逻辑运算 然后对结果求和，即有几个1;
    parity += value & 1;
    value >>= 1;
    n_bits -= 1;
   }
   
   
   /*
    * 如果计数器的最低位为0，返回TRUE(表示1的位数为偶数个）
    */
    return (parity%2) == 0;
    
}    
