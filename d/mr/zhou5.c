inherit ROOM;
void create()
{
        set("short", "渡船");
        set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名老艄公手持长竹篙，正在船
尾吃力地撑着船。
LONG
        );
        set("outdoors", "mr");
        setup();
        replace_program(ROOM);
}
