// Room: /d/city/shuyuan2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "�쵤��������");
        set("long", @LONG
�쵤��һ����ż��ӵ�����������һ�Ŵ����⣬ΨһֵǮ
��ֻ��һ������ˡ�
LONG
        );
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("sleep_room", "1");
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shuyuan",
]));
        setup();
        replace_program(ROOM);
}
