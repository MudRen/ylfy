// player
// ��ǿһЩ efun ����ӦһЩ����ϵͳ��Ҫ By Wenwu On 2006.7.18

object find_player( string str )
{
	object ob, *usrs;
	int i;

	if ( ob = efun::find_player(str) )
		return ob;

	usrs = children(USER_OB);
	for (i = 0; i < sizeof(usrs); i++)
	{
		if ( usrs[i]->query("id") == str )
		{
			if ( environment(usrs[i]) )
			{
				ob = usrs[i];
				return ob;
			}
		}
	}

	return 0;
}

int userp( object ob )
{
	if ( efun::userp(ob) )
		return 1;
	
	return ob->is_player();
}

int query_ip_port( object ob )
{
	int port;
	
	if ( port = efun::query_ip_port(ob) )
		return port;

	if ( userp(ob) )
		return __PORT__;
}

object *get_all_user()
{
	object *all_user, *all_users;
	int i;

	all_user = efun::users();
	all_users = children(USER_OB);
	for (i = 0; i < sizeof(all_users); i++)
	{
		if ( !interactive(all_users[i]) && clonep(all_users[i]) )
			all_user += ({ all_users[i] });
	}

	return all_user;
}

int playerp(object ob)
{
	return ob->is_player();
}