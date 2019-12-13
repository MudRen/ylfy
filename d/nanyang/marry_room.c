// marry_room.c
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "����ׯ");
        set("long", @LONG
��������վ�ں���ׯ�������ר�����˵޽��Լ�ͽ����Լ�ĵط���
�������еķ򸾶���������ϲ����Ե�ģ�������������Ҳ�����Ľ�������ġ�
�����������Ǹ����ĵط���
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
        "west" : __DIR__"ruzhou",
        "east" : __DIR__"hubudatang",
         ]) );
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("objects", ([
                __DIR__"/npc/mei_po" : 1,
        ]) );
 
        setup();
}
string look_sign(object me)
{
        return "�޽������Լ��\n";
}
int valid_leave(object me, string dir)
{
    if ( me->query_temp("pending/pro") )
           me->delete_temp("pending/pro");
       return ::valid_leave(me, dir);
}
void init()
{
    if (this_player()->query_temp("asked")){
        this_player()->delete_temp("asked");
        delete("exits/enter");
    }
}
