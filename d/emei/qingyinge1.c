// Room: /d/emei/qingyinge.c ������ ������


inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƕ���������Ϣ�ĵط����������ģ������۾���ż��Ҳ�м���
��У���ʱ��ɽ���лص�������������Ϣ�ң�������Ů��Ϣ�ҡ��ڳ���
����һ��Сľ��(men)�������Ĺر��š�
LONG
	);

	set("exits", ([
                 "west": __DIR__"xiuxishi",
                 "east": __DIR__"xiuxishi1",
	]));
	setup();
}
void init()
{
	add_action("do_open", "open");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"qingyinge")) )
		room = load_object(__DIR__"qingyinge");
	if(objectp(room))
	{
		delete("exits/north");
			message("vision", "������ǰ��ľ�Ź���������\n", this_object());
		room->delete("exits/south");
		message("vision", "�����������İ�ľ�Ź����ˡ�\n", room);
	}
}

int do_open(string arg)
{
	object room;

	if (query("exits/north"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "men" && arg != "north"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"qingyinge")) )
		room = load_object(__DIR__"qingyinge");
	if(objectp(room))
	{
		set("exits/north", __DIR__"qingyinge");
		message_vision("$N���İ�ľ�Ŵ��˿�����\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision", "֨��һ�����������˰�ľ�Ŵ��ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}
int valid_leave(object me, string dir)
{
       if ( me->query("gender") == "����" && dir == "west")
       return notify_fail("������㣡����Ů��Ϣ�ҡ�\n");
       if ( me->query("gender") == "Ů��" && dir == "east")
       return notify_fail("������㣡��������Ϣ�ҡ�\n");
        return ::valid_leave(me, dir);
}
