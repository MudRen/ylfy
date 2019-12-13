//tomud

int main(object me, string arg)
{
	string msg;
	int i, number, *nums;

	msg = "ºìÇò£º";
	nums = ({});

	for ( i=0; i<6; i++ )
	{
		number = random(34);
		if ( number<1 ) 
		{
			i++;
			continue;
		}
		if ( member_array(number, nums) != -1 )
		{
			i++;
			continue;
		}
		nums += ({ number });
		msg = msg + number + "¡¢";
		if ( i == 5 ) msg += "\nÀ¶Çò£º";
	}

	while ( number = random(17) )
	{
		if ( number ) break;
	}

	msg = msg + number + "\n";
	write(msg);
	return 1;
}