// Room: /chengdu/zhubaopu.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
        set("short", "�ܼ��鱦��");
	set("long", @LONG
����һ��רӪ�������鱦������ε꣬�ϰ�Ͱ����ף�������
������������Ҽ������͸���������ˣ��ǾͲ�Ҫ����ԥ�ˣ��Ͻ�
��ǮׯȡǮ�ɡ�
LONG
	);

	set("exits", ([
                "west" : __DIR__"beijie",
	]));

	setup();
	replace_program(ROOM);
}

