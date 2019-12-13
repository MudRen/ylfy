// updated.c

#include <liebiao.h>

object creat_weapon(object me);

void create()
{
	seteuid(getuid());
}

varargs void check_user(object ob, int gx)
{
	object weapon, marry_ring, thousand_gold, m_jiayi;
	mapping my;
	string name, id, or, type, time;
	int value, lv;
	
	//temp
	ob->delete("chblk_rumor");
	ob->delete("chblk_chat");
	ob->delete("chblk_shout");
	ob->delete("chblk_es");
	
	thousand_gold=present("thousand-gold",ob);
	
	if (thousand_gold)
	{
		if (thousand_gold->query_amount()>100)
			thousand_gold->set_amount(100);
	}
	
	if(ob->query("neili") > ob->query("max_neili")*2)
		ob->set("neili",ob->query("max_neili")*2);
	
	if (ob->is_ghost() && !wizardp(ob))
	{
		ob->set("jing", 1);
		ob->set("neili", 0);
		ob->set("jingli", 0);
		ob->set("eff_jing", 1);
		ob->set("qi", 1);
		ob->set("eff_qi", 1);
	}
	
	my = ob->query_entire_dbase();
	
	if( !pointerp(my["channels"]) )
		my["channels"]=({ "xyxw" });
	else if( member_array("xyxw", my["channels"])==-1 )
		my["channels"]+=({ "xyxw" });
	
	if(!wizardp(ob))
		ob->set("channels", ({ "chat","jypm","es","xyxw","rumor","new","jh","xy"}) );
	
	if (my["more_money"]>5000)
	{
		my["more_money"]=5000;//����Ǯׯ��Ǯ����Ϊ5000��
		my["money"]=0;
	}

	if ( playerp(ob) )
	{
		if ( gx && gx == 3 )
		{
			auto_restore_item(ob);
			ob->remove_save_item();
			//________________________�����������____________________
			ob->set_temp("last_ip_name", query_ip_name(ob));
			ob->set_temp("last_ip_number", query_ip_number(ob));

			if ( ob->query("env/myhp_show") )
				tell_object(ob, CHECK(ob->query("id")));
			//__________________________ End __________________________
		}
	}

	if ( !ob->query_temp("my_make_item") && ob->query("jia/make"))
	{
		if (!present("my jia",ob))
		{
			m_jiayi=new("/d/npc/m_weapon/npc/jia");
			m_jiayi->move(ob);
		}
	}
	
	if (!wizardp(ob))
		ob->delete("env/invisibility");
	
	if( (ob->query("weapon/make")==1) )
	{
		name = ob->query("weapon/name");
		id = ob->query("weapon/id");
		or = ob->query("weapon/or");
		type=ob->query("weapon/type");
		time=ob->query("weapon/time");
		value=ob->query("weapon/value");
		lv = ob->query("weapon/lv");
		ob->delete("weapon");
		ob->set("weapon/make",1);
		ob->set("weapon/name",name);
		ob->set("weapon/id",id);
		ob->set("weapon/or",or);
		ob->set("weapon/type",type);
		ob->set("weapon/value",value);
		ob->set("weapon/lv",lv);
		ob->set("weapon/id_name", ob->query("id")); //����idʶ�𣬷�ֹ���˵��� 2015.10
		ob->set("weapon/time",time);
	}
	else
		ob->delete("weapon");
		
	if ( !ob->query_temp("my_make_item") && !ob->over_encumbranced())
	{
		if ( stringp(id = ob->query("weapon/id")) )
		{
			if (!present(id,ob))
			{
				weapon = creat_weapon(ob);
				weapon->move(ob);
				//weapon->wield(); //��ʱȡ�����������������Զ�wield
			}
		}
		if ( stringp(id != ob->query("weapon/id")) )
		{
			if (!present(id,ob))
			{			
				destruct(weapon); //�жϣ�ÿ��������������в����Լ������������ʹݻ�
			}
		}		
		if ( ob->query("couple/have_couple") && !present("marry ring",ob) )
		{
			marry_ring= new("/clone/misc/marry_ring");
			marry_ring->move(ob);
			marry_ring->wear();
		}
	}
		
	if ( wizardp(ob) )
	{
		if ( !ob->query("env/show_wiz_msg") )
			ob->set("env/block_wiz_msg", 1);
		return;
	}
		
	if( undefinedp(my["eff_jing"]) )
		my["eff_jing"] = my["max_jing"];
		
	if( undefinedp(my["eff_qi"]) )
		my["eff_qi"] = my["max_qi"];
		
	if( my["eff_jing"] > my["max_jing"] )
		my["eff_jing"] = my["max_jing"];
		
	if( my["eff_qi"] > my["max_qi"] )
		my["eff_qi"] = my["max_qi"];
		
	if( my["jing"] > my["eff_jing"] )
		my["jing"] = my["eff_jing"];
		
	if( my["qi"] > my["eff_qi"] )
		my["qi"] = my["eff_qi"];
		
	if ( userp(ob) && ( (my["int"]+my["dex"]+my["con"]+my["str"]) > 80 ) )
		log_file("cheat_users",sprintf("%s(%s) int=%d,str=%d,con=%d,dex=%d \n",my["name"],my["id"],my["int"],my["str"],my["con"],my["dex"]));
}
		
object creat_weapon(object me)
{
	object weapon;
	string mask;//the verible that record the type of weapon
			
	mask = me->query("weapon/type");
			
	switch(mask)
	{
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
				
		if (me->query("max_neili")<1000)
		{
			weapon->set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
			weapon->set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
		}
		else if (me->query("max_neili")<10000)
		{
			weapon->set("wield_msg", HIY "$N��ৡ���һ�����$n"+HIY+"���˸�������������â���£������Ƿɡ� \n" NOR);
			weapon->set("unwield_msg", HIY "$N��ৡ��ذ�$n"+HIY+"��ؽ��ʡ�\n" NOR);
		}
		else
		{
			weapon->set("wield_msg", HIW "$N����������ֻ��һ����â������$N������������Ϣ�ض���һ��$n"+HIW+"��\n" NOR);
			weapon->set("unwield_msg", HIW "$n"+HIW+"��$N���з����ڰ����һת����ৡ���Ծ�뽣�ʡ�\n" NOR);
		}
				
		return weapon;
				
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
		return weapon;
				
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
		return weapon;
		
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
		return weapon;
		
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
		return weapon;
	}
	return 0;
}
