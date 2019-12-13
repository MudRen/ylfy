// lonely-sword.c ���¾Ž�

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
        ""+(order[random(13)])+"ȴ��$n̤ǰһ������ʽбָ����ұۣ���Ҫʹ$P������ˡ�"NOR"\n",
        "$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ"+(order[random(13)])+"���������"NOR"������"NOR"\n",
        ""+(order[random(13)])+"$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ������"+(order[random(13)])+"������������"NOR"��ͼ��ʹ$P���С�"NOR"\n",
        ""+(order[random(13)])+"$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������"NOR"\n"
        "$n�������ܣ��ٽ������ʹ��"+(order[random(13)])+"�����両�ࡹ"NOR"����$P��$l���뵲������С�"NOR"\n",
        "$nͻȻʹ��������ɷ罣����"+(order[random(13)])+"�����ڤڤ��"NOR"�����Ƿ�λȴ����ƫ���������$Pһ�ʣ���\nͼͻ��$P�Ĺ��ƣ�"NOR"\n"
        "$nͦ��һ������"+(order[random(13)])+"�����Ƴ�ᶡ�"NOR"�ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣"NOR"\n",
        "ֻ��$n���˷���������Ʈ�磬�����һʽ"+(order[random(13)])+"������������"NOR"�������޶�����׽���ص�ס��$P��\n������"NOR"\n",
        "$n���˷�����ʹ����ɽ����"+(order[random(13)])+"��������롹"NOR"��ɭɭ�����������ܣ��ܿ���$P������"NOR"\n",
});

