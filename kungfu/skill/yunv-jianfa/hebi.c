// by Yu Jue 98/7

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object *enemy;
        int i,j;
        float h, k, o, p;
        object weapon = me->query_temp("weapon");

       if ( me->query("gender")!="Ů��") return notify_fail("��ʹ�õļ��ܲ��ԡ�\n");
        if( !target || target == me) return notify_fail("��Ҫ��˭�ϱڣ�\n");

        if (me->query_temp("hebi")) return notify_fail("���Ѿ��ںϱ��ˡ�\n");
        if (target->query_temp("hebi")) return notify_fail("���Ѿ��ںϱ��ˡ�\n");
        if (me->query("jingli") < 200) return notify_fail("��ľ��������ˡ�\n");
        if (target->query("jingli") < 200) return notify_fail("�Է��ľ��������ˡ�\n");
        if(!me->is_fighting()) return notify_fail("�ϱ�ֻ����ս����ʹ�á�\n");
        if (me->is_fighting(target)) return notify_fail("�����ںͶԷ���ܣ��ϱڸ�ʲô��\n");

        if( (int)me->query_skill("yunv-jianfa", 1) < 60 )
                return notify_fail("�����Ů����������죬����ʹ�úϱڡ�\n");
        if( (int)me->query_skill("yunv-xinjing", 1) < 80 )
                return notify_fail("�����Ů���Ĺ�δ�������λ��кϱڵ�������\n");
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunv-jianfa")
                return notify_fail("�������޷��ϱڡ�\n");
        
        enemy = me->query_enemy();
        i = sizeof(enemy);
        while (i--) if (target->is_fighting(enemy[i])) break;
        if (i<0) return notify_fail(target->name()+"��û�к���Ķ����ڽ�ս��\n");

        if( (int)target->query_skill("quanzhen-jianfa", 1) < 60 )
                return notify_fail("�Է���ȫ�潣��������죬����ʹ�úϱڡ�\n");
         if( (int)target->query_skill("yunv-xinjing", 1) < 80 )
                  return notify_fail("�Է�����Ů���Ĺ��������죬�޷����Ӻϱ�������\n");
        weapon = target->query_temp("weapon");
        if (target->is_busy() || !weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "quanzhen-jianfa")
                return notify_fail("�Է������޷��ϱڡ�\n");
       
        message_vision(HIY "\n$N��$n˫��һ��������������\n" NOR, me, target);
        me->set_temp("hebi", 1);
        target->set_temp("hebi", 1);
        me->receive_damage("jingli", 100);
        target->receive_damage("jingli", 100);
        me->start_busy(1);
        target->start_busy(1);
          i = (int)me->query_skill("yunv-jianfa", 1);
          j =(int)target->query_skill("quanzhen-jianfa", 1);
          h = (int)(me->query_skill("yunv-xinjing", 1) /80);
          k = (int)(target->query_skill("yunv-xinjing", 1) /80);
          o = me->query("combat_exp", 1);
        p = target->query("combat_exp", 1);
        me->add_temp("apply/attack", i/5);
        me->add_temp("apply/dodge", i/5);
        target->add_temp("apply/attack", j/5);
        target->add_temp("apply/dodge", j/5);
        if (me->query("marry/id") == target->querry("id"))
  {
           me->set_skill("yunv-jianfa", i*h);
           target->set_skill("quanzhen-jianfa", j*k);
         me->set("combat_exp", o*h);
         target->set_skill("combat_exp", p*k);
          }
        call_out("hebi", 1, me, target, environment(me), i, j, h, k, o, p,(i+j)/25);
        return 1;
}

void hebi()
{
        object me, target, env;
        int i, j, o, p,count;
        object weapon;

        if (!me && !target) return;
        if (!me && target) {
                tell_room(env, HIY "\n�ϱ��Զ��߽⡣\n" NOR);
                target->add_temp("apply/attack", -j/5);
                target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                   target->set_skill("quanzhen-jianfa", j);
                 target->set("combat_exp", p);
                return;
        }
        if (me && !target) {
                tell_room(env, HIY "\n�ϱ��Զ��߽⡣\n" NOR);
                 me->add_temp("apply/attack", -i/5);
               me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                  me->set_skill("yunv-jianfa", i);
                me->set("combat_exp", o);
                return;
        }

        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunv-jianfa") {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);
                me->add_temp("apply/attack", -i/5);
               me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunv-jianfa", i);
                me->set("combat_exp", o);
                target->add_temp("apply/attack", -j/5);
               target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                  target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);
                return;
        }

        weapon = target->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "quanzhen-jianfa") {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);
                me->add_temp("apply/attack", -i/5);
                me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunv-jianfa", i);
                me->set("combat_exp", o);
                target->add_temp("apply/attack", -j/5);
                target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);

                return;
        }

        if (environment(me) != env || environment(target) != env) {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);
                me->add_temp("apply/attack", -i/5);
               me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunv-jianfa", i);
                me->set("combat_exp", o);
                 target->add_temp("apply/attack", -j/5);
               target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);

                return;
        }
        if (!me->is_fighting() || !target->is_fighting() || count < 1) {
                message_vision(HIY "\n$N��$n����һЦ���������С�\n" NOR, me, target);
                me->add_temp("apply/attack", -i/5);
                me->add_temp("apply/dodge", -i/5);
                me->delete_temp("hebi");
                me->set_skill("yunv-jianfa", i);
                me->set("combat_exp", o);
                 target->add_temp("apply/attack", -j/5);
               target->add_temp("apply/dodge", -j/5);
                target->delete_temp("hebi");
                target->set_skill("quanzhen-jianfa", j);
                  target->set("combat_exp", p);
                return;
        }
        call_out("hebi", 1, me, target, env, i, j, o, p, count - 1);
}

