// ���ƾ�  by:pipip
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "���ƾ�");
    set("long", @LONG
��һ�����������ŵ�һ��������ֻ��һΪ��ò��
�ŵ��������������㵯�٣�����ʱ��ʱ�壬���紺��
�������ƺӲ��Σ���ֱ���������ˡ�
LONG
    );
    set("exits", ([
        "south" : __DIR__"door",
        "east" : "d/xuantian/room1",
    ]));
    set("objects", ([
        "d/xuantian/npc/wuming" : 1 ]));
    setup();
    replace_program(ROOM);
}

int do_check(object me)
{
    object where=this_object();
    object *obj;
    int i;
    obj=deep_inventory(where);
    if (!sizeof(obj))   return 0;
    for (i=0;i<sizeof(obj);i++){
        if (obj[i]==me) continue;
        if (userp(obj[i]))
            return 1;
    }
    return 0;
    
}

void init()
{
    object ob=this_player();
    if(userp(ob) && (int)do_check(ob)){
        message_vision("��������һ��ץס$N���˳�����˵������һ��ֻ��һ��ͽ�ܡ�\n",ob);
        ob->move("d/xuantian/dadao");
    }
}

