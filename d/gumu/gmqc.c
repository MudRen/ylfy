
#include <ansi.h>
inherit ROOM;

void delete_qiecuo(object me, object arg);

void create()
{
          set("short",HIR"�д���"NOR);
          set("long", @LONG
���ǹ�Ĺ�ɵ����д��似�ĵط����տ���һ��ʯ�ң�û���κΰ��衣����
�������ٻ�ѣ���Ҳ�ƻ�ͨ����ʯ�������м������˵���ӡ����ʯ���֣��Լ�
�Ǹ����ཻ��Ϊ��
LONG        );

          set("exits", ([
               "north" : __DIR__"gmqt",
          ]));
          set("no_fight", 1);
          setup();
}

void init()
{
        add_action("do_qiecuo", "qiecuo");
        add_action("do_qiecuo", "chaizhao");
}

int do_qiecuo(object arg)
{
        object me = this_player();
        object ob;
        mapping fam;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
//      if (ob->is_busy() || ob->is_fighting())
//                    return notify_fail("��û�����Է���æ����\n");
        if (!arg)
            return notify_fail("��Ҫ��˭�д����գ�\n");
        if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
            return notify_fail("�㲻�ǹ�Ĺ�ɴ��ˡ�\n");
        if (!(ob = present(arg, this_object())))
            return notify_fail("�������ڲ������\n");
        if (me == ob)
            return notify_fail("������˫�ֻ�����\n");
        if (!living(ob))
            return notify_fail("������Ȱ�" + arg->name() + "Ū�ѡ�\n");
        if (!userp(ob))
            return notify_fail("��ֻ�ܺ�����д����գ�\n");
        if (me->query("combat_exp") > 150000)
            return notify_fail("�㹦����ߣ��Ѿ����ܴ��д��еõ������ˣ�\n"); 
        if (ob->query("combat_exp") < me->query("combat_exp")/2 )
            return notify_fail("���˹����������̫Զ���޷�����������\n");
        if (me->query("jing") < 40 || me->query("qi") < 40)
            return notify_fail("��̫���ˣ���������Ϣһ����ɣ�\n");
        if (me->query_temp("gumu_qiecuo") >= 1)
            return notify_fail("���������ںͱ��˲��У�\n");
         me->set_temp("gumu_qiecuo", 1);
         if (ob->query_temp("gumu_qiecuo") < 1)
         return notify_fail("�Է��ƺ���û��Ҫ�����д����յ���˼��\n");
         message_vision("$N��$n������ʽ������������\n", me, ob);
         me->start_busy(10);
         ob->start_busy(10);
         call_out("delete_qiecuo",15, me, ob);
         return 1;
}

void delete_qiecuo(object me, object ob)
{
        mapping my;
        if (!me || !ob) return;
        my = me->query_entire_dbase();

        me->delete_temp("gumu_qiecuo");
        ob->delete_temp("gumu_qiecuo");
        message_vision("$N��$n�㹥���أ����α�ã�ת�۱��Ѳ���ʮ����.....\n",me, ob);
        if (my["potential"] < 1) {
         tell_object(me, "��ʲôҲû��ѧ����\n");
         return;
         }
        my["potential"]--;
        tell_object(me, "��ֻ���ô˷���ϰ���ջ��ķᣬ�������յĸ�������ˣ�\n");
        me->receive_damage("jing", 20+random(my["max_jing"]/10) );
        me->receive_damage("qi",  20+random(my["max_qi"]/10) );
        me->add("combat_exp", 1+random((my["max_pot"]-100)/3) );
        return;
}

