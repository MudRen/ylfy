// shanlu2.c ɽ·2
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������һ����ɽС·�ϣ������ػأ�������Ȼ��ï�ܵ����֣�����һƬ
�ž�����紵��ֻ������Ҷҡ�ڼ䷢�������졣
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "east": __DIR__"shanlu1",
                "west": __DIR__"shanlu3",
      	]));
	setup();
}

