// ansuan.c ����
//by King 97.05
#include <ansi.h>
inherit F_CLEAN_UP;
mapping default_where = ([
        "n":    "north",
        "s":    "south",
        "e":    "east",
        "w":    "west",
        "nu":   "northup",
        "su":   "southup",
        "eu":   "eastup",
        "wu":   "westup",
        "nd":   "northdown",
        "sd":   "southdown",
        "ed":   "eastdown",
        "wd":   "westdown",
        "ne":   "northeast",
        "nw":   "northwest",
        "se":   "southeast",
        "sw":   "southwest",
        "u":    "up",
        "d":    "down",
]);
mapping default_dirs = ([
        "north":                "����",
        "south":                "�ϱ�",
        "east":                 "����",
        "west":                 "����",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":            "����",
        "southdown":            "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":            "����",
        "northwest":            "����",
        "southeast":            "����",
        "southwest":            "����",
        "up":                   "����",
        "down":                 "����",
        "enter":                "����",
        "out":                  "����",
]);
mapping default_undirs = ([
        "south":                "����",
        "north":                "�ϱ�",
        "west":                 "����",
        "east":                 "����",
        "southup":              "����",
        "northup":              "�ϱ�",
        "westup":               "����",
        "eastup":               "����",
        "southdown":            "����",
        "northdown":            "�ϱ�",
        "westdown":             "����",
        "eastdown":             "����",
        "southwest":            "����",
        "southeast":            "����",
        "northwest":            "����",
        "northeast":            "����",
        "down":                 "����",
        "up":                   "����",
        "out":                  "����",
        "enter":                "����",
]);
int main(object me, string arg)
{
        string who, where, dir, undir, where_temp;
        object env, old_env;
        mapping exits,apply;
        object target;
        int count;
        string gen;
        if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 ) 
                return notify_fail("ָ���ʽ��ansuan <����> at <����>\n");
        env = environment(me);
        old_env = env;
        if( !undefinedp(default_where[where_temp]) )
                where = default_where[where_temp];
        else
                where = where_temp;
        if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) )
                return notify_fail("û���������\n");
        if( !objectp(env = find_object(exits[where])) )
        {       call_other(exits[where], "???");
                env = find_object(exits[where]);
        }
        if( env->query("no_fight") )
                return notify_fail("�����ֹս����\n");
        if( !objectp(target = present(who, env)) )
                return notify_fail("�������û�д��ˡ�\n");
        if( !target->is_character() )
                return notify_fail("�����һ�㣬�ǲ��������\n");
        if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ����ܰ��㡣\n");
        if( me->is_fighting() )
                return notify_fail("����æ��ս���أ�������˼������ˣ�\n");
        if( !living(target) )
                if( userp(target) && target->query_temp("sleeped"))
                        return notify_fail("���˼�˯����ʱ�����֣��ٺ٣���Ҳ̫ȱ���ˣ�\n");
                else
                        return notify_fail(target->name() + "���Ѿ������ˣ��㻹�õ��Ű�����\n"); 
if(target->query_temp("apply/shade_vision"))    return notify_fail("�㿴����"+target->query("name")+"��\n");        	
        if ( (int)target->query("age") <= 17 
			&& playerp(target) 
			&& !target->query_condition("killer") )
                return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
        if( (int)me->query("jing", 1) < 100 )
                return notify_fail("���޷����о��������㲻�˱��ˡ�\n");
        target->delete_temp("fighting");
        if( !undefinedp(default_dirs[where]) )
                dir = default_dirs[where];
        else
                dir = where;
        if( !undefinedp(default_undirs[where]) )
                undir = default_undirs[where];
        else
                undir = where;
        if(me->query("gender") == "Ů��")
                gen = "ٻӰ";
        else
                gen = "��Ӱ";
        write( CYN"����Ϣ���������������" + dir + "��" + target->name() + "��ȥ��\n"NOR);
        message("vision", CYN"\nһ��" + gen + "��Ȼ��" + dir + "��ȥ��ת�ۼ��ֻص�ԭ����\n\n"NOR, environment(me), me);
        tell_object(target, CYN"\nһ��" + gen + "��Ȼ��" + undir + "����������\n\n"NOR);
        message("vision", CYN"\nһ��" + gen + "��Ȼ��" + undir + "��" + target->name() + "������\n\n"NOR, environment(target), target);
        count = me->query_str();
        apply=me->query_temp("apply");
        me->set_temp("apply/name", ({gen}));
        me->set_temp("apply/id", ({"none"}));
        me->set_temp("apply/short", ({gen}));
        me->set_temp("apply/long", ({gen}));
        me->move(environment(target));
        me->add_temp("str", count);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") );
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
        {
                message_vision(CYN"$Nһʱû�з�������$n���˸����ֲ�����\n"NOR, target, me);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon") );
        }
        else
        {
                message_vision(CYN"$N����ḻ������ϸ����������$n������\n"NOR, target, me);
                COMBAT_D->do_attack(target, me, target->query_temp("weapon") );
        }
        me->add_temp("str", - count);
        if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/5 )
        {
                me->delete_temp("apply/name");
                me->delete_temp("apply/id");
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                me->set_temp("apply",apply);
                tell_object(target, CYN"��һ����ԭ����" + me->name() + "�ڰ����ң�\n"NOR);
                write( CYN "���ã���" + target->name() + "�����ˣ�\n"NOR);
                message_vision(CYN"$N�ȵ���$n����Ұ����ң��Ҹ���û�꣡\n"NOR, target, me);
// ��������
                if ( me->query("age")<18 && userp(target))
                        me->att_kill_ob(target);
                if( !target->is_killing(me) ) target->kill_ob(me);
                me->start_busy(3);
        }
        else
        {
                message("vision", CYN"\n" + gen + "ת˲������\n\n"NOR, environment(target), me);
                tell_object(me, CYN"\n�������˻�ԭ����\n\n"NOR);
                me->move(old_env);
                me->delete_temp("apply/name");
                me->delete_temp("apply/id");
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                me->set_temp("apply",apply);
                tell_object(target, CYN"��һ���񣬿���ʲô��û������\n"NOR);
                message("vision", CYN"" + target->name() + "һ���֣̿�����֪��˭�ڰ�������\n"NOR, environment(target), target);
                write( CYN "������" + target->name() + "��Ȼû��������\n"NOR);
                write( CYN"����˴��֣�һ���޹������ӡ�\n"NOR);
        }
        me->start_busy(3);
        me->add("jing", -50);
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : ansuan <����> at <����>
���ָ�����㰵��λ��<����>��<����>��
�������ɹ�������˷��ֲ����㡣����...:)
HELP
    );
    return 1;
}
