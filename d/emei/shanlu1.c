// shanlu1.c ɽ·1
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����ɽС·�ϣ������ػأ�������Ȼ��ï�ܵ����֣�����һƬ
�ž�����紵��ֻ������Ҷҡ�ڼ䷢�������졣
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "west": __DIR__"shanlu2",
                "northeast": "/d/wudang/wdroad9",
      	]));
	setup();
}

