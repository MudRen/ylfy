
inherit ROOM;

void create()
{
	set("short", "�嶫��");
	set("long", @LONG
������С��Ķ�ͷ����Ϊ����չ�������һƬ��Ţ��·�ǳ������ߡ�˳
������·һֱ���߾͵�������ɽ�����ˡ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"northwest" : __DIR__"cun7",
        "east" : __DIR__"cun9",
	]));
  
	setup();
	replace_program(ROOM);
}

