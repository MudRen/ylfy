// equip.c
// �޸�֧�ֶ�̬ By Wenwu On 2006.7.17

#include <dbase.h>
#include <weapon.h>

inherit F_SAVE;

void suit_temp(object owner)
{
      mapping applied_prop=([]);
      mapping sum_eff=([]);  //��װЧ��
      mapping suit_eff=([]);
      string *apply;
   //��װ���Ը���ʵ��-------------------------------------------------------------------------------
         //�˴��츳
        if(mapp(suit_eff=owner->suit(owner,"suit_eff"))) 
           {
              applied_prop=([]);
              sum_eff=owner->sum_eff(owner,suit_eff);
              apply=keys(sum_eff);
              for(int i = 0; i<sizeof(apply); i++)
		if( undefinedp(applied_prop[apply[i]]) )  //���applied_prop���޷��ҵ�apply[i]
			applied_prop[apply[i]] = sum_eff[apply[i]];   //�򽫷���Ч����ӽ�applied_prop��
		else
			applied_prop[apply[i]] += sum_eff[apply[i]];  //���ҵ����ͺϲ�����
           }
           owner->set_temp("suit_eff",applied_prop);
           //���Ӽ���
           if(mapp(suit_eff=owner->suit(owner,"suit_skill"))) 
           {
              applied_prop=([]);
              sum_eff=owner->sum_eff(owner,suit_eff);
              apply=keys(sum_eff);
              for(int i = 0; i<sizeof(apply); i++)
		if( undefinedp(applied_prop[apply[i]]) )  //���applied_prop���޷��ҵ�apply[i]
			applied_prop[apply[i]] = sum_eff[apply[i]];   //�򽫷���Ч����ӽ�applied_prop��
		else
			applied_prop[apply[i]] += sum_eff[apply[i]];  //���ҵ����ͺϲ�����
           }
           owner->set_temp("suit_skill",applied_prop);
}

int wear()
{
	mixed item_ob;
	object owner;
	mapping armor_prop, applied_prop, default_armor_prop, is_bind;
	string *apply, type;
	int sx_add;
	
	// Only character object can wear armors.
	if( !owner = environment())
		return 0;
	if( !owner->is_character() )
		return 0;
	// If already worn, just recognize it.
	if( query("equipped") )
		return 1;
	// Check if we have "armor_prop" defined.
	if( mapp(armor_prop = query("weapon_prop")) )
		return notify_fail(this_object()->name()+"�����������ǻ��ߣ���ֻ�ܴ����ɵ������ߵĶ�����\n");
	if( !mapp(armor_prop = query("armor_prop")) )
		return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");
	
	type = query("armor_type");
	
	if( owner->query_temp("armor/" + type) )
		return notify_fail("���Ѿ�������ͬ���͵Ļ����ˡ�\n");
	// ����ճ�һ�ֲ���װ������
	if ( type == "shield" 
		&& owner->query_temp("secondary_weapon") )
		return notify_fail("�����ճ�һֻ����װ�����ơ�\n");
	// �󶨵�װ�������޷�װ����
	if ( mapp(is_bind=query("bind_master_level")) 
		&& !is_bind[owner->query("id")] )
		return notify_fail("���Ǳ��˵�˽�з������޷�װ���ϡ�\n");
	
	owner->set_temp("armor/" + type, this_object());

	// ��̬֧���������
	//-------------------------------------------------------------------
	if ( item_ob = this_object()->query_default_object() )
	{
		default_armor_prop = item_ob->query("armor_prop");
		armor_prop = maps_compose(armor_prop, default_armor_prop);
	}
	//-------------------------------------------------------------------

	apply = keys(armor_prop);
	applied_prop = owner->query_temp("apply");
	
	if( !mapp(applied_prop) )
		applied_prop = ([]);
	
	for(int i = 0; i<sizeof(apply); i++)
	{

	   switch (query("xyzx_item/pinji"))  // װ��Ʒ��
	   {
		case 5:sx_add = armor_prop[apply[i]]*70/100; break;
		case 4:sx_add = armor_prop[apply[i]]*50/100; break;
		case 3:sx_add = armor_prop[apply[i]]*30/100; break;
		case 2:sx_add = armor_prop[apply[i]]*20/100; break;
		case 1:sx_add = armor_prop[apply[i]]*10/100; break;
		default:sx_add = 0;
	   }

        //write(HIY"������ֵ��"+sx_add+" ��Դ��"+armor_prop[apply[i]]+"��\n"NOR);

		if( undefinedp(applied_prop[apply[i]]) )
			applied_prop[apply[i]] = armor_prop[apply[i]] + sx_add;
		else
			applied_prop[apply[i]] += (armor_prop[apply[i]] + sx_add);
	}
	
	owner->set_temp("apply", applied_prop);
        //��װ���Ը��ӵ���
        //---------------------------------
           suit_temp(owner);
        //---------------------------------
	set("equipped", "worn");
	// װ����
	if ( query("xyzx_sys/bind_type") && playerp(owner) )
	{
		set("bind_master_level/"+owner->query("id"), 2);
		set("owner_id", 1);
		set("xyzx_save_item", 1);
	}
	
	return 1;
}

