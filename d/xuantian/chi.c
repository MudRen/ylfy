inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
����ǰͻȻ����һ���޴��ˮ�أ���ˮ������ģ�ʮ�ֲֿ���
�㲻�������ٹ���������˹���ˮ�Ծ���һ��...
LONG    );

        set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/xuantian/room1",
                "east" : "/d/xuantian/xiaolu",
                "north" : "/d/xuantian/room7",
                "south" : "/d/xuantian/room2",
                "out" : "/d/xuantian/pomiao",
        ]));
        set("outdoors", "xuantian" );
        set("no_clean_up", 0);
        setup();
}
 
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob;
        int new_gin;
        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "ˮ��" )
                return notify_fail("�������裿Ӧ�õ������Ŷԡ�\n");
        tell_object(ob, HIR"���������˿���������һԾ�������˺�ˮ���С�\n"NOR);
        message("vision", NOR"ֻ��" + ob->query("name") + "�����ң����������˺�ˮ��֮�С�������\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<300) )
        {
                ob->die();
                return 1;
        }
        ob->add("gin", 0 - new_gin);
        ob->move("d/xuantian/dong");
        ob->unconcious();
        return 1;
}

