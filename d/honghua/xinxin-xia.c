//Room /d/honghua/xinxin-xia.c

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short","����Ͽ");
    set("long",@LONG
����ǰ����ʯ��һ���ſ���ֱ���ȥ��ɽʯ�������������ƺ�
���б�����أ��ٱ���ʱ�������ͱ��м�¶��һ���������Ǳ��Ǹ�
��ͻؽ�֮��Ľ�ͨҪ������Ͽ
LONG
    );
    
    set("outdoor", "honghua");    
    set("exits", ([
        "south" : __DIR__"shanxia",
        "north" : __DIR__"caoyuan3",
    ]));

    set("coor/x",-130);
    set("coor/y",80);
    set("coor/z",0);
    set("coor/x",-130);
    set("coor/y",80);
    set("coor/z",0);
    set("coor/x",-130);
    set("coor/y",80);
    set("coor/z",0);
    set("coor/x",-130);
    set("coor/y",80);
    set("coor/z",0);
    setup();
}
