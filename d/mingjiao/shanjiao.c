// Room: shanjiao.c

inherit ROOM;

void create()
{
        set("short", "ɽ����");
        set("long", @LONG
ɽ��ŭ�ţ�������ӿ��һ����ɽ��Ȼչ���������ǰ����
һ�����������������Զ������������ɣ�ԶԶ����ȥ����
����һ��ѩ���ĵ���бб�Ĳ��ڰ����С�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luzhou",
  "north" : __DIR__"shanlu2",
  "northwest" : __DIR__"diecong2",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

