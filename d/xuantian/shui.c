//by pipip
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "����ˮ");
        set("long", @LONG
����ǰ��һ����Ȼ�ĵ��º������ڰ���͸�����⣬
�������֪�������ˮ����ǳ��Ҳ��֪��ˮ���Ƿ��
�й�������ŵ�Ѫ�ȡ�
LONG    );

        set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/xuantian/room2",
                "east" : "/d/xuantian/room3",
                "north" : "/d/xuantian/room7",
                "south" : "/d/xuantian/room5",
        ]));
        set("outdoors", "xuantian" );
        set("no_clean_up", 0);
        setup();
}
 
void init()
{
        add_action("do_qian","qian");
}

int do_qian(string arg)
{
        object ob;
        int new_gin;
        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "����ˮ��" )
                return notify_fail("ǱʲôǱ����ķ�ˮ��ߴ���û��\n");
        tell_object(ob, HIR"���������˿���������һԾ��Ǳ�����ĵ���ˮ�С�\n"NOR);
        message("vision", NOR"ֻ��" + ob->query("name") + "��ͨһ��������ˮ�\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<1300) )
        {
                ob->die();
                return 1;
        }
        ob->add("gin", 0 - new_gin);
        ob->move("d/xuantian/xiaojin");
        ob->unconcious();
        return 1;
}

