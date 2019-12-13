// liaoyuan-spear.c ��ԭǹ��
#include <ansi.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
([
"action":"$NԾ�ڰ�գ�һ�С�����չ�᡹������$w�ѻ�������ǹӰ����$n�ۻ����ң���֪���룬��������",
         "force" : 180,
         "dodge" : 20,
         "parry" : 20,
        "damage": 20,
         "lvl" : 0,
         "skill_name" : "����չ��",
         "damage_type":"����"
]),
([
"action":"$Nͦ$w��$n����ʽ��ס��˳��һ�С������ǹ����$w�������ҷɿ����������ǹ�ߣ���$nѹ������",
         "force" : 200,
         "dodge" : 10,
         "parry" : 15,
        "damage": 100,
         "lvl" : 30,
         "skill_name" : "�����ǹ",
         "damage_type":"����"
]),
([
"action":"$Nʹһ�С�ӭ����������������$w��������$n���ţ���ɤ��ǰ��",
         "force" : 220,
         "dodge" : 15,
         "parry" : 20,
        "damage": 40,
         "lvl" : 60,
         "skill_name" : "ӭ��������",
         "damage_type":"����"
]),
([
"action":"$Nһ���粽��ʹһ�С���ɽ��ˮ��������$w�������ٴ���$n��$l",
         "force" : 240,
         "dodge" : 20,
         "parry" : 25,
        "damage": 60,
         "lvl" : 80,
         "skill_name" : "��ɽ��ˮ",
         "damage_type":"����"
]),
([
"action":"$Nһ�С��������ơ���������磬����$n�ɿ챼�ܣ�����$wһ�п���һ�У�ɲ�Ǽ���$n�������ʮ��ǹ",
         "force" : 280,
         "dodge" : 30,
         "parry" : 30,
        "damage": 80,
         "lvl" : 100,
         "skill_name" : "��������",
         "damage_type":"����"
]),
([
"action":
"$Nһ��ǹ�ѣ�һ�С�Ұ����ԭ���������ǹ�����������ң�����ʵʵ����$nȫ��Ҫ��",
         "force" : 260,
         "dodge" : 30,
         "parry" : 40,
        "damage": 100,
         "lvl" : 120,
         "skill_name" : "Ұ����ԭ",
         "damage_type":"����"
]),
([
"action":"$N���һ����һ�С��������졹��$w���ַɳ������ž�������$n��ǰ�ģ��漴����$n����������ְ�$w��������",
         "force" : 300,
         "dodge" : 20,
         "parry" : 30,
        "damage": 80,
         "lvl" : 130,
         "skill_name" : "��������",
         "damage_type":"����"
]),
([
"action":"$Nʹһ�С���ɨ÷���������岻ͣ����ת������$w����ת�������׵糸����$n��$lɨȥ",
         "force" : 300,
         "dodge" : 20,
         "parry" : 30,
        "damage": 80,
         "lvl" : 130,
         "skill_name" : "��ɨ÷��",
         "damage_type":"����"
]),
([
"action":"$N����š�����������գ�һ�С�����հ�ա���$w�й�ֱ��������ƽ�͵ش���$n��$l",
         "force" : 350,
         "dodge" : 20,
         "parry" : 30,
        "damage": 120,
         "lvl" : 130,
         "skill_name" : "����հ��",
         "damage_type":"����"
]),
([
"action":"ֻ��$Nһ��б�磬ʹ�����ٻ������ơ�������$w����һ�����������¶��ϼ���$n$l",
         "force" : 350,
         "dodge" : 20,
         "parry" : 30,
        "damage": 100,
         "lvl" : 150,
         "skill_name" : "�ٻ�������",
         "damage_type":"����"
]),
});

string *parry_msg = ({
"$N��ǹб������ǹ�����ʹ$n���޳���֮����\n",
"$N���г�ǹбָ����$n��ǰһ����$n��������ж��һ�ԣ�",
"$N˫�ֽ�����ǹ��������ԲȦ�������סȫ�����ް�ֿ�϶����$n֮���ƻ��������Ρ�\n",
"ֻ��$Nʹ��������ǧ��֮�ɾ�����ǹб������$n�Ĺ�������һ�ԣ�\n",
"$N����ʮ��ǹ��������ƣ�����ǧ�ٱ���ǹ��סȫ��Բת���⣬���ް��������\n",
"$n��������$N����$N����ǹת������Ȧת���׵ػ��⣡\n"
});

