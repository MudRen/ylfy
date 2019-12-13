#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name(HIY"�����" NOR, ({ "yufeng zhen", "zhen" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", HIY"�����������ϸ��ë���Ľ��룬���ɻƽ��ĳɾ��֣������β����
��Һ��������ȻϸС������ƽ���أ�����ʱ(she)�Կɼ�Զ��\n"NOR);
                set("value", 20000);
                set("material", "steel"); 
                set("treasure",1); 
                set("base_unit", "ö");
                set("base_weight", 2);              
        }
        set_amount(1);
        init_throwing(50);
        setup();
}

int init()
{
   add_action("do_throw", "she");
}

int do_throw(string arg)
{
       object me, ob;
       int i, damage;
       string msg;

       me = this_player();
       if (!arg) return notify_fail("��Ҫ��˭���֣�\n");       
       ob = present(arg, environment(me)); 
       if (!ob) return notify_fail("�Ҳ���������\n");       i = ob->query_skill("dodge", 1) + ob->query_skill("parry", 1);
       i = random(i/2) - 10;
       damage = me->query_skill("throwing", 1)+me->query_str()*2;
       if( environment(me)->query("no_fight") )
                return notify_fail("�㲻�������ﶯ�֡�\n");
       if(me->is_busy())
                return notify_fail("����æ���ء�\n");
       if(me->query("neili") < 500)
                return notify_fail("������������������֡�\n");
       if(me->query("family/master_name") != "С��Ů")
             return notify_fail("�㲻��С��Ů�ĵ��ӣ���ô��ʹ������룡\n"); 
       msg = HIY"\n$N����һ�ӣ�һö��������׷ɳ�ֱ��$n�����ȥ��\n\n"NOR;       
       me->start_busy(2);
       me->add("neili", -100);
       me->add("jingli", -20);
       if(me->query_skill("throwing", 1) > i && random(ob->query("kar")) < 10 &&
          me->query("combat_exp") > (int)ob->query("combat_exp")/2 ) {
          msg += HIR"$n�ͼ����һ������æ�����ܣ�����һ���ҽУ�������Ǳ��������У�\n"NOR;
          ob->apply_condition("bee_poison", 70);
          ob->receive_wound("jing", damage/2);
          ob->receive_damage("qi", damage+random(damage));
          ob->receive_wound("qi", damage); 
//          p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
//          msg += "( $n"+eff_status_msg(p)+" )\n";
//          ob->set_temp("last_damage_from", "��"+me->name()+"ɱ");
          }
       else {
          msg +=HIY"$n��æ�����Ծ��ֻ����һ�����죬���������$p��ǰ������֮�С�\n"NOR;
          ob->add("jingli", -10);
          }              
       message_vision(msg, me, ob);
       if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
       destruct(this_object());
       return 1; 
}


int query_autoload() { return 1; }