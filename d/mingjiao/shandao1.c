// Room: shandao1.c


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");

        set("long", @LONG
��ɫ�谵��ɽ�����ԵĴ������³�����֦Ҷ���ڻ谵�Ĺ����и���
�Ե��������£����ߵ������ֻ�����������ˣ�һ���亹��Ȼ��������
�ɵô������������ֲݴ����кü�������(teng)��ԭ������������̵�
���ߵ���Զ��--���¡�

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandao0",
]));

        set("no_clean_up", 0);
        set("item_desc", ([
                "teng": "����һ����ɽ�١�\n"
                ]) );

        setup();
}
void init()
{
        add_action("do_hua", "hua");
}
int do_hua(string arg)
{
        object me=this_player();

        if( !arg || arg=="" ) {write("��Ҫ��ʲô��\n");return 1;}
if (me->is_busy())
return notify_fail("����һ��������û����ɣ�\n");

        if( arg=="teng" ) {
                write("��˳��ɽ�٣��ɿ�����»�ȥ....\n");
if((int)me->query_skill("dodge",1)>=40)
                {write("��ѽ��ѽ����ѽ��ѽ�������ڻ����˹ȵס�\n");
                me->move(__DIR__"gudi");         

                 return 1;}
                write(RED"ͻȻ�䣬��һ�����⣬�͵�����ȥ��\n"NOR);

                me->add("jing",-40);
                me->add("qi",-40);
                me->improve_skill("dodge", random(100));
                me->unconcious();

                return 1;

                 }
}

