inherit ROOM;
void create()
{
          set("short", "兵器房");
        set("long", @LONG
小小的兵器房，但却保存着各式各样的兵器，其中不乏绝世兵器，
凡通吃帮弟子都可以来选择自己的兵器。
LONG
        );
        set("exits", ([
                   "west" : __DIR__"tianjin",
        ]));
        set("objects", ([
        ]));
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}
