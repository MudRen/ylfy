//字符ASCII码相关函数 By 龙云梦(Wenwu)

#include <ascii.h>

//常用ASCII码字符表
string random_all_char()
{
	//字符串形式标志各个字符
	string *all_char = ({
		" ", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", 
		"7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", 
		"L", "M", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "]", "^", "_", "`", "a", "b", 
		"c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", 
		"x", "y", "z", "{", "|", "}", "~" 
		});
	
	//返回随机两字符组成的字符串
	return ( all_char[random(91)] + all_char[random(91)] + all_char[random(91)] + all_char[random(91)] + all_char[random(91)] );
}

//求取字符串中各字符的ASCII码之和除以99的余数
string ascii_num(string arg)
{
	string v;
	int temp, num1, num2, num3, num4;

	//取得字符串前两字符的ASCII码
	num1 = ascii_tap[arg[0..0]];
	num2 = ascii_tap[arg[1..1]];
	num3 = ascii_tap[arg[2..2]];
	num4 = ascii_tap[arg[3..3]];

	//ASCII码之和除以99求余
	temp = (num1 + num2 + num3 + num4) % 99;

	//检查temp是否为一个字节，因为除以99的余数范围是0~98，以这种形式检查方便些。呵呵
	if ( temp < 10 )
		v = "0" + sprintf("%d",temp);
	else
		v = sprintf("%d",temp);

	return v;
}