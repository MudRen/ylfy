//      guangchang.c �㳡
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","�㳡");
        set("long",@LONG
������ѩɽ���ڵĹ㳡���㳡�ı��������ɽ������ѩɽ�´�
������һЩ�ֳ�ɮ����ɮ����Ѳ�ߡ�
LONG
        );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"xiaoyuan",
                "west" : __DIR__"chang",
                "north" : __DIR__"dadian",
                "south" : __DIR__"shanmen",
        ]));
        set("objects" , ([
                __DIR__"npc/seng-bing1"  : 4 ,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
    if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;
    return ::valid_leave(me, dir);
}
