inherit ROOM;
void create()
{
    set("short", "石阶");
    set("long", @LONG 
长长的石阶往上依然看不到尽头。身边的山壁受着长年风雨
的浸润，长出了薄薄的青苔。上面依稀有些刻凿的痕迹。有一行
字特别清晰：“通吃帮帮主杨小邪到此一游”
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
 ]));
    set("no_clean_up", 0);
    set("outdoors", "tongchi");
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandao",
    "east" : __DIR__"hu",
]));
    setup();
    replace_program(ROOM);
}