string *msg = ({
HIG"$N����������һʽ��Ұ����ԭ�����ֳ�ǹ���ֻ�������ʵ����"NOR,
MAG"����$Nǹ�����¿��ϡ�����������ʵ�ѵ��˲�ľΪ���ľ���"NOR,
HIW"$N����$w"HIW"��ʹ�ü��죬ȴ˿����������������֮�������ǹ��֮�����Ѵ��ڻ���"NOR,
HIC"$N��������������ﳤ����������$n������$N$w"HIC"һ��������һ�ƽ������"NOR,
HIC"$N����$n��ʽ����ǹ������֮�ơ���ׯ��֮�Σ��������ն�����������������˸����"NOR,
HIB"$Nǹ��ͻ�䣬��ʽ�����������Լ��������������������������⵴��"NOR,
CYN"$N$w����һ�д�����Լ�֮�ۣ�����֮�޷�"NOR,
HIC"$N��Ȼ�����У����ж�δ��ʹ�ϣ����������˳�һ�㣬����ӿ��$n"NOR,
MAG"$N$w"MAG"�ڿ��л��ɴ�Ȧ�����ִ���������Ҳ��������΢��"NOR,
HIW"$Nһǹ�̵�����������������������죬������ǿ"NOR,
HIW"$N����$w"HIW"��ס�Ķ���������$n�����ߴ�ҪѨ��ǹ�⼱��������������δ�"NOR,
MAG"$N����һ���˿�������$w"MAG"ǹ�����಻������������"NOR,
CYN"$N����$w"CYN"ʹ����Ӧ�֣��켫�������������棬�����鶯����ò��⣬ͻȻ����ֱ��$n��$l�̵�"NOR,
HIW"$N����Ԧǹ��ǧ���򻯣������޾���ÿһ�ж�����ƽ����ʵ�������Դ�����ز�¶"NOR,
HIB"$N����Ԧǹ�����಻������������������ʵ��ǧ���򻯣������޾�"NOR,
HIB"$N������Х��ǹ���ݺ�仯������޷���$w"HIB"����������ʹ֮����������������ɵ�"NOR,
HIC"$N���о��ް�����ң�������ǹ��$w"HIC"ÿ��һ�У�����һ���������$n"NOR,
HIR"$Nǹ�����¿��ϡ�����������������ʤ�������Ҫ֮���������˳���������һ���˿������಻��"NOR,
HIR"$N����$w"HIR"������ǰ��������һ���Ρ�$nֻ��һ��ɭɭ������ֱ�ƹ���"NOR,
CYN"$N����$w"CYN"��ס������ͻȻƽ�̣�ǹ�⼱��������������δ���$N��һ����������$n�����ߴ�ҪѨ"NOR,
HIW"$N����δ��ʹ�ϣ���ȻȦת��ͻȻ֮�䣬$n��ǰ�����˼�����ɫ��Ȧ����ȦСȦ����ȦбȦ����˸����"NOR,
});

int valid_enable(string usage) { return  (usage == "spear") || (usage =="parry"); }

int valid_learn(object me)
{
        if (!me->query("sg/tzjj"))
             return notify_fail("��û�еõ��Ϲٰ�����ɣ���ô��͵ѧ��ԭǹ����\n");
         if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������������\n");
         if ((int)me->query_skill("force", 1) < 160)
                return notify_fail("����ڹ����̫ǳ��\n");
         if((int)me->query_skill("spear",1) <=120)
      		return notify_fail("��Ļ���ǹ������㣬����������ԭǹ����\n");
         return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"liaoyuan-spear/" + action;
}
string query_skill_name(int level)
{
         int i;
         for(i = sizeof(action)-1; i >= 0; i--)
                 if(level >= action[i]["lvl"])
                         return action[i]["skill_name"];
}

