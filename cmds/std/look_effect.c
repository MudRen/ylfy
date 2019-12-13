

#define MY_WEAPON_TYPE "����"
#define MY_ARMOR_TYPE "����"
#define GRANT_WIZ_LEVEL 8

#include <liebiao.h>
#include <item.h>

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
"pants"   :  "����"
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
"pants"   :  "����"
]);

string look_item(object me, object obj);
int resolve_data(object ob, string data, string type);

int main(object me, string arg)
{
	object ob, *inv, room;
	string id, *ids, *id_list, id1, id2, new_id, num, msg, cue;
	int win, i, m, v, is_set, is_right, is_allow;
	string is_name, is_id, is_type, is_data;

	m = 0;
	is_set = 0;
	is_allow = 0;

	if ( !stringp(arg) ) return 0;
	if ( me->query("xieyi/zmud") ) return 0;
	if ( !me->query("env/myhp_show") ) return 0;

	if ( sscanf(arg, "set %s>%s>>%s>>>%s<%s", arg,is_type,is_name,is_id,is_data) == 5 ) 
	{
		if ( wiz_level(me) > GRANT_WIZ_LEVEL )
			is_set = 1;
		is_allow = 1;
	}

	if ( sscanf(arg, "%s,%d", id, win) != 2 ) return 0;
	
	msg = "���="+arg+";";
	
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
	
	if ( !objectp(ob) ) 
	{
		write(LOOK("��ʾ=Err:�����������޷���ʾ��Ʒ���ϡ�;"));
		return 1; 
	}

	if ( is_set )
	{
		//ob->set_name(is_name, ({is_id}));
		is_right = resolve_data(ob, is_data, is_type);
		
		if ( !is_right )
			cue = "��ʾ=�޸�ʧ�ܣ��������޷���ȷ�������ݰ�;";
		else if ( is_right == -1 )
			cue = "��ʾ=�޸�ʧ�ܣ�Ŀǰֻ֧���޸�װ������;";
		else
			cue = "��ʾ=�޸ĳɹ�;";
	}

	msg += "Ȩ��="+wiz_level(me)+";";

	if ( ob->is_corpse() ) 
	{
		msg += "װ������=ʬ��;";
		msg += "������="+ob->query("name")+";Ӣ����="+ob->query("id")+";";
		msg += "����="+ob->long()+";";
		if ( !is_allow )
			cue = "��ʾ=�������������ר�����װ��ϵͳ���ģ����Է�װ�����ֻ�ܼ���ʾ�С�Ӣ�����������������������Ĳ���ֻ��˵����Ǹ�ˣ���ʱ��Ļ����������Ƶġ�;";
	}
	else if ( ob->is_character() )
	{
		if ( playerp(ob) ) 
			msg += "װ������=���;";
		else
			msg += "װ������=NPC;";
		msg += "������="+ob->query("name")+";Ӣ����="+ob->query("id")+";";
		msg += "����="+ob->long()+";";
		if ( !is_allow )
			cue = "��ʾ=�������������ר�����װ��ϵͳ���ģ����Է�װ�����ֻ�ܼ���ʾ�С�Ӣ�����������������������Ĳ���ֻ��˵����Ǹ�ˣ���ʱ��Ļ����������Ƶġ�;";
	}
	else
	{
		if ( mapp(ob->query("weapon_prop")) || mapp(ob->query("armor_prop")) )
		{
			msg += look_item(me, ob);
		}
		else
		{
			msg += "װ������=��ͨ��Ʒ;";
			msg += "������="+ob->query("name")+";Ӣ����="+ob->query("id")+";";
			msg += "����="+ob->long()+";";
			if ( !is_allow )
				cue = "��ʾ=�������������ר�����װ��ϵͳ���ģ����Է�װ�����ֻ�ܼ���ʾ�С�Ӣ�����������������������Ĳ���ֻ��˵����Ǹ�ˣ���ʱ��Ļ����������Ƶġ�;";
		}
	}

	if ( is_allow && !is_set )
		cue = "��ʾ=�޸�ʧ�ܣ�����Ȩ�޲������������ܾ����и������;";

	msg += cue;
	write(LOOK(clean_color(msg)));
	return 1;
}

