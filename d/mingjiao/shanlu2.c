// Room: shanlu2.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·Խ��Խ����һ��С�ľͻ�ˤ����ɽ·�����ǻ�����ɽ
��һ����������һ����ͷ�������̲�ס���򼸸����硣һ֦��
��������ɽ·�ϣ���ֻ��ѻվ��֦ͷ�������ɡ��ҽС�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanmen",
  "south" : __DIR__"shanjiao",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
}

