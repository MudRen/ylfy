 // duanchang.c
//modify by ronger

inherit ROOM;
#include <ansi.h>


void init()
{
        add_action("do_pa", "pa");
        add_action("do_bang", "bang");
        add_action("do_cuo", "cuo");
        add_action("do_tiao", "tiao");
        add_action("do_yes", "yes");
        add_action("do_no", "no");
        
}

void create()
{
        set("short",HIY"�ϳ���"NOR);
        set("long", @LONG
���ߵ�ɽ�嶥����һ��ɽ�£�ɽ���ϲ�֪��˭�̵��м��д��֣�dazi����
�Դ����ϣ���ʮ�ɹ�����Ĵ�ݲ��������������ƣ�������ң������Ҳ��
���ڷ嶥ͣ�㡣ɽ���Ա߾���һ����Ԩ��shenyuan�������±��ϳ���һ������
����song��бб��̽���±ߡ�
LONG);
        set("item_desc", ([
        "dazi": HIY"                             
            ������������������������������������
            ����������                  ��������
            ��������    ʮ �� �� ��   ��������
            ��������                    ��������
            ��������    �� �� �� �ᣬ   ��������
            ��������                    ��������
            ��������    �� �� �� �   ��������
            ��������                    ��������
            ��������    �� ʧ �� Լ���� �������� 
            ����������                  ��������
            ������������������������������������\n"NOR,
        "shenyuan":HIB"���Ԩ��������ȥ������Ԩ���������ƣ������ĵ�����ס�\n"NOR,
        "song": HIG"һ������������֦����б̽��֦������������\n"NOR,
        ]));

        set("exits", ([ 
                "westdown"  : __DIR__"shanlu10",
        ]));

        set("outdoors", "��Ĺ");

        setup();
}

int do_pa(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "down" )
                return notify_fail("��Ҫ��������\n");
        if (!me->query_temp("mark/bang"))
                return notify_fail("����������ɱô��ֱ������ȥ�ɣ�\n");
        message_vision(HIG"$N���������������ȥ��\n"NOR, me);
        me->move(__DIR__"yabi1");
        me->add_temp("tengacc",-1);
        tell_room(environment(me), me->name() + "����������������\n", ({ me }));
        me->delete_temp("mark/bang");
        return 1;
}

int do_bang(string arg)
{      
        object me;
        me = this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if( (int)me->query_temp("tengacc", 1)<=0 )
            return notify_fail("��Ҫ��ʲô��\n");
        if ( !arg || arg != "song" )
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->query_temp("mark/bang"))
                return notify_fail("�����Ѿ�����ˡ�\n");
        message_vision(HIY"$N����ϸϸ�ذ�����һ�˰����������ϡ�\n"NOR, me);
        me->set_temp("mark/bang",1);
        return 1;
}

int do_cuo(string arg)
{
        object me;
        me = this_player();
        if ( !arg || arg != "shupi" )
        return notify_fail("��Ҫ��ʲô��\n");         
        if( (int)me->query_temp("tengacc", 1)<=0 )
        {
                if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");                
                message_vision(GRN"$N����һ����Ƥ���������һ�����١�\n"NOR, me);
                me->set_temp("tengacc", 1);
                return 1;
        }
        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n"); 
//        if ((int)me->query_temp("tengacc",1) > 8)
//        return notify_fail("��Ƥ����������ˣ��㻹��ʲô����\n);
        message_vision(GRN"$N����һ����Ƥ�����������ٽӳ���\n"NOR, me);
        me->add_temp("tengacc",1);
        return 1;
}

#include "/d/gumu/tiao.c"	
