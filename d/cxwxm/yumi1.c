// yumi1.c
// marry 99 .8
inherit ROOM;

void create()
{
        set("short", "���׵�");
        set("long", @LONG
����һƬïʢ�����׵أ���������ײ�֪��ʲô����Ʒ�֣��������˶�ߣ���
�������ߣ���������·��
LONG
        );

       set("exits", ([
               "north" : __DIR__"tianye",
               "south" : __DIR__"yumi2",
               "east" : __DIR__"yumi3",
               "west" : __DIR__"pubu",
       ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
