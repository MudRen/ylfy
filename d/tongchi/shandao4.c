inherit ROOM;
void create()
{
    set("short", "石阶");
    set("long", @LONG 
石级继续向上延伸，瀑布在脚下越来越小，水声也渐行远去
往上远眺，似乎可以看到石檐一角。
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
 ]));
    set("no_clean_up", 0);
    set("outdoors", "tongchi");
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandao3",
  "north" : __DIR__"damen",
]));
    setup();
    replace_program(ROOM);
}
