
inherit ROOM;

void create()
{
	set("short", "Ѧ�ξ�");
	set("long", @LONG
������һ��Ůʫ��Ѧ������֮�أ��������ֻ��ƣ������ĵ�
���Լ��ĽŲ��������õ��������ǰ�пڹž������泤������̦��
�������Ѿ��ܾ�û�������ˡ�
LONG
	);

	set("exits", ([
                "west" : __DIR__"wanliqiao",
	]));

        set("outdoors", "chengdu");
	setup();
	replace_program(ROOM);
}