int double_attack(object me)
{	
        return 1;
   	if ( me->query_skill("liaoyuan-spear", 1) >= 80
     	&& me->query_skill_mapped("spear") == "liaoyuan-spear"
     	&& me->query("zhou/hubo"))
             	return 1;
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
	string msg1;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("liaoyuan-spear",1);
         lvl = (int)me->query_skill("super-strike", 1);
    
        if (random(me->query_skill("spear", 1)) > 100 
        && random(me->query_skill("liaoyuan-spear", 1)) > 100 
        && me->query_skill("force") > 100
	&& random(10)>6
        && me->query("neili") > 30 ) {
                me->add("neili", -20);
                return ([
 			"action": HIG"$N�����������ٳ���$nȴ�����޴����֣��������$N����"+weapon->query("name")+""HIG"��̼��£�$nһ������ͱ�$Nһ�����С�"NOR,
                  	"force": level+level/2+level/3,
                  	"parry": level+level/4,
                  	"dodge": level+level/4,
                  	"damage": level+level/2,
                  	"damage_type": "����"
                ]);
        }
    
            if(me->query_temp("canyun"))
			{
				switch(me->query_temp("canyun"))
				{
				case 2: msg1 = HIY"$N����������ɽ���ƺ����������ٳ�����æ���ң���ʵ����ʵ����������׾��ÿһ�������ж������������ޱȵ����塣"NOR; break;
				case 1: msg1 = HIR"$N�ۼ��Է���������Χ����Ҳ����ȫ����ˣ����³�ǹ�ػ�����ȻȦת������һ�죬��$n$l�ϻ�����ȥ��"NOR; break;
				default: msg1 = HIW"$NͻȻ���һ����������ϣ�����$w"HIW"���������꣬ʹ���������ơ�������ǹӰ������������ŭ������һ�㣡"NOR;break;
				}
				me->add_temp("canyun", -1);      
				return ([
                        "action":msg1, 
                        "force" : level+level/3,
                        "dodge":level+level/3 ,
  "damage":level ,
                        "parry": level/2,
                        "damage_type" : "����",
              ]);
            }
    
        if (me->query_temp("slbw")) { 
  me->delete_temp("slbw");             
                return ([  
                        "action" : HIC"����$NӲ����$n��һ�У�ִǹ���������һ�ڣ�һ�С�������β�����䲻��ص�����$n��$l�ϣ�"NOR,
                        "force":level+level/2,
                        "dodge": level/2,
  "damage":level+level/2 ,
                        "parry": level/2,
                        "damage_type" : "����",
                        ]);
                }

 if( level > 350 ){   
        	if( weapon ){
        		switch(weapon->query("material")){
    				case "wood":
    				case "bamboo": 
    				case "paper":
        				weapon->set_temp("no_weapon_cut", 1); break;
        			default: break;
 }
}
        
        if( level > 450){
  return ([
                        "action":msg[random(sizeof(msg))],
   "damage":level + level/6,
                        "damage_type":"����",
                        "dodge": level/2,
                	"parry":   level/2,
                        "force":level+random(level/2)
                ]);
        }
        
        if( level > 350
	&& random(10)>6){
  return ([
                        "action":msg[random(sizeof(msg))],
                        "damage":level + level/16,
                        "damage_type":"����",
                        "dodge": level/5,
                	"parry":   level/5,
                        "force":level+random(level/5)
                ]);
        }
 }         
         if ( level >= 200 && lvl >= 200 && random(level) > lvl / 2
         && objectp(target = me->select_opponent())
         && objectp(weapon = me->query_temp("weapon"))
        // && me->query_skill_mapped("strike") == "super-strike" 
        // && me->query_skill_prepared("strike") == "super-strike" 
         && me->query("neili") > 300 && me->query("jingli") > 100 ) {
         	pre = me->query_skill_prepare();
        	skill = keys(pre);     
        	for (i=0; i<sizeof(skill); i++){
                	if(skill[i]=="strike") continue; 
                	a = skill[i];
                	b = pre[skill[i]];
                	me->prepare_skill(skill[i]);
        	}
        	
                weapon->unequip();
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
                weapon->wield();
                me->prepare_skill(a,b);
                me->add("neili", -15);
                me->add("jingli", -10);
         }
        


         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    	object weapon, weapon1;
    	int i;    
    	weapon = me->query_temp("weapon");
    	weapon1= victim->query_temp("weapon");

	if( !objectp(weapon) ) return;
	i = me->query_skill("liaoyuan-spear", 1);
	
    	if(weapon1 && me->query("jiali")
       	&& me->query("max_neili") > 1200 && me->query("neili") > 1000 && random(10) >= 7
       	&& random(me->query_str(1)) > 30 
       	&& me->query_skill_mapped("parry") == "liaoyuan-spear"
       	&& random(me->query("combat_exp")) > victim->query("combat_exp")/4){
      		message_vision(HIM"$N��ǹб����"+weapon->name()+HIM"ƽ����$n"+weapon1->name()+HIM"�����ϣ�����������"+weapon1->name()+HIM"��ʱһ����\n"NOR, me,victim);
      		if(random(me->query("str")) > victim->query("str")/3){           
           		me->add("neili", -50);
           		message_vision(HIR"$N��ʽ����ɬ�ͣ�ֻ��������"+weapon1->name()+HIR"���ϵ�������������һ���ѳֲ��������ַɳ���\n"NOR, victim);
           		weapon1->unequip();
           		weapon1->move(environment(victim));
           	}
      		else {
           		message_vision(HIY"$Nһ��ʹ���������˵ò��㣬��"+weapon->name()+HIY"������ת����Ȧ�ӣ�����"+weapon1->name()+HIY"һ����Щ���֣�\n"NOR, victim);
           		victim->add_busy(3);
           	}
    	}
    	
    	else if( i > 350 ){
    		if( i < 350 ) return i/5;
    		switch(weapon->query("material")){
    			case "wood":
    			case "bamboo": 
    			case "paper":
    					if( random(i) > 250 
    					&& !victim->query_temp("lost_attack") 
   && random(me->query_str(1)+me->query_con(1)) > random(victim->query_int(1)*2) 
	&& random(10)>6){
    						victim->add_temp("lost_attack", 1+random(3));
    						message_vision(HIC"$PԽ��Խ���£���$p������ʽ����ɬ�ͣ�\n"NOR, victim, me);
    						i *= 2;
    					}
    					
    					if( i > 450 ) i *= 2;
    				 	i += me->query_skill("force") * 2 + (me->query("jiali") * (10+random(10)));
    					break;
    			default: 	
    					if( i > 450 ) {
    						if( random(i) > 250 
    						&& !victim->query_temp("lost_attack") 
   && random(me->query_str(1)+me->query_con()
	&& random(10)>6) > random(victim->query_int(1)*2) ){
    							victim->add_temp("lost_attack", 1+random(3));
    							message_vision(HIC"$PԽ��Խ���£���$p������ʽ����ɬ�ͣ�\n"NOR, victim, me);
    							i += random(i);
    						}
    						i *= 2;
    				 		i += me->query_skill("force") * 2 + (me->query("jiali") * (10+random(10)));
    						break;
    					}
}
}

        if(random(me->query_skill("liaoyuan-spear", 1)) > 100 &&
            me->query_skill("poison", 1) > 60) {      
            victim->apply_condition("hot_poison", random(6) + 
                    (me->query_skill("poison", 1)/10) +
                    victim->query_condition("hot_poison"));
        }
}


