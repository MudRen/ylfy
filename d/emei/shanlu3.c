// shanlu3.c ɽ·3
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�߳���ï�ܵ����֣���·��Ȼ���ʡ�һ�����ֱͨ��һ����ɽɽ�š�Զ
Զ��ȥ��Լ��������Զ����һ������
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "south": __DIR__"shanmen",
                "east": __DIR__"shanlu2",
                
      	]));
	setup();
}

