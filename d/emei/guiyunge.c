// Room: /d/emei/guiyunge.c ������ ���Ƹ�


inherit ROOM;


void create()
{
	 set("short","���Ƹ�");
      set("long",@LONG
���Ƹ�ԭ���ƴ����������ʦ�ĵ������δ�������䣬ɮ��ʿ��������
�ؽ������Ƹ�������Ů�壬���Ͽɵִ���������ǹ����á�
LONG);

	set("exits", ([
		"east" : __DIR__"guanyintang",
		"west" : __DIR__"chunyangd",
	]));

	set("objects",([
			"d/emei/npc/girldizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}

