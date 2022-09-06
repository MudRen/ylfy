// Room: /d/heimuya/zhaoze/shiliang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "石梁");
	set("long", @LONG
顺着山路向前走去，行不多时，山路就到了尽头，前面是条宽约尺许    
的石梁，横架在两座山峰之间，云雾笼罩，望不见尽处。若是在平地之上
尺许小径又算得了甚么，可是这石梁下临深谷，别说行走，只望一眼也不
免胆战心惊。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fongdian",
  "north" : __DIR__"shiliang1",
]));
	set("outdoors", "shiliang");

	setup();
	replace_program(ROOM);
}
