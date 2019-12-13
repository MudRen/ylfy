
#define MY_WEAPON_TYPE "����"
#define MY_ARMOR_TYPE "����"
#define GRANT_WIZ_LEVEL 8

#include <liebiao.h>

inherit F_CLEAN_UP;
inherit F_COLOR;

#include <item_sx.h>

mapping weapon_skill_type = ([
"sword"   :  "����",
"blade"   :  "����",
"axe"     :  "����",
"club"    :  "����",
"dagger"  :  "ì��",
"fork"    :  "�淨",
"hammer"  :  "����",
"staff"   :  "�ȷ�",
"whip"    :  "�޷�",
"spear"   :  "ǹ��",
"unarmed" :  "ȭ��",
"throwing":  "����"
]);

mapping armor_type = ([
"cloth"   :  "�·�",
"armor"   :  "����",
"boots"   :  "ѥ��",
"finger"  :  "��ָ",
"hands"   :  "����",
"head"    :  "ñ��",
"neck"    :  "����",
"shield"  :  "����",
"surcoat" :  "����",
"waist"   :  "����",
"wrists"  :  "����",
"pants"  :   "����"
]);

mapping wear_type = ([
"cloth"   :  "����",
"armor"   :  "����",
"boots"   :  "�Ų�",
"finger"  :  "��ָ",
"hands"   :  "�ֲ�",
"head"    :  "ͷ��",
"neck"    :  "����",
"shield"  :  "����",
"surcoat" :  "����",
"waist"   :  "����",
"wrists"  :  "��",
"pants"  :   "����"
]);

string *look_level_boy = ({
	BLU "ü����б����ͷѢ�ţ���������" NOR,
 	BLU "�������죬������ף�����ޱ�" NOR,
 	BLU "�����Ƥ��ͷ���������˲����ٿ��ڶ���" NOR,
	HIB "��ü���ۣ�������ߣ�������״" NOR,
	HIB "��ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц" NOR,
 	NOR "��հ��ݣ��ݹ����꣬������̾" NOR,
 	NOR "ɵͷɵ�ԣ��ճպ�����������Ҳ��ʵ" NOR,
 	NOR "��òƽƽ�������������ʲôӡ��" NOR,
 	YEL "�����Բ���������⣬���ζ���" NOR,
 	YEL "��Բ���������ڷ����Ǹ񲻷�" NOR,
 	RED "üĿ���㣬�����󷽣�һ���˲�" NOR,
 	RED "˫�۹⻪Ө��͸���������ǵĹ�â" NOR,
 	HIY "�ٶ���������ˮ�����̷��飬������������Ŀ��" NOR,
 	HIY "˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ�" NOR,
 	HIR "�����촽�����˿��Σ���ֹ��������" NOR,
 	HIR "��������Ŀ�����ǣ����˹�Ŀ����" NOR,
 	MAG "�������񣬷�ױ��������������" NOR,
 	MAG "Ʈ�ݳ�������������" NOR,
 	MAG "�����ʣ��������������������ٷ�" NOR,
 	HIM "������ˬ���Ǹ����棬��������" NOR,
 	HIM "һ���������ȣ��ɷ���ǣ���ֹ����" NOR,
});

string *look_level_girl = ({
	BLU "�������Σ�״��ҹ��" NOR,
	BLU "���б�ۣ���ɫ�Ұܣ�ֱ����һ��" NOR,
	BLU "����ü�������ۣ���Ƥ�Ʒ�������һ��������" NOR,
	HIB "��С�綹��üëϡ�裬�����צ����������" NOR,
	HIB "һ�����������һ����û�ø�" NOR,
  	NOR "�������Ƥɫ�ֺڣ���ª����" NOR,
  	NOR "�ɻƿ��ݣ���ɫ���ƣ�����Ů��ζ" NOR,
  	YEL "�����С�������޹⣬��������" NOR,
  	YEL "�䲻���£���Ҳ�׾�����Щ����֮��" NOR,
  	RED "����΢�ᣬ�ŵ��������¿���" NOR,
  	RED "�������ģ�����Ө͸��������˼" NOR,
  	HIR "��С���磬���������������������" NOR,
  	HIR "�������󣬼���ʤѩ��Ŀ����ˮ" NOR,
  	HIW "���۰���������ҩ���̣����￴��" NOR,
  	HIW "����ϸ������欶��ˣ�����һ������������" NOR,
  	MAG "�����������������£�����ܳ�������" NOR,
  	MAG "üĿ�续������ʤѩ�����ν�����߻�" NOR,
  	MAG "�������������Ż���ɽ�����˼�֮����" NOR,
  	HIM "������ϼ���������񣬻�����������" NOR,
  	HIM "�������ɣ���մһ˿�̳�" NOR,
  	HIM "����"+HIW+"������"+HIM+"�������ƻã��Ѳ����Ƿ�������" NOR,
});

