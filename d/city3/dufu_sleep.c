// Room: /d/city/shuyuan2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "�Ÿ�������");
        set("long", @LONG
�Ÿ�һ����ż��ӵ�����������һ�Ŵ����⣬ΨһֵǮ��
ֻ��һ������ˡ�
LONG
        );
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("sleep_room", "1");
        set("exits", ([ 
  "south" : __DIR__"caotang",
]));
        setup();
        replace_program(ROOM);
}