int wield()
{
	mixed item_ob;
	object owner, old_weapon;
	mapping weapon_prop, default_weapon_prop, is_bind;
	string *apply;
	int flag, sx_add;
	
	// Only character object can wear armors.
	if( !owner = environment())
		return 0;
	if( !owner->is_character() )
		return 0;
	// If already wielded, just recognize it.
	if( query("equipped") )
		return 1;
	// Check if we have "weapon_prop" defined.
	if( !mapp(weapon_prop = query("weapon_prop")) )
		return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");
	// �󶨵�װ�������޷�װ����
	if ( mapp(is_bind=query("bind_master_level")) 
		&& !is_bind[owner->query("id")] )
		return notify_fail("���Ǳ��˵�˽���������޷�װ���ϡ�\n");
	
	flag = query("flag");
	
	// ˫��������־ 1:����˫�ֲ���װ��,2:���Բ�ͬ��װ��
    if( flag & TWO_HANDED )
	{
		if( owner->query_temp("weapon")
			||  owner->query_temp("secondary_weapon")
			||  owner->query_temp("armor/shield") )
			return notify_fail("�����ճ�˫�ֲ���װ��˫��������\n");
		
		owner->set_temp("weapon", this_object());
		owner->set_temp("secondary_weapon",this_object());
	}
	else
	{
		// If we are are using any weapon?
		if( !(old_weapon = owner->query_temp("weapon")) )
			owner->set_temp("weapon", this_object());
		// If we still have a free hand? 
		else if( !owner->query_temp("secondary_weapon") 
			&& !owner->query_temp("armor/shield") )
		{
			// If we can wield this as secondary weapon?
            if(flag & SECONDARY)
			{
				owner->set_temp("secondary_weapon", this_object());
			}
			// If we can switch our old weapon to secondary weapon ?
			else if( (int)old_weapon->query("flag") & SECONDARY )
			{
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();
			}
			// We need unwield our old weapon before we can use this one.
			else
				return notify_fail("������ȷ�����Ŀǰװ����������\n");
		}
		// We have both hands wearing something.
		else
			return notify_fail("�����ճ�һֻ����ʹ��������\n");
	}

	// ��̬֧���������
	//------------------------------------------------------------------
	if ( item_ob = this_object()->query_default_object() )
	{
		default_weapon_prop = item_ob->query("weapon_prop");
		weapon_prop = maps_compose(weapon_prop, default_weapon_prop);
	}
	//------------------------------------------------------------------
	
	apply = keys(weapon_prop);
	for(int i = 0; i<sizeof(apply); i++)
	{
		switch (query("xyzx_item/pinji")) // װ��Ʒ��
	   {
		case 5:sx_add = weapon_prop[apply[i]]*70/100; break;
		case 4:sx_add = weapon_prop[apply[i]]*50/100; break;
		case 3:sx_add = weapon_prop[apply[i]]*30/100; break;
		case 2:sx_add = weapon_prop[apply[i]]*20/100; break;
		case 1:sx_add = weapon_prop[apply[i]]*10/100; break;
		default:sx_add = 0;
	   }
		owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]] + sx_add);
	}
	
	owner->reset_action();
        //��װ���Ը��ӵ���
        //---------------------------------
           suit_temp(owner);
        //---------------------------------
	set("equipped", "wielded");
	// װ����
	if ( query("xyzx_sys/bind_type") && playerp(owner) )
	{
		set("bind_master_level/"+owner->query("id"), 2);
		set("owner_id", 1);
		set("xyzx_save_item", 1);
	}
    
	return 1;
}

int unequip()
{
	mixed item_ob;
	object owner,s_weapon;
	mapping prop, applied_prop, default_weapon_prop, default_armor_prop;
	string *apply, equipped;
	int sx_add;
	
	if( !(owner = environment())->is_character() )
		return 0;
	if( !stringp(equipped = query("equipped")) )
		return notify_fail("��Ŀǰ��û��װ������������\n");
	
	if( equipped=="wielded" )
	{
		if( (object)owner->query_temp("weapon") == this_object() )
		{
			owner->delete_temp("weapon");
			if( (object)owner->query_temp("secondary_weapon") == this_object() )
				owner->delete_temp("secondary_weapon");
			if (objectp(s_weapon=owner->query_temp("secondary_weapon")))
			{
				s_weapon->unequip();
				s_weapon->wield();
			}
		}
		else if( (object)owner->query_temp("secondary_weapon") == this_object() )
			owner->delete_temp("secondary_weapon");
		
		prop = query("weapon_prop");

		// ��̬֧���������
		//---------------------------------------------------------------------
		if (item_ob = this_object()->query_default_object() )
		{
			default_weapon_prop = item_ob->query("weapon_prop");
			prop = maps_compose(prop, default_weapon_prop);
		}
		//---------------------------------------------------------------------

		owner->reset_action();
	}
	else if( equipped=="worn" )
	{
		owner->delete_temp("armor/" + query("armor_type") );
		prop = query("armor_prop");

		// ��̬֧���������
		//-------------------------------------------------------------------
		if ( item_ob = this_object()->query_default_object() )
		{
			default_armor_prop = item_ob->query("armor_prop");
			prop = maps_compose(prop, default_armor_prop);
		}
		//-------------------------------------------------------------------
	}
	
	apply = keys(prop);
	applied_prop = owner->query_temp("apply");
	
	for(int i = 0; i<sizeof(apply); i++)
	{	
	switch (query("xyzx_item/pinji"))  // װ��Ʒ��
	   {
		case 5:sx_add = prop[apply[i]]*70/100; break;
		case 4:sx_add = prop[apply[i]]*50/100; break;
		case 3:sx_add = prop[apply[i]]*30/100; break;
		case 2:sx_add = prop[apply[i]]*20/100; break;
		case 1:sx_add = prop[apply[i]]*10/100; break;
		default:sx_add = 0;
	   }
		// To support array apply, we cannot add_temp() here.
		applied_prop[apply[i]] -= (prop[apply[i]] + sx_add);
	}
	 //��װ���Ը��ӵ���
        //---------------------------------
           suit_temp(owner);
        //---------------------------------

	delete("equipped");
    
    return 1;
}