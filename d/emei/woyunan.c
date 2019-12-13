// Room: /d/emei/woyunan.c 峨嵋派 卧云庵

inherit ROOM;


void create()
{
	  set("short","卧云庵");
      set("long",@LONG
卧云庵旁边有个井络泉，据说以前曾因饮水人多而干涸，众尼为之诵经，
于是泉水复出。出了卧云庵便是睹光台，旁边是华藏庵。
LONG);

	set("exits", ([
		"northeast" : __DIR__"jinding",
		"southup" : __DIR__"duguangtai",
	]));

	set("objects",([
		"d/emei/npc/girldizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