mapping *action = ({
([      "action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ������"+(order[random(13)])+"��������Ȫ��"NOR"ֱ��$n��$l��",
        "force" : 110,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N������$n�ӳ�"+(order[random(13)])+"��Ȫ��ܽ�ء�"NOR"��"+(order[random(13)])+"�������ϸǡ�"NOR"��"+(order[random(13)])+"��ʯ��������"NOR"��"+(order[random(13)])+"������������"NOR"��"+(order[random(13)])+"�����ף�ڡ�"NOR"��ɽ���񽣣�",
        "force" : 110,
        "dodge" : 60,
        "damage": 250,
        "lvl" : 7,
        "damage_type" : "����"
]),
([
        "action" : "$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ"+(order[random(13)])+"����Ůʮ�Ž���"NOR"�����������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼��",
        "force" : 110,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 14,
        "damage_type" : "����"
]),
([      "action" : ""+(order[random(13)])+"$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ��",
        "force" : 120,
        "dodge" : 65,
        "damage": 250,
        "lvl" : 21,
        "damage_type" : "����"
]),
([      "action" : ""+(order[random(13)])+"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ���ƻ���$n��$l��",
        "force" : 120,
        "dodge" : 80,
        "damage": 250,
        "lvl" : 28,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ���������"+(order[random(13)])+"��̩ɽʮ���̡�"NOR"Ϊһ������$n��",
        "force" : 130,
        "dodge" : 100,
        "damage": 255,
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ�䣬ʹ����ɽ��"+(order[random(13)])+"��һ������㡹"NOR"������$n��$l����֪������;��ͻȻת�򣬴��$n����֮�⣡",
        "force" : 140,
        "dodge" : 100,
        "damage": 260,
        "lvl" : 42,
        "damage_type" : "����"
]),
([      "action" : "$N����������һ������"+(order[random(13)])+"��������ɽ��"NOR"������$w����ն�䣬ֱ����$n��
$l��",
        "force" : 150,
        "dodge" : 100,
        "damage": 280,
        "lvl" : 49,
        "damage_type" : "����"
]),
([      "action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ��"+(order[random(13)])+"���ٱ�ǧ������ʮ��ʽ��"NOR"����ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��",
        "force" : 160,
        "dodge" : 100,
        "damage": 290,
        "lvl" : 56,
        "damage_type" : "����"
]),
([      "action" : "$N��Ц����������ׯ�ϣ�$w��ӣ�����"+(order[random(13)])+"����Ħ����"NOR"Ϊһʽ������ش���$n��",
        "force" : 170,
        "dodge" : 100,
        "damage": 300,
        "lvl" : 63,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ"+(order[random(13)])+"��̫������"NOR"���⣬�������СС������ԲȦ�������޾�ԴԴ�����ز���$n��",
        "force" : 280,
        "dodge" : 100,
        "damage": 320,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n��"+(order[random(13)])+"����Ħ����"NOR"�Ľ����¶���ţ�",
        "force" : 290,
        "dodge" : 105,
        "damage": 330,
        "lvl" : 77,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$NͻȻ�鲽������ʹ�������䵱"+(order[random(13)])+"�����ѵ�ˮ��"NOR"��һ�У�",
        "force" : 200,
        "dodge" : 105,
        "damage": 360,
        "lvl" : 84,
        "damage_type" : "����"
]),
([      "action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ���������"+(order[random(13)])+"����ħ����"NOR"��"+(order[random(13)])+"������ʽ��"NOR"��",
        "force" : 220,
        "dodge" : 100,
        "damage": 395,
        "lvl" : 91,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�˽����һ�ֹ����"+(order[random(13)])+"�������罣����"NOR"����Ȼ��$n�����Ҵ�������",
        "force" : 240,
        "dodge" : 100,
        "damage": 320,
        "lvl" : 98,
        "damage_type" : "����"
]),
([      "action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ��",
        "force" : 260,
        "dodge" : 100,
        "damage": 350,
        "lvl" : 105,
        "damage_type" : "����"
]),
([      "action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô������",
        "force" : 280,
        "dodge" : 100,
        "damage": 380,
        "lvl" : 112,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻã�",
        "force" : 200,
        "dodge" : 100,
        "damage": 485,
        "lvl" : 119,
        "damage_type" : "����"
]),
([      "action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ��������ȵ�$n���ò��أ�",
        "force" : 320,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 126,
        "damage_type" : "����"
]),
([      "action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n���Կ��彣�����ƣ�",
        "force" : 340,
        "dodge" : 105,
        "damage": 480,
        "lvl" : 133,
        "damage_type" : "����"
]),
([      "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ��",
        "force" : 460,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 140,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼�飡",
        "force" : 480,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 147,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l��",
        "force" : 500,
        "dodge" : 100,
        "damage": 520,
        "lvl" : 154,
        "damage_type" : "����"
]),
([
    "action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡",
        "force" : 600,
        "dodge" : 100,
        "damage": 665,
        "lvl" : 180,
    "damage_type" : "����"
]),
([      "action" : HIW "����$N����$w" HIW "�ƿճ�����ƽƽһ������$n��������ʽ����",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 250,
        "damage_type" : "����"
]),
([      "action" : HIW "$N�����۽������赭д������̳�һ������֮����������ʽ",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 300,
        "damage_type" : "����"
]),
([      "action" : HIW "$N��Ʈ�ݣ���̬��Ȼ������������У�����$w" HIW "����������������¾Ž��ѵ����շ�����ľ���",
        "force" : 600,
        "attack": 100,
        "dodge" : 100,
        "parry" : 300,
        "damage": 560,
        "lvl" : 350,
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "ʥ��ħ��"|| myfam["master_id"] != "a fei")	
            return notify_fail("���¾Ž�ֻ���򰢷�ѧϰ��\n");	
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취�����¾Ž���\n");
        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("���¾Ž�ֻ��ͨ��"+(order[random(13)])+"���ܾ�ʽ��"NOR"��������\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
    int jiali;
	object weapon;
	weapon = me->query_temp("weapon");
        if (random(me->query_skill("lonely-sword",1)) < 100 || me->query_skill("force",1) < 100 )
        return 0;
        if (random(me->query_skill("lonely-sword",1)) > 200 &&
        random(me->query_skill("sword",1))>180 &&
     	me->query_skill("force",1) > 250 
     	&& !victim->is_busy())
{
        me->add("neili", -50);
        victim->map_skill("dodge");
  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+1);
}
        message_vision(HIC "$nͻȻ�ٽ�һ�̣�����������£�ȴĪ�������ͻ����$N�Ĺ��ƣ����$N���ϣ�" NOR, victim,me  );
        return HIR"$n���һ������Ȼ�������ܣ�\n"NOR;
        
}
        if (random(me->query_skill("lonely-sword",1)) > 140 &&	
	 random(me->query_skill("sword",1))>140 &&
            me->query_skill("force",1) > 200 
            && !victim->is_busy())	
{
        
        me->add("neili", -50);
        victim->map_skill("parry");
  if( !victim->is_busy() )
{
        victim->start_busy(random(2)+1);
}
        message_vision(HIC "$n�ٽ��������������ش���$N��������$N��������������һ������������" NOR, victim,me);
        return HIY"$n���Կ��彣������,��Ȼ�����мܣ�\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 130 &&	
        random(me->query_skill("sword",1))>130 &&
	 me->query_skill("force",1) > 150
	 && !victim->is_busy())
{
        me->add("neili", -50);
  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+1);
}
        message_vision(HIC "$n�ὣ�ش̣��������$N��������$N���ò��������أ�����һ�μ����˳�����" NOR, victim,me );
        return HIG"$n��æ���ң����Ҳ�����\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 100 &&
        random(me->query_skill("sword",1))>100 &&
      	me->query_skill("force",1) > 120
      	&& !victim->is_busy() )	
{
if (victim->query("neili")>600)
{
        victim->add("neili", -500);
}
        message_vision(HIC "$nһת���ƣ�����ԴԴ��������$N�������ƣ�\n" NOR, victim,me );
	return HIM"$nʹ������������ѳ���Ȧ��\n"NOR;
}
        if (random(me->query_skill("lonely-sword",1)) > 80 &&	
        random(me->query_skill("sword",1))>80 &&  
	  me->query_skill("force",1) > 100 
	  && !victim->is_busy())	
{

  if( !victim->is_busy() )
{        victim->start_busy(random(2)+1);
}
        message_vision(HIC "$n�ۼ����޿ɱܣ�ֻ���ὣ�Ҵ�һͨ����Ȼ�������ϵؽ�$N�Ĺ�����ȥ��롣" NOR, victim,me );
	return HIW"$n��ʱ�����޴룬��֪����Ǻã�\n"NOR;
  } 
	
	jiali = me->query("jiali");

