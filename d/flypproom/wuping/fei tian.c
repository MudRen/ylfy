//fei tian.c
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
set_name( HIR "����" NOR , ({ "feitian sword","sword","jian"}));      	
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		 set("icon", "10030");
set("long", HIC"��˵�а���������佣,��˵�����ɽ�����֮�������žŰ�ʮһ�����.��˵�˽��з���ݵ�֮��ͨ,�ʶ���Ϊ"HIR"����!\n");
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);
                set("no_drop",1);
                set("value", 20000);
                set("material", "steel");
                set("weapon_prop/strength", 30);
                set("weapon_prop/unarmed", 100);
set("wield_msg",HIC"$N���һ��,˫��ƽ������.........\n"
HIR"ɲ�Ǽ���Ʊ�ɫ.�·���$Nɱ����Ӧһ��,��ҲΪ֮��ŭ.����һ�������\n"
HIY"        �ϡ�...��.....��...��...��.....��...����...\n"
HIC"һ���޴����������$N������.���ŵ���������ȥ,һ�ѵ�����µ�˫�־޽�Ҳ������չ¶��$N������.\n" NOR);	
set("unwield_msg", HIM"����$N"HIR"ɱ��"HIC"�ļ���,"HIY"��"HIR"����"HIW"�Ĺ�âҲԽ��Խƽ��.����$N��"HIR"ɱ��"HIC"��ȫ��ʧ,"HIR"����"HIY"Ҳ����һ�������ʧ�ھ���֮�⣡" NOR);
        }
init_sword(1500,1);	
        setup();
}

mixed hit_ob(object me,object victim,int damage_bonus)
{
	if ( me->query_skill_mapped("sword") == "taiji-jian" ) 
	{
		victim->receive_damage("jing", random(damage_bonus));
		me->add("neili", -(int)me->query("jiali"));
		return HIM "����$N"HIR"ɱ��"HIC"������,������"HIR"����"HIC"�����"HIY"���"HIC"��Ȼ���ų�"HIR"����"HIY"�Ĺ�â!\n" NOR;
	}

}

int query_autoload() { return 1; }      	
