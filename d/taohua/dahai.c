inherit ROOM;
 
void create()
{
        set("short", "��");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��˵��Ĵ�����
LONG);   
    set("exits", ([
       "out" : __DIR__"dahai",
    ]));
        setup();
}
int do_check()
{
	object *obj;
	int	i;
	obj=all_inventory(this_object());
	if (!sizeof(obj))	return 1;
	for (i=0;i<sizeof(obj);i++)
		if (userp(obj[i]))	return 0;
	return 1;
}