string look_item(object me, object obj);
string look_living(object me, object obj);

int main(object me, string arg)
{
	object ob, *inv, room;
	string id, *ids, *id_list, id1, id2, new_id, num, msg, pro;
	int win, i, m, v;

	m = 0;

	if ( !stringp(arg) ) return 0;
	if ( me->query("xieyi/zmud") ) return 0;
	if ( !me->query("env/myhp_show") ) return 0;
	if ( sscanf(arg, "%s,%d", id, win) != 2 ) return 0;
	
	msg = "";
	
	if ( !sscanf(id, "%s %s", id1, id2) )
	{
		new_id = id; // �������⴦��ʱ�ģ������ id ���� new_id
		v = 0;
	}
	else
	{
		id_list = explode(id , " ");
		if ( !stringp(num = id_list[sizeof(id_list)-1]) ) return 0; // δ֪�����ͣ���ֱ���˳�
		
		if ( !(v = atoi(num)) ) new_id = id; // ���������⴦��ĸ�ʽ������Ϊ new_id ����ԭ���� id
		else new_id = replace_string(id, " "+v, ""); // �����⴦��ĸ�ʽ���������»����ȷ�� id(new_id)
	}
	// ���ǰѴ���ĳ����ʽ�������ָ����λ�õ������ʽ����
	if ( !v )
		v = 1;
	
	switch ( win )
	{
		// ͬ�����²˵�
		case 0 :
				// ��� me �Ƿ��л�����û����ֱ�ӷ���
				if ( !objectp(room = environment(me)) )
						return 1;
				// ͨ��������������� ob
				inv = all_inventory(room);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// ����������֤ ob ����ʵ id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						if ( m == v )
						{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
						}
						else
							continue; // �粢����ָ����λ���ϣ������������һ��λ��
					}
					// ��֤αװ��� id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// �ҵ���αװ�˵� ob �� id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
							}
							else
								continue; // �粢����ָ����λ���ϣ������������һ��λ��
						}
					}
				}
				break;
		
		case 1 :
				// ��� me �Ƿ���Ч���ڣ�û����ֱ�ӷ���
				if ( !objectp(me) )
						return 1;
				// ͨ��������������� ob
				inv = all_inventory(me);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// ����������֤ ob ����ʵ id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						if ( m == v )
						{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
						}
						else
							continue; // �粢����ָ����λ���ϣ������������һ��λ��
					}
					// ��֤αװ��� id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// �ҵ���αװ�˵� ob �� id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // �ҵ�����ָ����λ���ϣ���ô������Ҫ�� ob ���������
								break;
							}
							else
								continue; // �粢����ָ����λ���ϣ������������һ��λ��
						}
					}
				}
				break;
	}
	
	if ( !objectp(ob) ) return 1;

	if ( ob->is_corpse() ) 
	{
		msg += "�����ơ���"+ob->query("name")+"("+ob->query("id")+")$$";
		msg += "����顿��"+sort_string(ob->long(), 73, 10)+"$$";
		msg += " ���ͣ�ʬ��$$$$";

		inv = all_inventory(ob);
		pro = (ob==me) ? gender_self(ob->query("gender")) : gender_pronoun(ob->query("gender"));
		if( sizeof(inv) ) 
		{
			inv = map_array(inv, "inventory_look", this_object());
			if( sizeof(inv) )
				msg += sprintf("%s���������У�$$ %s$$", pro, implode(inv, "$$ ") );
		}
		else
			msg += sprintf("%s��������ʲôҲû�С�$$", pro);
	}
	else if ( ob->is_character() )
	{
		if ( !playerp(ob) || wizardp(me) || !ob->query_temp("apply/id") )
		{
			msg += "�����ơ���"+ob->query("name")+"("+ob->query("id")+")$$";
			msg += "����顿��"+sort_string(replace_string(ob->long(1),"\n", ""), 73, 10)+"$$";
			if ( playerp(ob) ) 
				msg += " ���ͣ����$$$$";
			else
				msg += " ���ͣ�NPC$$$$";
		}

		msg += look_living(me, ob);
	}
	else
	{
		if ( mapp(ob->query("weapon_prop")) || mapp(ob->query("armor_prop")) )
		{
			msg += look_item(me, ob);
		}
		else
		{
			msg += "�����ơ���"+ob->query("name")+"("+ob->query("id")+")$$";
			msg += "����顿��"+sort_string(ob->long(), 73, 10)+"$$";
			msg += " ���ͣ���ͨ��Ʒ$$$$";
			inv = all_inventory(ob);
			if ( sizeof(inv) ) 
			{
				inv = map_array(inv, "inventory_look", this_object() );
				msg += sprintf("�����У�$$ %s$$", implode(inv, "$$ ") );
			}
		}
	}

	write(SHOWIETM(clean_color(msg)));
	return 1;
}

