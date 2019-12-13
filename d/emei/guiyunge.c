// Room: /d/emei/guiyunge.c 峨嵋派 归云阁


inherit ROOM;


void create()
{
	 set("short","归云阁");
      set("long",@LONG
归云阁，原是唐代福昌达道禅师的道场。宋代绍兴年间，僧人士性又率众
重建。归云阁左有玉女峰，西上可抵纯阳殿，东下是观音堂。
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

