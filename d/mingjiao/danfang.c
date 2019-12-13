//danfang.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǽ�ҩ�������Ĵ��ݣ������ܶ����˸�ʽ�����Ĳ�ҩ�������м�
����һ������ҩ��ͭ��(tongding)����Ϊ������Ե�ʣ��������ļ��紺��
һλ���̵���������ǽ�Ŵ��˯��
LONG
        );
        set("exits", ([
 "west" : __DIR__"yaofang1",
        ]));

        set("objects",([
                __DIR__"npc/mingjiaodizi" : 1,

        ]));
        

        set("item_desc", ([
                "tongding" :
"    ��������ͭ���ɵ�����ͭ������Լ���ٶ��������о���Ϸ��
��ͼ�������ڻ������������������Ľ�Ҫ��ͷ! Ϊ�˱��ֻ��ƣ����벻
ͣ���򶦿���(shan)�硣\n",
        ]));
        
        setup();
}

void init()
{
        add_action("do_shan", "shan");
}

int do_shan(string arg)
{
        object me;
        int i, costj, costq;

        me = this_player();


        if ( !living(me)) return notify_fail("�㷢����? \n");

        if ( !arg || arg != "tongding" )
            {    message_vision("$N���˰���,����������!\n",me);
                 return 1;
             }
        if ((int)me->query_skill("taoism", 1) < 30) 
               return notify_fail("���Ӻȵ���������̲��޹ϸ𣬷�������֮�ˣ����ذ׷�����!\n");
        costj = 1500 / (int)me->query("con");
        costj = random(costj);
        costq = 2000 / (int)me->query("str");
        costq = random(costq);

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
        message_vision("$N��������, һ������ͷྵ���¯��!\n",me);
        me->unconcious();return 1;}
        
	me->add("jing", -costj);
        me->add("qi", -costq);       

        message_vision("$N���������������Ż�\n", me);

        if ( (int)me->query_skill("strike", 1) < 31)
                {
                        write(HIY"���ֱ���������������֮���ƺ��Ի����Ʒ���Щ����\n"NOR);
                        me->improve_skill("strike", (int)(me->query("int") / 8));
                }
        i = (int)me->query("int") * (int)me->query("str") / 4;
        i = i + (int)me->query("kar") / 3 - 20;
        if ( random(i) > 95 )
                {
                        write(HIY"��ϲ! ����������һ����۾���!\n"NOR);
                        me->add("combat_exp", (int)(me->query("int") / 10));
                      }
        if ( random(i) > 100 )
                {
                        write(HIY"��ϲ! ����������һ��ת������!\n"NOR);
                        me->add("combat_exp", (int)(me->query("int") / 10));
                      }

        return 1;
}