int ob_hit(object ob, object me, int damage)
{
        string msg;
        int i, neili,j,skill, neili1;
        skill = me->query_skill("liaoyuan-spear", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

        if(!living(ob)) return damage;
        if(neili < 300) return damage;
        if(living(me) &&
        userp(me) &&
        random(me->query_str(1)) > ob->query_str(1)/4 &&
        random(me->query("combat_exp")) > ob->query("combat_exp")/10 &&
        me->query_skill("liaoyuan-spear", 1) >= 180 && 
        me->query("neili") > 600 &&
        !me->query_temp("slbw_hit") &&
        !ob->query("env/invisibility"))
        {
                me->set_temp("slbw", 1);
              i = me->query("jiali");
                neili = me->query("neili");
  me->set("jiali", me->query_skill("force") + 100);
        me->add_temp("apply/attack", me->query_skill("liaoyuan-spear", 1));
                me->add_temp("apply/strength", i/2);
            
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
                
                if(me->query("neili") < neili) me->set("neili", neili-100);
                me->set("jiali", i);
                me->add_temp("apply/attack", -me->query_skill("liaoyuan-spear", 1));
                me->add_temp("apply/strength", -i/2);
        }else{       
           msg = parry_msg[random(sizeof(parry_msg))];
             if(neili >= random(neili1)+damage){
              msg += "���������ж����$n��������\n";              
              j = -(damage+skill);
              }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += "���ж����һЩ$n��������\n";
              else msg += "���ж����$nһ���������\n";
              j = -j;
              }
           }           
           message_vision(msg, me, ob);
           return j;
          
     
}

int practice_skill(object me)
{
         object weapon;
         if((int)me->query_skill("spear",1) <=120)
      		return notify_fail("��Ļ���ǹ������㣬����������ԭǹ����\n");
        if (!me->query("sg/tzjj"))
             return notify_fail("��û�еõ��Ϲٰ�����ɣ���ô��͵ѧ��ԭǹ����\n");
         if (!objectp(weapon = me->query_temp("weapon"))
                  || (string)weapon->query("skill_type") != "spear")
                return notify_fail("��ʹ�õ��������ԡ�\n");
         if ((int)me->query("jingli") < 70)
                return notify_fail("���������������ԭǹ����\n");
         if ((int)me->query("neili") < 40)
                return notify_fail("���������������ԭǹ����\n");
                
 me->receive_damage("jingli", 30);           
         if((int)me->query_skill("liaoyuan-spear",1)> 200)
 me->add("neili",-10);

         return 1;
}

int help(object me)
{
	write(HIC"\n��ԭǹ����"NOR"\n");
	write(@HELP
	��ԭǹ��Ϊ����ʱ�廢��֮������������ǹ�������Ƽ��ټ�֮������
	�ٽݾ�����ʹ�˷���ʤ����������ս��ʮ���������·ǹ�����֣�������
	�ᣬ���������괴���˴�ǹ�������ԳƵ������µ�һǹ��������������֪��
	·�δ��������Ϲٽ��������ڱ���ɽ�������ã�
	
HELP
	);
	return 1;
}

