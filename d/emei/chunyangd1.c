// Room: /d/emei/chunyangd1.c ������ ������㳡


inherit ROOM;


void create()
{
	set("short", "������㳡");
	set("long", @LONG
�����Ƕ��ҵĴ�������Ĺ㳡������ɽ��ˮ�ƣ��ɸ����ƣ�ʮ������
������������һ������Ǵ������ΰ�ߴ�������ï�����֣�������ͨ
�������һ����ɽС����
LONG
	);
      set("outdoors", "emei");
	set("exits", ([
                "east":__DIR__"lshenggang",
                "south":__DIR__"chunyangd",
                "northdown":__DIR__"jietuopo",
	]));

	set("objects",([
	  "/d/emei/npc/qingyi" : 2,
         ]));

	setup();
}

