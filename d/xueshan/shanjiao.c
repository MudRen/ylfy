//      shanjiao.c ɽ��
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","ɽ��");
        set("long",@LONG
    ������ɽ���µ�һƬƽ�أ�ɽ�ϲ�Զ������Զ��������ѩɽ�¡�
LONG
        );
        set("outdoors","xueshan");
        set("exits",([
                "northup" : __DIR__"shanlu1",
"westup" : "/d/xuedao/nroad7",	
                "south" : __DIR__"hubian4",
        ]));
        setup();
        replace_program(ROOM);
}
