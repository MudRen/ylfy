

#define MY_WEAPON_TYPE "兵器"
#define MY_ARMOR_TYPE "防具"
#define GRANT_WIZ_LEVEL 8

#include <liebiao.h>
#include <item.h>

inherit F_CLEAN_UP;
inherit F_COLOR;

#include <item_sx.h>

mapping weapon_skill_type = ([
"sword"   :  "剑法",
"blade"   :  "刀法",
"axe"     :  "斧法",
"club"    :  "棍法",
"dagger"  :  "矛法",
"fork"    :  "叉法",
"hammer"  :  "锤法",
"staff"   :  "杖法",
"whip"    :  "鞭法",
"spear"   :  "枪法",
"unarmed" :  "拳套",
"throwing":  "暗器"
]);

mapping armor_type = ([
"cloth"   :  "衣服",
"armor"   :  "铠甲",
"boots"   :  "靴子",
"finger"  :  "戒指",
"hands"   :  "护手",
"head"    :  "帽子",
"neck"    :  "项链",
"shield"  :  "盾牌",
"surcoat" :  "披风",
"waist"   :  "腰带",
"wrists"  :  "护腕",
"pants"   :  "裤子"
]);

mapping wear_type = ([
"cloth"   :  "身体",
"armor"   :  "身体",
"boots"   :  "脚部",
"finger"  :  "手指",
"hands"   :  "手部",
"head"    :  "头部",
"neck"    :  "颈项",
"shield"  :  "左手",
"surcoat" :  "背部",
"waist"   :  "腰部",
"wrists"  :  "腕部",
"pants"   :  "腿上"
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
	
	msg = "物件="+arg+";";
	
	if ( !sscanf(id, "%s %s", id1, id2) )
	{
		new_id = id; // 不是特殊处理时的，传入的 id 就是 new_id
		v = 0;
	}
	else
	{
		id_list = explode(id , " ");
		if ( !stringp(num = id_list[sizeof(id_list)-1]) ) return 0; // 未知的类型，则直接退出
		
		if ( !(v = atoi(num)) ) new_id = id; // 不符合特殊处理的格式，则认为 new_id 还是原来的 id
		else new_id = replace_string(id, " "+v, ""); // 是特殊处理的格式，我们重新获得正确的 id(new_id)
	}
	// 我们把传入的常规格式命令看作是指向首位置的特殊格式命令
	if ( !v )
		v = 1;
	
	switch ( win )
	{
		// 同环境下菜单
		case 0 :
				// 检查 me 是否有环境，没有则直接返回
				if ( !objectp(room = environment(me)) )
						return 1;
				// 通过遍历来查找这个 ob
				inv = all_inventory(room);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// 我们首先验证 ob 的真实 id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						if ( m == v )
						{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
						}
						else
							continue; // 如并不在指定的位置上，则继续查找下一个位置
					}
					// 验证伪装后的 id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// 找到了伪装了的 ob 的 id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
							}
							else
								continue; // 如并不在指定的位置上，则继续查找下一个位置
						}
					}
				}
				break;
		
		case 1 :
				// 检查 me 是否有效存在，没有则直接返回
				if ( !objectp(me) )
						return 1;
				// 通过遍历来查找这个 ob
				inv = all_inventory(me);
				for ( i = 0; i < sizeof(inv); i++ )
				{
					if ( inv[i] == me )
						continue;
					// 我们首先验证 ob 的真实 id
					if ( inv[i]->query("id") == new_id )
					{
						m++;
						if ( m == v )
						{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
						}
						else
							continue; // 如并不在指定的位置上，则继续查找下一个位置
					}
					// 验证伪装后的 id
					if ( ids = inv[i]->query_temp("apply/id") )
					{
						if ( !arrayp(ids) )
							continue;
						// 找到了伪装了的 ob 的 id
						if ( ids[0] == new_id )
						{
							m++;
							if ( m == v )
							{
								ob = inv[i]; // 找到并在指定的位置上，那么我们需要的 ob 就是这个了
								break;
							}
							else
								continue; // 如并不在指定的位置上，则继续查找下一个位置
						}
					}
				}
				break;
	}
	
	if ( !objectp(ob) ) 
	{
		write(LOOK("提示=Err:操作数错误，无法显示物品资料。;"));
		return 1; 
	}

	if ( is_set )
	{
		//ob->set_name(is_name, ({is_id}));
		is_right = resolve_data(ob, is_data, is_type);
		
		if ( !is_right )
			cue = "提示=修改失败，服务器无法正确解析数据包;";
		else if ( is_right == -1 )
			cue = "提示=修改失败，目前只支持修改装备属性;";
		else
			cue = "提示=修改成功;";
	}

	msg += "权限="+wiz_level(me)+";";

	if ( ob->is_corpse() ) 
	{
		msg += "装备类型=尸体;";
		msg += "中文名="+ob->query("name")+";英文名="+ob->query("id")+";";
		msg += "描述="+ob->long()+";";
		if ( !is_allow )
			cue = "提示=由于这个界面是专门针对装备系统做的，所以非装备物件只能简单显示中、英文名及描述。如因此造成您的不便只能说声抱歉了，有时间的话会慢慢完善的。;";
	}
	else if ( ob->is_character() )
	{
		if ( playerp(ob) ) 
			msg += "装备类型=玩家;";
		else
			msg += "装备类型=NPC;";
		msg += "中文名="+ob->query("name")+";英文名="+ob->query("id")+";";
		msg += "描述="+ob->long()+";";
		if ( !is_allow )
			cue = "提示=由于这个界面是专门针对装备系统做的，所以非装备物件只能简单显示中、英文名及描述。如因此造成您的不便只能说声抱歉了，有时间的话会慢慢完善的。;";
	}
	else
	{
		if ( mapp(ob->query("weapon_prop")) || mapp(ob->query("armor_prop")) )
		{
			msg += look_item(me, ob);
		}
		else
		{
			msg += "装备类型=普通物品;";
			msg += "中文名="+ob->query("name")+";英文名="+ob->query("id")+";";
			msg += "描述="+ob->long()+";";
			if ( !is_allow )
				cue = "提示=由于这个界面是专门针对装备系统做的，所以非装备物件只能简单显示中、英文名及描述。如因此造成您的不便只能说声抱歉了，有时间的话会慢慢完善的。;";
		}
	}

	if ( is_allow && !is_set )
		cue = "提示=修改失败，您的权限不够，服务器拒绝进行该项操作;";

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
	msg = "中文名="+obj->query("name")+";英文名="+obj->query("id")+";";
	//------------------------------------------------------
	//开光魔法戒指描述特殊处理
	if ( obj->query("old_copy_log") && obj->query("diablo/only_me") != me->query("id") )
		msg += "描述="+obj->query("old_copy_log")+";";
	else
		msg += "描述="+obj->long()+";";

	// 属性显示
	// 兵器
	if ( obj->query("weapon_prop") )
	{
		msg += "装备类型="+MY_WEAPON_TYPE+";";
		v_num = 0;
		for (i = 0; i < sizeof(weapon_shuxing); i++)
		{
			if ( obj->query("weapon_prop/" + keys(weapon_shuxing)[i]) )
				v_num++;
		}
		msg += "品阶="+v_num+";";
		msg += "等级="+obj->query("weapon_prop/level")+";";

		if ( obj->query("flag") & 1 )
		{
			msg += "使用类型=双手;";
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
			msg += "使用类型=单手;";
			if ( !stringp(obj->query("pic_name")) )
			{
				if ( obj->query("skill_type") == "sword" )
					obj->set("pic_name", ""+(random(WEAPON_SWORD_PIC_NUM_ODD)));
				if ( obj->query("skill_type") == "blade" )
					obj->set("pic_name", ""+(random(WEAPON_BLADE_PIC_NUM_ODD)));
			}
		}
		msg += "item_type="+obj->query("skill_type")+";pic_name="+obj->query("pic_name")+";";

		msg += "应用类型="+weapon_skill_type[obj->query("skill_type")]+";";

		if ( obj->query("weapon_prop/damage") )
			msg += "物攻="+obj->query("weapon_prop/damage")+";";

		if ( obj->query("weapon_prop/strength") )
			msg += "臂力="+obj->query("weapon_prop/strength")+";";

		if ( obj->query("weapon_prop/intelligence") )
			msg += "悟性="+obj->query("weapon_prop/intelligence")+";";

		if ( obj->query("weapon_prop/constitution") )
			msg += "根骨="+obj->query("weapon_prop/constitution")+";";

		if ( obj->query("weapon_prop/dexerity") )
			msg += "身法="+obj->query("weapon_prop/dexerity")+";";

		if ( obj->query("weapon_prop/karma") )
			msg += "福缘="+obj->query("weapon_prop/karma")+";";

		if ( obj->query("weapon_prop/personality") )
			msg += "容貌="+obj->query("weapon_prop/personality")+";";

		if ( obj->query("weapon_prop/dodge") )
			msg += "轻功="+obj->query("weapon_prop/dodge")+";";

		if ( obj->query("weapon_prop/unarmed") )
			msg += "拳脚="+obj->query("weapon_prop/unarmed")+";";

		if ( obj->query("weapon_prop/force") )
			msg += "t内功="+obj->query("weapon_prop/force")+";";

		if ( obj->query("weapon_prop/parry") )
			msg += "招架="+obj->query("weapon_prop/parry")+";";

		if ( obj->query("weapon_prop/sword") )
			msg += "剑法="+obj->query("weapon_prop/sword")+";";

		if ( obj->query("weapon_prop/blade") )
			msg += "刀法="+obj->query("weapon_prop/blade")+";";

		if ( obj->query("weapon_prop/axe") )
			msg += "斧法="+obj->query("weapon_prop/axe")+";";

		if ( obj->query("weapon_prop/stick") )
			msg += "棒法="+obj->query("weapon_prop/stick")+";";

		if ( obj->query("weapon_prop/staff") )
			msg +="杖法="+obj->query("weapon_prop/staff")+";";

		if ( obj->query("weapon_prop/spear") )
			msg+="枪法="+obj->query("weapon_prop/spear")+";";

		if ( obj->query("weapon_prop/fork") )
			msg+="叉法="+obj->query("weapon_prop/fork")+";";

		if ( obj->query("weapon_prop/club") )
			msg+="棍法="+obj->query("weapon_prop/club")+";";

		if ( obj->query("weapon_prop/throwing") )
			msg+="暗器="+obj->query("weapon_prop/throwing")+";";

		if ( obj->query("weapon_prop/hammer") )
			msg +="锤法="+obj->query("weapon_prop/hammer")+";";

		if ( obj->query("weapon_prop/taoism") )
			msg+="道学心法="+obj->query("weapon_prop/taoism")+";";

		if ( obj->query("weapon_prop/whip") )
			msg+="鞭法="+obj->query("weapon_prop/whip")+";";

		if ( obj->query("weapon_prop/strike") )
			msg+="掌法="+obj->query("weapon_prop/strike")+";";

		if ( obj->query("weapon_prop/finger") )
			msg+="指法="+obj->query("weapon_prop/finger")+";";

		if ( obj->query("weapon_prop/magic") )
			msg+="魔法咒文="+obj->query("weapon_prop/magic")+";";

		if ( obj->query("weapon_prop/spells") )
			msg+="基本法术="+obj->query("weapon_prop/spells")+";";

		if ( obj->query("weapon_prop/poison") )
			msg+="毒功="+obj->query("weapon_prop/poison")+";";

		if ( obj->query("weapon_prop/hand") )
			msg+="手法="+obj->query("weapon_prop/hand")+";";

		if ( obj->query("weapon_prop/cuff") )
			msg+="拳法="+obj->query("weapon_prop/cuff")+";";

		if ( obj->query("weapon_prop/claw") )
			msg+="爪法="+obj->query("weapon_prop/claw")+";";
	}
	else if ( obj->query("armor_prop") ) // 防具
	{
		msg += "装备类型="+MY_ARMOR_TYPE+";";
		v_num = 0;
		for (i = 0; i < sizeof(armor_shuxing); i++)
		{
			if ( obj->query("armor_prop/" + keys(armor_shuxing)[i]) )
				v_num++;
		}
		msg += "品阶="+v_num+";";
		msg += "等级="+obj->query("armor_prop/level")+";";

		if ( obj->query("armor_type") )
		{
			msg += "使用类型="+armor_type[obj->query("armor_type")]+";";
			msg += "应用类型="+wear_type[obj->query("armor_type")]+";";
		}

		if ( obj->query("armor_prop/armor") )
			msg += "物防="+obj->query("armor_prop/armor")+";";

		if ( obj->query("armor_prop/strength") )
			msg += "臂力="+obj->query("armor_prop/strength")+";";

		if ( obj->query("armor_prop/intelligence") )
			msg += "悟性="+obj->query("armor_prop/intelligence")+";";

		if ( obj->query("armor_prop/constitution") )
			msg += "根骨="+obj->query("armor_prop/constitution")+";";

		if ( obj->query("armor_prop/dexerity") )
			msg += "身法="+obj->query("armor_prop/dexerity")+";";

		if ( obj->query("armor_prop/karma") )
			msg += "福缘="+obj->query("armor_prop/karma")+";";

		if ( obj->query("armor_prop/personality") )
			msg += "容貌="+obj->query("armor_prop/personality")+";";

		if ( obj->query("armor_prop/armor_vs_force") )
			msg += "真气护体="+YEL+obj->query("armor_prop/armor_vs_force")+";";

		if ( obj->query("armor_prop/dodge") )
			msg += "轻功="+obj->query("armor_prop/dodge")+";";

		if ( obj->query("armor_prop/unarmed") )
			msg += "拳脚="+obj->query("armor_prop/unarmed")+";";

		if ( obj->query("armor_prop/force") )
			msg += "内功="+obj->query("armor_prop/force")+";";

		if ( obj->query("armor_prop/parry") )
			msg += "招架="+obj->query("armor_prop/parry")+";";

		if ( obj->query("armor_prop/sword") )
			msg += "剑法="+obj->query("armor_prop/sword")+";";

		if ( obj->query("armor_prop/blade") )
			msg += "刀法="+obj->query("armor_prop/blade")+";";

		if ( obj->query("armor_prop/axe") )
			msg += "斧法="+obj->query("armor_prop/axe")+";";

		if ( obj->query("armor_prop/stick") )
			msg += "棒法="+obj->query("armor_prop/stick")+";";

		if ( obj->query("armor_prop/staff") )
			msg += "杖法="+obj->query("armor_prop/staff")+";";

		if ( obj->query("armor_prop/spear") )
			msg += "枪法="+obj->query("armor_prop/spear")+";";

		if ( obj->query("armor_prop/fork") )
			msg += "叉法="+obj->query("armor_prop/fork")+";";

		if ( obj->query("armor_prop/club") )
			msg += "棍法="+obj->query("armor_prop/club")+";";

		if ( obj->query("armor_prop/throwing") )
			msg += "暗器="+obj->query("armor_prop/throwing")+";";

		if ( obj->query("armor_prop/hammer") )
			msg += "锤法="+obj->query("armor_prop/hammer")+";";

		if ( obj->query("armor_prop/taoism") )
			msg += "道学心法="+obj->query("armor_prop/taoism")+";";

		if ( obj->query("armor_prop/whip") )
			msg += "鞭法="+obj->query("armor_prop/whip")+";";

		if ( obj->query("armor_prop/strike") )
			msg += "掌法="+obj->query("armor_prop/strike")+";";

		if ( obj->query("armor_prop/finger") )
			msg += "指法="+obj->query("armor_prop/finger")+";";

		if ( obj->query("armor_prop/magic") )
			msg += "魔法咒文="+obj->query("armor_prop/magic")+";";

		if ( obj->query("armor_prop/spells") )
			msg += "基本法术="+obj->query("armor_prop/spells")+";";

		if ( obj->query("armor_prop/poison") )
			msg += "毒功="+obj->query("armor_prop/poison")+";";

		if ( obj->query("armor_prop/hand") )
			msg += "手法="+obj->query("armor_prop/hand")+";";

		if ( obj->query("armor_prop/cuff") )
			msg += "拳法="+obj->query("armor_prop/cuff")+";";

		if ( obj->query("armor_prop/claw") )
			msg += "爪法="+obj->query("armor_prop/claw")+";";
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