// donglang1.c ��������
// by Xiang
// Modified by Marz 03/27/96
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "���칬");
    set("long", @LONG
������һ����̻Ի͵Ĵ������鳯�칬�������֡��ϱ��ǻ�
ͷ�ң������������ţ��������������֡�
LONG
    );
    set("exits", ([
        "south" : __DIR__"hutou",
        "north" : __DIR__"santian",
    ]));
    
    set("objects", ([
        CLASS_D("wudang") + "/xi" : 1]));
        
    setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    object ob;
    myfam = (mapping)me->query("family");
    ob=present("zhang songxi", environment(me));
    if (objectp(ob) && living(ob))
    if ( wizardp(ob))
    if ((!myfam || myfam["family_name"] != "�䵱��") && dir == "north" )
       return notify_fail("����Ϫ�ȵ����㲻���䵱���ӣ��������ڡ�\n");
        
        return ::valid_leave(me, dir);
}
