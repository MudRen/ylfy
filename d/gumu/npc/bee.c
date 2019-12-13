// bee.c
//bee.c test
// Modify By csy 98/12
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���", ({ "yu feng", "bee","feng" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "ֻ������ҳ����С���ȵס����֣�������С����ھ������֣�ÿ����ϸ����
�������ʻ�����������ü�ϸ����̳ɡ�\n");
        set("attitude", "peaceful");         

        set("str", 20);
        set("con", 30);

        set("limbs", ({  "����",  "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 5000);

        set_temp("apply/attack", 35);
        set_temp("apply/damage", 23);
        set_temp("apply/armor", 24);

        setup();
}

void init()
{
        mapping fam;
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
          (fam = ob->query("family")) && fam["family_name"] != "��Ĺ��"){
                message_vision(HIR"$N���Դ����Ĺ���ء�\n"NOR,ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
//              set_leader(ob);
        }
}

void die()
{
        message_vision("$N����һ�ƻ��䣬������ɢ��ʬ��ȫ�ޡ�\n", this_object());
        destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("bee_poison", victim->query_condition("bee_poison") + 20);
        return 0;
}     
int query_autoload() { return 1; }

