inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "Ī����");
        set("long", @LONG 
��ǰ����������Ī�����������ĺ��浹Ӱ������Ͱ��ƣ�����ˮ�� 
�����Ŀ���������˵�˺���ɲ⣬���䳺�ǣ����Ϸ������³壬����
���Ǻ�����������ӿ�ǳ�,��֮������Ͽˮ�ƣ��й�֮���޲���,��ɲ�
Ҫ(tiao)��ȥѽ��
LONG    );

        set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/tongchi/shandao2",        
  ]));
        set("outdoors", "tongchi" );
        set("no_clean_up", 0);
        setup();
}
 
void init()
{
        add_action("do_tiao","tiao");
}

 int do_tiao(string arg)
{
        object ob;
        int new_gin;
        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("������ѽ����ô���ĺ���������\n");
         tell_object(ob, HIG"�㲻��˼��������һԾ���������������\n"NOR);        message("vision", NOR"ֻ��" + ob->query("name") + "����������Ī������ȥ��������\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 15 ) && ((int)ob->query_skill("dodge")<30) )
        {
                ob->die();
                return 1;
        }
        ob->add("gin", 0 - new_gin);
        ob->move(__DIR__"hudi");
        return 1;
}