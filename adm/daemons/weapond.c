// weapond.c

#include <ansi.h>
#include <combat.h>
void bash_weapon2(object me, object victim, object weapon, object ob);

mapping weapon_actions = ([
    "slash": ([
        "damage_type":  "����",
        "action":       "$N�Ӷ�$w��ն��$n��$l",
        "parry":        20,
        ]),
    "slice": ([
        "damage_type":  "����",
        "action":       "$N��$w��$n��$l��ȥ",
        "dodge":        20,
        ]),
    "chop": ([
        "damage_type":  "����",
        "action":       "$N��$w����$n��$l������ȥ",
        "parry":        -20,
        ]),
    "hack": ([
        "action":       "$N����$w����׼$n��$lһ���ҿ�",
        "damage_type":  "����",
        "damage":       30,
        "dodge":        30,
        ]),
    "thrust": ([
        "damage_type":  "����",
        "action":       "$N��$w��$n��$l��ȥ",
        "dodge":        15,
        "parry":        -15,
        ]),
    "pierce": ([
        "action":       "$N��$w��$n��$l�ݺݵ�һͱ",
        "damage_type":  "����",
        "dodge":        -30,
        "parry":        -30,
        ]),
    "whip": ([
        "action":       "$N��$wһ���$n��$l��ȥ",
        "damage_type":  "����",
        "dodge":        -20,
        "parry":        30,
        ]),
    "impale": ([
        "action":       "$N��$w��$n��$lֱ����ȥ",
        "damage_type":  "����",
        "dodge":        -10,
        "parry":        -10,
        ]),
    "bash": ([
        "action":       "$N����$w����$n��$l����һ��",
        "damage_type":  "����",
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        ]),
    "crush": ([
        "action":       "$N�߸߾���$w����$n��$l��ͷ����",
        "damage_type":  "����",
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        ]),
    "slam": ([
        "action":       "$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",
        "damage_type":  "����",
        "post_action":  (: call_other, __FILE__, "bash_weapon" :),
        ]),
    "throw": ([
        "action":       "$N��$w��׼$n��$l���˹�ȥ",
        "damage_type":  "����",
        "post_action":  (: call_other, __FILE__, "throw_weapon" :),
        ]),
]);

varargs mapping query_action()
{
    string verb, *verbs;

	verbs = previous_object()->query("verbs");
    
	if ( !pointerp(verbs) )
		return weapon_actions["hit"];
	else
	{
		verb = verbs[random(sizeof(verbs))];

		if( !undefinedp(weapon_actions[verb]) ) 
			return weapon_actions[verb];
		else 
			return weapon_actions["hit"];
	}   
}

// ���ڶ�̬װ�� By Wenwu On 2006.7.13
varargs mapping query_action_xyzx(object weapon)
{
    string verb, *verbs;

	verbs = weapon->query("verbs");
    
	if ( !pointerp(verbs) )
		return weapon_actions["hit"];
	else
	{
		verb = verbs[random(sizeof(verbs))];

		if( !undefinedp(weapon_actions[verb]) ) 
			return weapon_actions[verb];
		else 
			return weapon_actions["hit"];
	}   
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
    if( objectp(weapon) ) {
        if( (int)weapon->query_amount()==1 ) {
            weapon->unequip();
            tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
        }
        weapon->add_amount(-1);
    }
}
void bash_weapon(object me, object victim, object weapon, int damage)
{
    object ob;
    int wap, wdp;
    if( objectp(weapon)
    &&  damage==RESULT_PARRY
    &&  ob = victim->query_temp("weapon") ) {
        if (ob->query("skill_type")=="throwing") return;
        wap = (int)weapon->weight() / 500
            + (int)weapon->query("rigidity")
            + (int)me->query_str();
        wdp = (int)ob->weight() / 500
            + (int)ob->query("rigidity")
            + (int)victim->query_str();
        wap = random(wap);
        if( wap > 3 * wdp ) {
            if (ob->query("tenacity") < weapon->query("weapon_prop/damage")){
            message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name() + HIW
                + "�Ѿ���Ϊ���أ�\n" NOR, victim );
            ob->unequip();
            ob->set("name", "�ϵ���" + ob->query("name"));
			ob->set("item_old_value", ob->query("value"));
            ob->set("value", 0);
			// ���������Ա��޸������Ƕ�̬ϵͳ��Ҫ�� By Wenwu 
			ob->set("backold_weapon_prop", ob->query("weapon_prop"));
            ob->set("weapon_prop", 0);
            ob->move(environment(victim));
            }else{
                message_vision(HIW "$Nֻ��������" + ob->name() + HIW + "�ѳֲ��������ַɳ���\n" NOR,victim);
                ob->unequip();
            }
            if (!ob->query("no_get") && !ob->query("no_drop")) ob->move(environment(victim));
            victim->reset_action();
            
        }else if( wap > 2 * wdp ) {
            message_vision(HIW "$Nֻ��������" + ob->name() + HIW + "�ѳֲ��������ַɳ���\n" NOR,
                victim);
            ob->unequip();
            if (!ob->query("no_get") && !ob->query("no_drop")) ob->move(environment(victim));
            victim->reset_action();
        } else if( wap > wdp ) {
            message_vision(BOLD+"$Nֻ��������" + ob->name() + BOLD +"һ����Щ���֣�\n" + NOR,
                victim);
        } else {
             bash_weapon2(victim,me,ob,weapon);
        }
    }
}
void bash_weapon2(object me, object victim, object weapon, object ob)
{
    int wap, wdp;
        if (ob->query("skill_type")=="throwing") return;
        wap = (int)weapon->weight() / 500
            + (int)weapon->query("rigidity")
            + (int)me->query_str();
        wdp = (int)ob->weight() / 500
            + (int)ob->query("rigidity")
            + (int)victim->query_str();
        wap = random(wap);
        if( wap > 3 * wdp ) {
            if (ob->query("tenacity") < weapon->query("weapon_prop/damage")){
            message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name() + HIW
                + "�Ѿ���Ϊ���أ�\n" NOR, victim );
            ob->unequip();
            ob->set("name", "�ϵ���" + ob->query("name"));
			ob->set("item_old_value", ob->query("value"));
            ob->set("value", 0);
			// ���������Ա��޸������Ƕ�̬ϵͳ��Ҫ�� By Wenwu 
			ob->set("backold_weapon_prop", ob->query("weapon_prop"));
            ob->set("weapon_prop", 0);
            ob->move(environment(victim));
            }else{
                message_vision(HIW "$Nֻ��������" + ob->name() + HIW + "�ѳֲ��������ַɳ���\n" NOR,victim);
                ob->unequip();
            }
            if (!ob->query("no_get") && !ob->query("no_drop")) ob->move(environment(victim));
            victim->reset_action();
            
        }else if( wap > 2 * wdp ) {
            message_vision(HIW "$Nֻ��������" + ob->name() + HIW + "�ѳֲ��������ַɳ���\n" NOR,
                victim);
            ob->unequip();
            if (!ob->query("no_get") && !ob->query("no_drop")) ob->move(environment(victim));
            victim->reset_action();
        } else if( wap > wdp ) {
            message_vision(BOLD+"$Nֻ��������" + ob->name() + BOLD +"һ����Щ���֣�\n" + NOR,
                victim);
        } else {
            if (wap>400)
            message_vision(HIY+"$N��" + weapon->name() + HIY+"��$n��" + ob->name()
                + HIY+"�����ð�����Ļ��ǡ�\n" + NOR, me, victim);
        }
}