if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(me->query_skill("lonely-sword",1))>140  /*&& me->query("fengset")*/) {
	victim->receive_wound("qi", damage_bonus+100);
	return HIM"$N�����ݺ�! һ������������$n��$l�������Ѫ��!\n"NOR;
}
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
if ((int)me->query("qi")>1 && (int)me->query("eff_qi")>1)
{
if ((int)me->query("qi") < (int)me->query("eff_qi"))
        i = (int)me->query("eff_qi") / (int)me->query("qi") + 1;
else         i = (int)me->query("max_qi") / (int)me->query("eff_qi") + 1;
        if ( i > 5 ) i = 5;
}
else i=1;
        limbs = ob->query("limbs");
        level = me->query_skill("lonely-sword", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 100 /i 
         && me->query_skill_mapped("sword") =="lonely-sword"
         && me->query_skill_mapped("parry") =="lonely-sword"
         && me->query("fengset")
         && weapon
         && weapon->query("skill_type") == "sword"
         && me->query_skill("sword") > 300
         && random(me->query_skill("sword",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 4000
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIW"$N����ҡҡ��׹���ж����㣬֪����һ���޿ɶ�ܣ�����ͦ���̳������������۵�һ������$n���ʺ�\n"NOR;
            if ( random(level) > ob->query_skill("dodge", 1) / i){
             q = damage * i ;
             if ( q > 3500 ) q = 3500 + ( q - 3500 )/ 100;
             ob->receive_damage("qi", q);
             ob->receive_wound("qi", q/3);
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
             if ( random(me->query("combat_exp")) > ob->query("combat_exp") / i)
             p = ob->query("qi")*100/ob->query("max_qi");
             msg += damage_msg(damage, "����") + "( $n"+eff_status_msg(j)+" )\n";
             msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
             msg = replace_string(msg, "$w", "����");
             j = -(damage/2+random(damage/2));
            }
            else {
              dodge_skill = ob->query_skill_mapped("dodge");
             if( !dodge_skill ) dodge_skill = "dodge";
            msg += SKILL_D(dodge_skill)->query_dodge_msg(ob, 1);
              j = -damage/4; 
            }
            message_vision(msg, me, ob);
            return j;
        }
}