string look_item(object me, object obj)
{
	string msg;
	int v_num, i;

	// Add By Wenwu
	//------------------------------------------------------
	msg = "������="+obj->query("name")+";Ӣ����="+obj->query("id")+";";
	//------------------------------------------------------
	//����ħ����ָ�������⴦��
	if ( obj->query("old_copy_log") && obj->query("diablo/only_me") != me->query("id") )
		msg += "����="+obj->query("old_copy_log")+";";
	else
		msg += "����="+obj->long()+";";

	// ������ʾ
	// ����
	if ( obj->query("weapon_prop") )
	{
		msg += "װ������="+MY_WEAPON_TYPE+";";
		v_num = 0;
		for (i = 0; i < sizeof(weapon_shuxing); i++)
		{
			if ( obj->query("weapon_prop/" + keys(weapon_shuxing)[i]) )
				v_num++;
		}
		msg += "Ʒ��="+v_num+";";
		msg += "�ȼ�="+obj->query("weapon_prop/level")+";";

		if ( obj->query("flag") & 1 )
		{
			msg += "ʹ������=˫��;";
			if ( !stringp(obj->query("pic_name")) )
			{
				if ( obj->query("skill_type") == "sword" )
					obj->set("pic_name", ""+(100+random(WEAPON_SWORD_PIC_NUM_BOTH)));
				if ( obj->query("skill_type") == "blade" )
					obj->set("pic_name", ""+(100+random(WEAPON_BLADE_PIC_NUM_BOTH)));
			}
		}
		else
		{
			msg += "ʹ������=����;";
			if ( !stringp(obj->query("pic_name")) )
			{
				if ( obj->query("skill_type") == "sword" )
					obj->set("pic_name", ""+(random(WEAPON_SWORD_PIC_NUM_ODD)));
				if ( obj->query("skill_type") == "blade" )
					obj->set("pic_name", ""+(random(WEAPON_BLADE_PIC_NUM_ODD)));
			}
		}
		msg += "item_type="+obj->query("skill_type")+";pic_name="+obj->query("pic_name")+";";

		msg += "Ӧ������="+weapon_skill_type[obj->query("skill_type")]+";";

		if ( obj->query("weapon_prop/damage") )
			msg += "�﹥="+obj->query("weapon_prop/damage")+";";

		if ( obj->query("weapon_prop/strength") )
			msg += "����="+obj->query("weapon_prop/strength")+";";

		if ( obj->query("weapon_prop/intelligence") )
			msg += "����="+obj->query("weapon_prop/intelligence")+";";

		if ( obj->query("weapon_prop/constitution") )
			msg += "����="+obj->query("weapon_prop/constitution")+";";

		if ( obj->query("weapon_prop/dexerity") )
			msg += "��="+obj->query("weapon_prop/dexerity")+";";

		if ( obj->query("weapon_prop/karma") )
			msg += "��Ե="+obj->query("weapon_prop/karma")+";";

		if ( obj->query("weapon_prop/personality") )
			msg += "��ò="+obj->query("weapon_prop/personality")+";";

		if ( obj->query("weapon_prop/dodge") )
			msg += "�Ṧ="+obj->query("weapon_prop/dodge")+";";

		if ( obj->query("weapon_prop/unarmed") )
			msg += "ȭ��="+obj->query("weapon_prop/unarmed")+";";

		if ( obj->query("weapon_prop/force") )
			msg += "t�ڹ�="+obj->query("weapon_prop/force")+";";

		if ( obj->query("weapon_prop/parry") )
			msg += "�м�="+obj->query("weapon_prop/parry")+";";

		if ( obj->query("weapon_prop/sword") )
			msg += "����="+obj->query("weapon_prop/sword")+";";

		if ( obj->query("weapon_prop/blade") )
			msg += "����="+obj->query("weapon_prop/blade")+";";

		if ( obj->query("weapon_prop/axe") )
			msg += "����="+obj->query("weapon_prop/axe")+";";

		if ( obj->query("weapon_prop/stick") )
			msg += "����="+obj->query("weapon_prop/stick")+";";

		if ( obj->query("weapon_prop/staff") )
			msg +="�ȷ�="+obj->query("weapon_prop/staff")+";";

		if ( obj->query("weapon_prop/spear") )
			msg+="ǹ��="+obj->query("weapon_prop/spear")+";";

		if ( obj->query("weapon_prop/fork") )
			msg+="�淨="+obj->query("weapon_prop/fork")+";";

		if ( obj->query("weapon_prop/club") )
			msg+="����="+obj->query("weapon_prop/club")+";";

		if ( obj->query("weapon_prop/throwing") )
			msg+="����="+obj->query("weapon_prop/throwing")+";";

		if ( obj->query("weapon_prop/hammer") )
			msg +="����="+obj->query("weapon_prop/hammer")+";";

		if ( obj->query("weapon_prop/taoism") )
			msg+="��ѧ�ķ�="+obj->query("weapon_prop/taoism")+";";

		if ( obj->query("weapon_prop/whip") )
			msg+="�޷�="+obj->query("weapon_prop/whip")+";";

		if ( obj->query("weapon_prop/strike") )
			msg+="�Ʒ�="+obj->query("weapon_prop/strike")+";";

		if ( obj->query("weapon_prop/finger") )
			msg+="ָ��="+obj->query("weapon_prop/finger")+";";

		if ( obj->query("weapon_prop/magic") )
			msg+="ħ������="+obj->query("weapon_prop/magic")+";";

		if ( obj->query("weapon_prop/spells") )
			msg+="��������="+obj->query("weapon_prop/spells")+";";

		if ( obj->query("weapon_prop/poison") )
			msg+="����="+obj->query("weapon_prop/poison")+";";

		if ( obj->query("weapon_prop/hand") )
			msg+="�ַ�="+obj->query("weapon_prop/hand")+";";

		if ( obj->query("weapon_prop/cuff") )
			msg+="ȭ��="+obj->query("weapon_prop/cuff")+";";

		if ( obj->query("weapon_prop/claw") )
			msg+="צ��="+obj->query("weapon_prop/claw")+";";
	}
	else if ( obj->query("armor_prop") ) // ����
	{
		msg += "װ������="+MY_ARMOR_TYPE+";";
		v_num = 0;
		for (i = 0; i < sizeof(armor_shuxing); i++)
		{
			if ( obj->query("armor_prop/" + keys(armor_shuxing)[i]) )
				v_num++;
		}
		msg += "Ʒ��="+v_num+";";
		msg += "�ȼ�="+obj->query("armor_prop/level")+";";

		if ( obj->query("armor_type") )
		{
			msg += "ʹ������="+armor_type[obj->query("armor_type")]+";";
			msg += "Ӧ������="+wear_type[obj->query("armor_type")]+";";
		}

		if ( obj->query("armor_prop/armor") )
			msg += "���="+obj->query("armor_prop/armor")+";";

		if ( obj->query("armor_prop/strength") )
			msg += "����="+obj->query("armor_prop/strength")+";";

		if ( obj->query("armor_prop/intelligence") )
			msg += "����="+obj->query("armor_prop/intelligence")+";";

		if ( obj->query("armor_prop/constitution") )
			msg += "����="+obj->query("armor_prop/constitution")+";";

		if ( obj->query("armor_prop/dexerity") )
			msg += "��="+obj->query("armor_prop/dexerity")+";";

		if ( obj->query("armor_prop/karma") )
			msg += "��Ե="+obj->query("armor_prop/karma")+";";

		if ( obj->query("armor_prop/personality") )
			msg += "��ò="+obj->query("armor_prop/personality")+";";

		if ( obj->query("armor_prop/armor_vs_force") )
			msg += "��������="+YEL+obj->query("armor_prop/armor_vs_force")+";";

		if ( obj->query("armor_prop/dodge") )
			msg += "�Ṧ="+obj->query("armor_prop/dodge")+";";

		if ( obj->query("armor_prop/unarmed") )
			msg += "ȭ��="+obj->query("armor_prop/unarmed")+";";

		if ( obj->query("armor_prop/force") )
			msg += "�ڹ�="+obj->query("armor_prop/force")+";";

		if ( obj->query("armor_prop/parry") )
			msg += "�м�="+obj->query("armor_prop/parry")+";";

		if ( obj->query("armor_prop/sword") )
			msg += "����="+obj->query("armor_prop/sword")+";";

		if ( obj->query("armor_prop/blade") )
			msg += "����="+obj->query("armor_prop/blade")+";";

		if ( obj->query("armor_prop/axe") )
			msg += "����="+obj->query("armor_prop/axe")+";";

		if ( obj->query("armor_prop/stick") )
			msg += "����="+obj->query("armor_prop/stick")+";";

		if ( obj->query("armor_prop/staff") )
			msg += "�ȷ�="+obj->query("armor_prop/staff")+";";

		if ( obj->query("armor_prop/spear") )
			msg += "ǹ��="+obj->query("armor_prop/spear")+";";

		if ( obj->query("armor_prop/fork") )
			msg += "�淨="+obj->query("armor_prop/fork")+";";

		if ( obj->query("armor_prop/club") )
			msg += "����="+obj->query("armor_prop/club")+";";

		if ( obj->query("armor_prop/throwing") )
			msg += "����="+obj->query("armor_prop/throwing")+";";

		if ( obj->query("armor_prop/hammer") )
			msg += "����="+obj->query("armor_prop/hammer")+";";

		if ( obj->query("armor_prop/taoism") )
			msg += "��ѧ�ķ�="+obj->query("armor_prop/taoism")+";";

		if ( obj->query("armor_prop/whip") )
			msg += "�޷�="+obj->query("armor_prop/whip")+";";

		if ( obj->query("armor_prop/strike") )
			msg += "�Ʒ�="+obj->query("armor_prop/strike")+";";

		if ( obj->query("armor_prop/finger") )
			msg += "ָ��="+obj->query("armor_prop/finger")+";";

		if ( obj->query("armor_prop/magic") )
			msg += "ħ������="+obj->query("armor_prop/magic")+";";

		if ( obj->query("armor_prop/spells") )
			msg += "��������="+obj->query("armor_prop/spells")+";";

		if ( obj->query("armor_prop/poison") )
			msg += "����="+obj->query("armor_prop/poison")+";";

		if ( obj->query("armor_prop/hand") )
			msg += "�ַ�="+obj->query("armor_prop/hand")+";";

		if ( obj->query("armor_prop/cuff") )
			msg += "ȭ��="+obj->query("armor_prop/cuff")+";";

		if ( obj->query("armor_prop/claw") )
			msg += "צ��="+obj->query("armor_prop/claw")+";";
	}

    return msg;
}

int resolve_data(object ob, string data, string type)
{
	string *get_data, get_kinded, my_type;
	int get_num, i;

	if ( !sscanf(data, "%*s;%*s") ) return 0;

	if ( type == MY_WEAPON_TYPE )
		my_type = "weapon_prop/";
	else if ( type == MY_ARMOR_TYPE )
		my_type = "armor_prop/";
	else
		return -1;

	get_data = explode(data, ";");
	for ( i=0; i<sizeof(get_data); i++ )
	{
		if ( sscanf(get_data[i],"%s=%d",get_kinded,get_num) == 2 )
			ob->set(my_type+get_kinded,get_num);
	}
	return 1;
}