// Room: /d/heimuya/basket.c
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����������������º�ľ�µĹ��ߡ�
LONG
	);
	set("outdoors", "heimuya");
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
