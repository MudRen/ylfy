//      xiaoyuan.c СԺ
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","СԺ");
        set("long",@LONG
    ���������ڵ�СԺ�������и�������
LONG
        );
        set("outdoors","xueshan");
        set("exits",([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"chufang",
        ]));
        setup();
        replace_program(ROOM);
}