string look_item(object me, object obj)
{
	string msg;
	int v_num, i;

	// Add By Wenwu
	//------------------------------------------------------
	msg = "�����ơ���"+obj->query("name")+"("+obj->query("id")+")$$";
	//------------------------------------------------------
	//����ħ����ָ�������⴦��
	if ( obj->query("old_copy_log") && obj->query("diablo/only_me") != me->query("id") )
		msg += "����顿��"+sort_string(replace_string(obj->query("old_copy_log"),"\n", ""), 73, 10)+"$$";
	else
		msg += "����顿��"+sort_string(replace_string(obj->long(),"\n", ""), 73, 10)+"$$";

	// ������ʾ
	// ����
	if ( obj->query("weapon_prop") )
	{
		msg += " ���ͣ�"+MY_WEAPON_TYPE+"$$";
		v_num = 0;
		for (i = 0; i < sizeof(weapon_shuxing); i++)
		{
			if ( obj->query("weapon_prop/" + keys(weapon_shuxing)[i]) )
				v_num++;
		}
		msg += " Ʒ�ף�"+v_num+"$$";
		msg += " �ȼ���"+obj->query("weapon_prop/level")+"$$";

		if ( obj->query("flag") & 1 )
			msg += " ʹ�����ͣ�˫��$$";
		else 
			msg += " ʹ�����ͣ�����$$";

		msg += " Ӧ�����ͣ�"+weapon_skill_type[obj->query("skill_type")]+"$$$$";

		if ( obj->query("weapon_prop/damage") )
			msg += " �﹥��"+obj->query("weapon_prop/damage")+"$$";

		if ( obj->query("weapon_prop/strength") )
			msg += " ������"+obj->query("weapon_prop/strength")+"$$";

		if ( obj->query("weapon_prop/intelligence") )
			msg += " ���ԣ�"+obj->query("weapon_prop/intelligence")+"$$";

		if ( obj->query("weapon_prop/constitution") )
			msg += " ���ǣ�"+obj->query("weapon_prop/constitution")+"$$";

		if ( obj->query("weapon_prop/dexerity") )
			msg += " ����"+obj->query("weapon_prop/dexerity")+"$$";

		if ( obj->query("weapon_prop/karma") )
			msg += " ��Ե��"+obj->query("weapon_prop/karma")+"$$";

		if ( obj->query("weapon_prop/personality") )
			msg += " ��ò��"+obj->query("weapon_prop/personality")+"$$";

		if ( obj->query("weapon_prop/dodge") )
			msg += " �Ṧ��"+obj->query("weapon_prop/dodge")+"$$";

		if ( obj->query("weapon_prop/unarmed") )
			msg += " ȭ�ţ�"+obj->query("weapon_prop/unarmed")+"$$";

		if ( obj->query("weapon_prop/force") )
			msg += " �ڹ���"+obj->query("weapon_prop/force")+"$$";

		if ( obj->query("weapon_prop/parry") )
			msg += " �мܣ�"+obj->query("weapon_prop/parry")+"$$";

		if ( obj->query("weapon_prop/sword") )
			msg += " ������"+obj->query("weapon_prop/sword")+"$$";

		if ( obj->query("weapon_prop/blade") )
			msg += " ������"+obj->query("weapon_prop/blade")+"$$";

		if ( obj->query("weapon_prop/axe") )
			msg += " ������"+obj->query("weapon_prop/axe")+"$$";

		if ( obj->query("weapon_prop/stick") )
			msg += " ������"+obj->query("weapon_prop/stick")+"$$";

		if ( obj->query("weapon_prop/staff") )
			msg +=" �ȷ���"+obj->query("weapon_prop/staff")+"$$";

		if ( obj->query("weapon_prop/spear") )
			msg+=" ǹ����"+obj->query("weapon_prop/spear")+"$$";

		if ( obj->query("weapon_prop/fork") )
			msg+=" �淨��"+obj->query("weapon_prop/fork")+"$$";

		if ( obj->query("weapon_prop/club") )
			msg+=" ������"+obj->query("weapon_prop/club")+"$$";

		if ( obj->query("weapon_prop/throwing") )
			msg+=" ������"+obj->query("weapon_prop/throwing")+"$$";

		if ( obj->query("weapon_prop/hammer") )
			msg +=" ������"+obj->query("weapon_prop/hammer")+"$$";

		if ( obj->query("weapon_prop/taoism") )
			msg+=" ��ѧ�ķ���"+obj->query("weapon_prop/taoism")+"$$";

		if ( obj->query("weapon_prop/whip") )
			msg+=" �޷���"+obj->query("weapon_prop/whip")+"$$";

		if ( obj->query("weapon_prop/strike") )
			msg+=" �Ʒ���"+obj->query("weapon_prop/strike")+"$$";

		if ( obj->query("weapon_prop/finger") )
			msg+=" ָ����"+obj->query("weapon_prop/finger")+"$$";

		if ( obj->query("weapon_prop/magic") )
			msg+=" ����ħ����"+obj->query("weapon_prop/magic")+"$$";

		if ( obj->query("weapon_prop/spells") )
			msg+=" ����������"+obj->query("weapon_prop/spells")+"$$";

		if ( obj->query("weapon_prop/poison") )
			msg+=" ������"+obj->query("weapon_prop/poison")+"$$";

		if ( obj->query("weapon_prop/hand") )
			msg+=" �ַ���"+obj->query("weapon_prop/hand")+"$$";

		if ( obj->query("weapon_prop/cuff") )
			msg+=" ȭ����"+obj->query("weapon_prop/cuff")+"$$";

		if ( obj->query("weapon_prop/claw") )
			msg+=" צ����"+obj->query("weapon_prop/claw")+"$$";
	}
	else if ( obj->query("armor_prop") ) // ����
	{
		msg += " ���ͣ�"+MY_ARMOR_TYPE+"$$";
		v_num = 0;
		for (i = 0; i < sizeof(armor_shuxing); i++)
		{
			if ( obj->query("armor_prop/" + keys(armor_shuxing)[i]) )
				v_num++;
		}
		msg += " Ʒ�ף�"+v_num+"$$";
		msg += " �ȼ���"+obj->query("armor_prop/level")+"$$";

		if ( obj->query("armor_type") )
		{
			msg += " ʹ�����ͣ�"+armor_type[obj->query("armor_type")]+"$$";
			msg += " Ӧ�����ͣ�"+wear_type[obj->query("armor_type")]+"$$$$";
		}

		if ( obj->query("armor_prop/armor") )
			msg += " �����"+obj->query("armor_prop/armor")+"$$";

		if ( obj->query("armor_prop/strength") )
			msg += " ������"+obj->query("armor_prop/strength")+"$$";

		if ( obj->query("armor_prop/intelligence") )
			msg += " ���ԣ�"+obj->query("armor_prop/intelligence")+"$$";

		if ( obj->query("armor_prop/constitution") )
			msg += " ���ǣ�"+obj->query("armor_prop/constitution")+"$$";

		if ( obj->query("armor_prop/dexerity") )
			msg += " ����"+obj->query("armor_prop/dexerity")+"$$";

		if ( obj->query("armor_prop/karma") )
			msg += " ��Ե��"+obj->query("armor_prop/karma")+"$$";

		if ( obj->query("armor_prop/personality") )
			msg += " ��ò��"+obj->query("armor_prop/personality")+"$$";

		if ( obj->query("armor_prop/armor_vs_force") )
			msg += " �������壺"+YEL+obj->query("armor_prop/armor_vs_force")+"$$";

		if ( obj->query("armor_prop/dodge") )
			msg += " �Ṧ��"+obj->query("armor_prop/dodge")+"$$";

		if ( obj->query("armor_prop/unarmed") )
			msg += " ȭ�ţ�"+obj->query("armor_prop/unarmed")+"$$";

		if ( obj->query("armor_prop/force") )
			msg += " �ڹ���"+obj->query("armor_prop/force")+"$$";

		if ( obj->query("armor_prop/parry") )
			msg += " �мܣ�"+obj->query("armor_prop/parry")+"$$";

		if ( obj->query("armor_prop/sword") )
			msg += " ������"+obj->query("armor_prop/sword")+"$$";

		if ( obj->query("armor_prop/blade") )
			msg += " ������"+obj->query("armor_prop/blade")+"$$";

		if ( obj->query("armor_prop/axe") )
			msg += " ������"+obj->query("armor_prop/axe")+"$$";

		if ( obj->query("armor_prop/stick") )
			msg += " ������"+obj->query("armor_prop/stick")+"$$";

		if ( obj->query("armor_prop/staff") )
			msg += " �ȷ���"+obj->query("armor_prop/staff")+"$$";

		if ( obj->query("armor_prop/spear") )
			msg += " ǹ����"+obj->query("armor_prop/spear")+"$$";

		if ( obj->query("armor_prop/fork") )
			msg += " �淨��"+obj->query("armor_prop/fork")+"$$";

		if ( obj->query("armor_prop/club") )
			msg += " ������"+obj->query("armor_prop/club")+"$$";

		if ( obj->query("armor_prop/throwing") )
			msg += " ������"+obj->query("armor_prop/throwing")+"$$";

		if ( obj->query("armor_prop/hammer") )
			msg += " ������"+obj->query("armor_prop/hammer")+"$$";

		if ( obj->query("armor_prop/taoism") )
			msg += " ��ѧ�ķ���"+obj->query("armor_prop/taoism")+"$$";

		if ( obj->query("armor_prop/whip") )
			msg += " �޷���"+obj->query("armor_prop/whip")+"$$";

		if ( obj->query("armor_prop/strike") )
			msg += " �Ʒ���"+obj->query("armor_prop/strike")+"$$";

		if ( obj->query("armor_prop/finger") )
			msg += " ָ����"+obj->query("armor_prop/finger")+"$$";

		if ( obj->query("armor_prop/magic") )
			msg += " ����ħ����"+obj->query("armor_prop/magic")+"$$";

		if ( obj->query("armor_prop/spells") )
			msg += " ����������"+obj->query("armor_prop/spells")+"$$";

		if ( obj->query("armor_prop/poison") )
			msg += " ������"+obj->query("armor_prop/poison")+"$$";

		if ( obj->query("armor_prop/hand") )
			msg += " �ַ���"+obj->query("armor_prop/hand")+"$$";

		if ( obj->query("armor_prop/cuff") )
			msg += " ȭ����"+obj->query("armor_prop/cuff")+"$$";

		if ( obj->query("armor_prop/claw") )
			msg += " צ����"+obj->query("armor_prop/claw")+"$$";
	}

    return msg;
}

