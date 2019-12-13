// huacong.c by csy 98/12/29
#include <ansi.h>
inherit ROOM;

void delete_hexiu(object me, object arg);

void create()
{
          set("short",HIR"�컨��"NOR);
          set("long", @LONG
��Ժ컨�ſ����������ɣ����ܲ�㣬�����˱ǣ�������������һ������
�磬�����֦��ɷ�Ǻÿ������������񴹸ǣ�������Ȼ��ɵ�һ���������ݡ�
���ܶ���һƬ���ģ�ֻ��Ȫ����������˼���ȷ�Ǹ��Ϻõ��������ڡ�
LONG        );

          set("exits", ([
               "west" : __DIR__"guolin4",
               "south" : __DIR__"guolin5",
          ]));

          set("outdoors","��Ĺ");

          set("no_fight", 1);

          setup();
}

void init()
{
        add_action("do_hexiu", "hexiu");
}

int do_hexiu(object arg)
{
        object me = this_player();
        object ob;
        mapping fam;
        int ynlvl;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
        if (!arg)
            return notify_fail("��Ҫ��˭�����ڹ���\n");
        if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
            return notify_fail("�㲻�ǹ�Ĺ�ɴ��ˣ���ô������Ĺ���ڹ���\n");
        if (!(ob = present(arg, this_object())))
            return notify_fail("�������ڲ������\n");
        if (me == ob)
            return notify_fail("������˫�ֻ�����\n");
        if (!living(ob))
            return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");	
        if (!userp(ob))
            return notify_fail("��ֻ������Һ���������\n");
         ynlvl = me->query_skill("yunv-xinjing",1);
         if ( ynlvl > 130 )
          return notify_fail("���Ѿ����ܴӺ����еõ������ˣ�\n"); 
        if (ob->query_skill("yunv-xinjing", 1) < (ynlvl - 25) )
            return notify_fail("���˹����������̫Զ���޷�����������\n");
        if (me->query("jing") < 30 || me->query("qi") < 30)
            return notify_fail("��̫���ˣ���������Ϣһ����ɣ�\n");
        if (me->query_temp("gumu_hexiu") >= 1)
            return notify_fail("��������������˺����أ�\n");
         me->set_temp("gumu_hexiu", 1);
         tell_object(ob,me->name()+"����������ǰ�������������Ů�ľ���\n");
         if (ob->query_temp("gumu_hexiu") < 1)
         return notify_fail("�Է���û��Ҫ���������������˼��\n");
         message_vision(HIY"$N���͸�����ԣ���$n������֣����˸�������һ�ߣ��⿪��������ϰ������\n"NOR,me, ob);
         me->start_busy(5);
         ob->start_busy(5);
         call_out("delete_hexiu",5, me, ob);
         return 1;
}

void delete_hexiu(object me, object ob)
{
        mapping my;
        if (!me || !ob) return;
        my = me->query_entire_dbase();

        me->delete_temp("gumu_hexiu");
        ob->delete_temp("gumu_hexiu");         
        if (my["potential"] < 1) {
         tell_object(me,"���Ǳ�����Ĺ��ˣ����ʲôҲû��ѧ����\n");
         return;
         }
        my["potential"]--;
        message_vision(HIR"$N�ܵ���Ӧ����ʱ�˹�Ϊ����ȫ���������ڣ��ջ��ķᡣ\n"NOR,me);
        me->receive_damage("jing", 20+random(10));
        me->receive_damage("qi",  20+random(5) );
        me->improve_skill("yunv-xinjing", me->query_int()*( 2 + random(2)));        
        return;
}


