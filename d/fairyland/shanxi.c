
inherit ROOM;
void create()
{
	set("short", "ɽϪ��");
	set("long", @LONG
������һ��СϪ������ɽ�����ѩ�������������£����ֱ�ѩ�ڻ���ˮ��
�����СϪ��Ϫˮ���¶�������֪������η�������������һ������֡�
LONG	);
	set("exits", ([
		"westup" : __DIR__"conglin1",
                "eastup" : __DIR__"hmzhuang",
	]));
	set("outdoors", "����ɽ");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
