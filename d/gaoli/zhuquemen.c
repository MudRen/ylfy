// Room in 高丽
inherit ROOM;
void create()	
{
	set("short", "得胜门");
	set("long", @LONG
这里是高丽的得胜门。北面就到了城中，远望人山人海，往来行人
车流不绝。南面一条大路通向港口。城门下有一些执勤的兵士。兵将警
惕的盯着往来人士。
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"dadao6",
        	"north" : __DIR__"zhuque-2",
	]));
set("objects",([
  __DIR__"npc/guanbing":2,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	
}
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","zhuque");
  return ::valid_leave(ob,dir);
}
