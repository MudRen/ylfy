// ��ͼԴ�ļ�

#define SHORT_NAME "����ɭ��"
#define LONG_NAME "����ɭ��һ���ǽ����˼���������η��ĵط������ﵽ���������������Ϣ��\nҲ��֪�����ĳ��Ĵ�˭�˷��ֵ����Ҳ��Զ�ŵ�ʱ����Ѿ����˰ɡ�������ľ\n�����Ѽ����գ�����������ɱ������˵������ɭ����ͨ���������ıؾ�֮·��\n��������硱����ô��������������������ɭ��·�����������Թ�����ô���ߵ�\n��ȥ�أ�����֮���������Ÿ�����ħ���ޣ��������գ���Ȼ���������ɭ��̽��\n���˻������ﲻ�����Ͼ�����ĸ��������챦���ǽ�������������ģ����д���\n����ɭ����ħ���Ŀ�ʼ����ħ����...����������һ�����˵������ʣ�����ħ��\n�Խ�������˵��ν���绢����ÿ��ÿʱÿ�̶��и�ɫ�������ﲻ��������ɭ�֣�\n̽��...�˲�...����...��...��...��...��...����...���...����������ɭ��\n�ﷴ������.....\n"

inherit ROOM;

void create()
{
	set("outdoors", "automap");
	set("short", SHORT_NAME);
	set("long", LONG_NAME);
	set("exits", ([
"west" : __DIR__"413",
"south" : __DIR__"415",
"northwest" : __DIR__"739",
"east" : __DIR__"361",
"northeast" : __DIR__"539",
]));
	set("objects", ([]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping exits;
	string file_name;

	exits = this_object()->query("exits");

	if ( mapp(exits) && sizeof(exits) )
	{
		if ( !stringp(file_name = exits[dir]) )
			return notify_fail("��ͼ���Ӵ������� sos ֪ͨ����Ա�޸ġ�\n");
		if ( strlen(file_name) < 10 )
			return notify_fail("���ӵ�������ȷ������ sos ֪ͨ����Ա�޸ġ�\n");
		if ( !playerp(me) && base_name(this_object())[0..9] != file_name[0..9] )
			return 0;
	}

	return ::valid_leave(me, dir);
}