string inventory_look(object obj, int flag)
{
	string str;

	if ( !flag )
		return "     "+obj->short();

	if( obj->query("equipped") )
	{
		switch( obj->query("armor_type") ) 
		{
			case "cloth":
			case "armor":   str = "��";break; break;
			case "boots":   str = "�Ŵ�";break; break;
			case "head":    str = "ͷ��";break;
			case "pants":   str = "���ϴ���";break;
			case "neck":    str = "��Χ";break;
			case "wrists":  str = "�������";break;
			case "finger":  str = "��ָ�ϴ���";break;
			case "hands":   str = "��������";break;
			case "waist":   str = "�������";break;
			default:
				if ( environment(obj)->query_temp("weapon")==obj ) 
					str = "����ִ";
				else 
					str = "����ִ";
		}
		str += "һ" + obj->query("unit")+obj->query("name")+"��";
	}
    return str;
}

string look_living(object me, object obj)
{
    int per_temp,i;
    string str, pro,*skills_name;
    mixed *inv;
    mapping my_fam, fam,skills;
    
	str = "";

	if ( !objectp(present("fire", me)) 
		&& environment(me)->query("outdoors") 
		&& NATURE_D->outdoor_room() 
		&& !wizardp(me) )
	{
		str += sprintf("�㿴��ǰ���ƺ��и���Ӱ������̫���ˣ�����̫�����$$");
        return str;
    }

	if ( obj->query_temp("apply/name") ) 
	{
		str += sprintf("�Է��ƺ��Ǿ������ݸİ�ģ��޷���������ʵ��$$");
        return str;
	}

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	
	if( (string)obj->query("race")=="����" 
		&& intp(obj->query("age")) )
		str += sprintf("%s������Լ%s���ꡣ$$", pro, chinese_number(obj->query("age") / 10 * 10));
	per_temp= (obj->query_per()>=30)?20:(obj->query_per()-10);
	
	if ( per_temp<0 ) per_temp=0;
	
	if ( (string)obj->query("race")=="����" ) 
	{
		if ( (string)obj->query("gender") == "Ů��")
			str += sprintf("%s����%s��$$", pro, look_level_girl[per_temp]);
		else
			str += sprintf("%s����%s��$$", pro, look_level_boy[per_temp]);
		skills=obj->query_skills();
		if (!sizeof(skills))
			str+=sprintf("%s�������ƺ������κ��书��$$", pro);
		else
		{
			skills_name=sort_array( keys(skills), (: strcmp :) );
			i=random(sizeof(skills_name));
			if (SKILL_D(skills_name[i])->type()=="knowledge")
				str+=sprintf("%s�������ƺ������κ��书��$$", pro);
			else
				str+=sprintf("%s���书�������ƺ�%s��$$", pro,"/cmds/usr/skills"->skill_level(SKILL_D(skills_name[i])->type(), skills[skills_name[i]]));
		}
	}
   
	// If we both has family, check if we have any relations.
	if(obj!=me && obj->query("id")==me->query("couple/couple_id"))
	{	
		if(me->query("gender")=="Ů��") 
			str+=pro+"������Ϲ���$$";	
		else 
			if (me->query("gender")=="����") 
			str+=pro+"��������š�$$";	
	}
    
	if( obj!=me
		&& mapp(fam = obj->query("family"))
		&& mapp(my_fam = me->query("family")) 
		&& fam["family_name"] == my_fam["family_name"] ) 
	{
    
        if( fam["generation"]==my_fam["generation"] ) 
		{
            if( (string)obj->query("gender") == "����" )
                str += sprintf( pro + "�����%s%s��$$", 
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                    my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else
				str += sprintf( pro + "�����%s%s��$$",
                    my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                    my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
        } 
		else if( fam["generation"] < my_fam["generation"] ) 
		{
            if( my_fam["master_id"] == obj->query("id") )
                str += pro + "�����ʦ����$$";
            else if( my_fam["generation"] - fam["generation"] > 1 )
                str += pro + "�����ͬ�ų�����$$";
            else if( fam["enter_time"] < my_fam["enter_time"] )
                str += pro + "�����ʦ����$$";
            else
                str += pro + "�����ʦ�塣$$";
        } 
		else 
		{
            if( fam["generation"] - my_fam["generation"] > 1 )
                str += pro + "�����ͬ������$$";
            else if( fam["master_id"] == me->query("id") )
                str += pro + "����ĵ��ӡ�$$";
            else
                str += pro + "�����ʦֶ��$$";
        }
    }

    if( obj->query("max_qi") )
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "$$";
    
	inv = all_inventory(obj);
    if( sizeof(inv) ) 
	{
        inv = map_array(inv, "inventory_look", this_object(), 1 );
		inv -= ({0});
        if( sizeof(inv) )
			str += sprintf( "$$%s%s$$", pro, implode(inv, "$$") );
        if (!obj->query_temp("armor/cloth") && obj->query("race")=="����" )
            str+=pro+"����"+YEL+"����"+NOR+"��ʲôҲû����$$";
    }
	else 
		str += sprintf((obj->query("race")=="����"?"%s����"+YEL+"����"+NOR+"��ʲôҲû����$$":"��������û���κζ�����$$"),pro);

	return str;
}