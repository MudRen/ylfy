// Room: /d/kunlun/pqf.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������ɵı����������ܷ��⼸�������ܣ������������ɸ�����ƽʱ
�����õ��񽣡�
LONG
        );

        set("objects", ([ 
        "/clone/weapon/zhujian" : 4,
]));

        set("exits", ([
        "west" : __DIR__"bwc",
]));

        setup();
        replace_program(ROOM);
}
