// Room: /d/kunlun/sbxd.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����������ɽɽ�ŵ�һ��С�꣬���ڷ�Բ��ʮ��ʹ�һ��С�꣬��������
ɽ�����ѩ���������䣬������������������������������⻹����¡��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"klsj1",
 "west" : "/d/gaochang/room63",
]));
        set("objects", ([ 
        __DIR__"npc/xiaoer2" : 1,
]));

        setup();
        replace_program(ROOM);
}
