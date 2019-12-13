// ��̬���ݲ��� by Wenwu

mapping actions;

// �浵
nomask varargs void auto_save_item(object ob, int sb)
{
	string file_arg, ob_arg;
	mixed *file;
	object *inv;
	int i;

	ob_arg = "";
	inv = all_inventory(ob);

	if ( !stringp(ob->query("id")) ) return;
	if ( !environment(ob) ) return;
	if ( !playerp(ob) ) return;
	if ( ob->query_temp("no_auto_items")) return;

	file_arg = DATA_DIR + "item/" + ob->query("id") + "/";

	if ( file_size(file_arg) != -2 )
		mkdir(DATA_DIR + "item/" + ob->query("id"));

	file = get_dir(file_arg, -1);

	// ɾ���ϴεĵ���
	if ( sizeof(file) )
	{
		for (i = 0; i < sizeof(file); i++)
		{
			if ( file_size(file_arg + file[i][0]) != -1 )
				rm(file_arg + file[i][0]);
		}
	}

	if ( sizeof(inv) < 1 )
	{
		rmdir(DATA_DIR + "item/" + ob->query("id"));
		return;
	}

	// �浵
	for (i = 0; i < sizeof(inv); i++)
	{
		if( inv[i]->query("xyzx_ylfy_buy_sell") )
			continue;

		if ( inv[i]->query("xyzx_save_item") && inv[i]->query("owner_id") )
		{
			ob_arg += base_name(inv[i]) + ":" + i + "\n";

			if( inv[i]->query("equipped"))
			{
				inv[i]->set_temp("save_temp_remove", 1);

				if( !inv[i]->unequip() )
					log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(inv[i])));
			}

			inv[i]->save(file_arg + i);

			if ( sb && inv[i]->query_temp("save_temp_remove") )
			{
				inv[i]->delete_temp("save_temp_remove");

				if ( inv[i]->query("weapon_prop") )
					inv[i]->wield();
				else if ( inv[i]->query("armor_prop") )
					inv[i]->wear();
			}
		}
	}

	if ( ob_arg != "" )
		write_file(file_arg + "wupin", ob_arg, 1);
	else
		rmdir(DATA_DIR + "item/" + ob->query("id"));

	return;
}

// ȡ��
nomask void auto_restore_item(object ob)
{
	string file_arg, ob_arg, *file_list, *ob_list;
	mixed *file;
	object obj;
	int i;

	if ( !stringp(ob->query("id")) ) return;
	if ( !environment(ob) ) return;
	if ( !playerp(ob) ) return;

	file_arg = DATA_DIR + "item/" + ob->query("id") + "/";

	if ( file_size(file_arg) != -2 )
		return;
	if ( file_size(file_arg + "wupin") == -1 )
		return;

	file = get_dir(file_arg, -1);
	
	if ( sizeof(file) < 2 )
		return;

	ob_arg = read_file(file_arg + "wupin");
	file_list = explode(ob_arg, "\n");
	for (i = 0; i < sizeof(file_list); i++)
	{
		if ( strsrch(file_list[i], ":") != -1 )
		{
			ob_list = explode(file_list[i], ":");

			if( sscanf(ob_list[0], "/d/npc/m_weapon/%*s") )
				ob->set_temp("my_make_item", 1);

			obj = new(ob_list[0]);
			obj->restore(file_arg + ob_list[1]);
			//�����ID��ʧ����
        if(!obj->parse_command_id_list() || sizeof(obj->parse_command_id_list())==0)
            obj->set_name(obj->query("name"), ({obj->query("id")}));
        else
        obj->set_name(obj->query("name"), obj->parse_command_id_list());
			actions = WEAPON_D->query_action_xyzx(obj);
			obj->set("actions", actions);
			obj->move(ob);
		}
	}

	return;
}

// ɾ��
nomask void delete_item_data(object ob)
{
	string file_arg, id;
	mixed *file;
	int i;

	if ( !stringp(id = ob->query("id")) ) return;
	if ( !playerp(ob) ) return;

	file_arg = DATA_DIR + "item/" + id + "/";

	if ( file_size(file_arg) != -2 ) return;

	file = get_dir(file_arg, -1);

	// ɾ���ϴεĵ���
	if ( sizeof(file) )
	{
		for (i = 0; i < sizeof(file); i++)
		{
			if ( file_size(file_arg + file[i][0]) != -1 )
				rm(file_arg + file[i][0]);
		}
	}

	rmdir(DATA_DIR + "item/" + id);
}
