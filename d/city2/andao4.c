
inherit ROOM;
void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
�ص���һƬ��ڣ������ķ���������˷���������ʲôҲ����
����ֻ���ڵص���Ϲ����ײ�������ƺ�����ԼԼ����˵������ֻһ
�����û���ˡ���ʹ����ҡ��ҡͷ���ܻ����⵽���ǲ��ǻþ�����
�����Ѿ���·�ˡ�
LONG
	);
	set("exits", ([
		"north" : __FILE__,
		"south" : __DIR__"andao5",
		"west" : __FILE__,
		"east" : __DIR__"andao6",
	]));
	setup();
	replace_program(ROOM);
}
