//      kufang.c �ⷿ
//      Designed by secret (����)
//      97/04/09
inherit ROOM;

void create()
{
        set("short","�ⷿ");
        set("long",@LONG
���������䳡�Աߵ�С�ⷿ��������Щ���õ�������
LONG
        );
        set("exits",([
                "east" : __DIR__"chang",
        ]));
    set("objects", ([
        "/clone/weapon/zhujian" : random(4),
        "/d/xueshan/obj/mugun" : random(4),
        "/d/xueshan/obj/falun" : random(4),
    ]));

        setup();
        replace_program(ROOM);
}

