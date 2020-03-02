/*
 *这个程序从标准输入中读取输入行并在标准输出中打印这些输入行
 *输入的第一行：一串列标号，串的最后一行以负数结尾
 *4 9 12 20 -1
 *表示打印输入字符串的第4列到第9列+第12列到第20列+'\0'
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20        /*所能处理的最大列号*/
#define MAX_INPUT 1000     /*每个输入行的最大长度也意味着输出行也只能处理这么多*/

int read_column_numbers(int columns[],int max);
void rearrange(char *output,char const *input,int n_columns,int const columns[]);

int main(void)
{
	int n_columns;             //进行处理的列表号
	int columns[MAX_COLS];     //需要处理的列数
	char input[MAX_INPUT];      //容纳输入字符串的数组
	char output[MAX_INPUT];     //容纳输出字符串的数组

	/*
	 * 读取该串列表号
	 * 即用户输入的数字对
	 */
  printf("Please input array number:\n");
	n_columns = read_column_numbers(columns,MAX_COLS);

	/*
	 *读取、处理和打印剩余的输入行
	 */
	while(gets(input)!=NULL){
		printf("Original input:%s\n",input);
		rearrange(output,input,n_columns,columns);
		printf("Rearranged line:%s\n",output);
	}
	return EXIT_SUCCESS;
}

/*
*读取列表号 如果超出规定范围则不予理会
*para1:读取数据所存储的数组
*para2：MAX_COLS
*return:有效列表号
*/
int read_column_numbers(int columns[],int max)
{
	int num = 0;
	int ch;

	/*取得列表号 如果所读取的数小于0 则停止
	*Condition1: 字符串大小必须小于MAX_COLS
	*Condition2: 判断成功录入一个数字
	*Condition3：判断是否终止符-1
	*/
	while(num < max && scanf("%d",&columns[num]) == 1 && columns[num] >= 0)
		num += 1;

	/*
	*确认已经读取的标号的个数为偶数
	*BeginIndex EndIndex ... EndFlag(Invalid)
	*非偶数 告知错误信息 退出
	*/
	if(num % 2 != 0){
		puts("Lst column number is paired.");
		exit(EXIT_FAILURE);
	}

	/*
	*丢弃该行中包含最后一个数字的那部分内容
	*此种情况：一般输入完毕之后 我们都会按Enter键结束 
	*此目的就是消除这类内容
	*此写法常见 建议记住
	*/
	while((ch = getchar())!=EOF&&ch!='\n')
		;

	return num;
}


/*
* 处理输入行，将指定列（即我们的输入数字）的字符连接在一起，输出行一NUL结尾。
*parameter1：最终形成的字符串
*parameter2：用户输入的字符串 不可修改
*parameter3：用户输入数字的个数，即函数read_column_number();
*parameter4: 用户输入数字数组
*void 无返回值
*/
void rearrange(char *output,char const *input,int n_columns,int const columns[])
{
	int col;        //columns数组的下标
	int output_col; //输出列计数器：即输出字符个数统计
	int len;        //输入字符串的长度

	len = strlen(input);    //字符串长度
	output_col = 0;

	/*
	*处理每对列标号
	*/
	for(col = 0;col < n_columns;col+=2){
		//计算每对列表号之间的字符个数
		int nchars = columns[col+1]-columns[col]+1;

		/*
		 * 如果输入字符串长度没有那么长(即长度小于数组数据),则跳过这个范围
		 *即ByeBye，而数据要求从9-20，则进行此操作
		 */
		if(columns[col]>=len)
			continue;

		/*
		*如果输出行数组已满，结束任务
		*/
		if(output_col==MAX_INPUT-1)
			break;

		/*
		*如果输出行数据空间不够，只复制可以容纳的数据
		*/
		if(output_col + nchars > MAX_INPUT-1)
			nchars = MAX_INPUT-output_col - 1;

		/*
		 *观察输入行中多少个字符在这里范围里面，如果小于nchars，对nchars的值进行调整
		 *即如果只有ByeBye，而数据要求4-10，则进行此操作
		 */
		if(columns[col] + nchars - 1 >= len)
			nchars = len - columns[col];

		/*
		*复制相关数据并记录更新输出字符个数
		*/
		strncpy(output+output_col,input+columns[col],nchars);
		output_col += nchars;
	}
	//字符串结束标志设定
	output[output_col]='\0';

}
