inherit NPC;
#include <ansi.h>

string *first_name = ({ "����", "��ë", "��Ƥ", "��ë", "����"});
string *name_words = ({ "��", "����", "����", "��"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"shou"}));
        set("race", "Ұ��");
        set("long", "һֻ��ģ������Ұ�ޣ�����ݺݵĶ����㡣\n");
        set("age", 100); 
        set("attitude", "aggressive");

        set("max_jing", 10000); 
        set("neili", 10000); 
        set("max_neili", 100);        set("max_qi", 100000); 
        set("jiali", 700);
        set("str", 300);
        set("con", 300);

        set("limbs", ({ "ͷ��", "����", "β��","צ��" }) );
        set("verbs", ({ "bite" }) );

      set_skill("unarmed", 500);
      set_skill("dodge", 1000);
        set_temp("apply/attack", 800);
        set_temp("apply/defense", 800);
        set_temp("apply/armor", 800);

        set("combat_exp", 5000000+random(40)*200000);
 
        set_weight(500000);
        setup();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "������") {
              ob->apply_condition("fire_poison", 900
              +(int)ob->query_condition("fire_poison") );
              tell_object(ob, HIR "����ñ�ҧ�еĵط�һ���̣�\n" NOR );
        }
}

