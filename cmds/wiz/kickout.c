
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
void create() 
{
	seteuid(getuid());
    set("channel_id", "����ָ��(Kick)");
}
object find_player(string target)
{
	int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string arg)
{
	int i;
	object ob;
        object *inv;
                        
    if (!arg) return 0;                    
	ob=find_player(arg);
	if(!ob || !userp(ob)) return 0;
	if( !wizardp(ob) ) {
		inv = all_inventory(ob);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(ob, inv[i]);
	}
        write("��ӭ�´�������\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                ob->name() + "(" + ob->query("id") + ")�뿪��Ϸ�ˡ�");
 
	ob->save();
	destruct(ob);
	return 1;
}
