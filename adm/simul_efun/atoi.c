//atoi.c

int atoi(string str)
{
	int v;

	if ( !stringp(str) || !sscanf(str, "%d", v) ) return 0;
	return v;
}

string float_int(float i)
{
	string strr, str, *arg;

	if ( intp(i) )
	{
		strr = sprintf("%d",i);
		return strr;
	}
	else if (floatp(i))
	{
		strr = sprintf("%f",i);
		arg = explode(strr,".");
		str = arg[0];
		return str;
	}
	else
		return 0;
}

float min_max_attnum(int a, int b, int c, int d)
{
	float aa, bb, cc, dd, v;
	int l;

	l = a + b + c + d;
	aa = to_float(a) / l;
	bb = to_float(b) / l;
	cc = to_float(c) / l;
	dd = to_float(d) / l;

	v = aa - bb - cc - dd + 1;

	return v;
}

// �� map_2 �ж� map_1 û�е�Ԫ�ؼӽ� map_1������
// һ��ͬʱ�߱����� mapping ��Ԫ�ص�mapping��
mapping maps_compose(mapping map_1, mapping map_2)
{
	string *args;
	int i;

	if ( !mapp(map_1) && !mapp(map_2) )
		return ([]);
	if ( !mapp(map_1) )
		return map_2;
	if ( !mapp(map_2) )
		return map_1;

	args = keys(map_2);
	for (i = 0; i < sizeof(args); i++)
	{
		if ( !map_1[args[i]] )
			map_1[args[i]] = map_2[args[i]];
	}

	return map_1;
}