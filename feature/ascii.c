//�ַ�ASCII����غ��� By ������(Wenwu)

#include <ascii.h>

//����ASCII���ַ���
string random_all_char()
{
	//�ַ�����ʽ��־�����ַ�
	string *all_char = ({
		" ", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", 
		"7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", 
		"L", "M", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "]", "^", "_", "`", "a", "b", 
		"c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", 
		"x", "y", "z", "{", "|", "}", "~" 
		});
	
	//����������ַ���ɵ��ַ���
	return ( all_char[random(91)] + all_char[random(91)] + all_char[random(91)] + all_char[random(91)] + all_char[random(91)] );
}

//��ȡ�ַ����и��ַ���ASCII��֮�ͳ���99������
string ascii_num(string arg)
{
	string v;
	int temp, num1, num2, num3, num4;

	//ȡ���ַ���ǰ���ַ���ASCII��
	num1 = ascii_tap[arg[0..0]];
	num2 = ascii_tap[arg[1..1]];
	num3 = ascii_tap[arg[2..2]];
	num4 = ascii_tap[arg[3..3]];

	//ASCII��֮�ͳ���99����
	temp = (num1 + num2 + num3 + num4) % 99;

	//���temp�Ƿ�Ϊһ���ֽڣ���Ϊ����99��������Χ��0~98����������ʽ��鷽��Щ���Ǻ�
	if ( temp < 10 )
		v = "0" + sprintf("%d",temp);
	else
		v = sprintf("%d",temp);

	return v;
}