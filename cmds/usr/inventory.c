// /cmds/usr/inventory.c

#include <ansi.h>
#include <liebiao.h>
inherit F_CLEAN_UP;
object find_player(string target)
{
	int i;
	object *str;
	str=users();
	for (i=0; i<sizeof(str); i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string arg)
{
	int i,amount,w_p;
	object *inv, ob,obj;
	mapping my;
	string *str,col_p;
	if( wizardp(me) && arg )
	{
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}
	if( !ob ) ob = me;
	inv = all_inventory(ob);
	if( !sizeof(inv) )
	{
		write((ob==me)? HIW"Ŀǰ������û���κζ�����\n"NOR
		      : ob->name() + HIW"����û��Я���κζ�����\n"NOR);

		if(!me->query("xieyi/zmud"))
			write("" + CLEAN1);
		return 1;
	}
	obj=first_inventory(ob);
	arg="";
	if(!me->query("xieyi/zmud"))
		arg+=CLEAN1;
	while(obj)
	{
		reset_eval_cost();
		if (obj->query("equipped")  || obj->query("money_id"))
		{
			arg+=sprintf("%s%s \n",obj->query("equipped")? HIG "��" NOR:"  ",obj->short());
			if(!me->query("xieyi/zmud"))
				arg +=ADD1(obj);
			obj = next_inventory(obj);
			continue;
		}
		if (!mapp(my))
			my=([obj->query("unit")+obj->short():1]);
		else
		{
			amount=my[obj->query("unit")+obj->short()];
			my[obj->query("unit")+obj->short()]=amount+1;
		}
		if(!me->query("xieyi/zmud"))
			arg+=ADD1(obj);
		obj = next_inventory(obj);
	}
	if (mapp(my))
	{
		str=keys(my);
		for (i=0; i<sizeof(my); i++)
			arg+=sprintf("  %s%s\n",
			             my[str[i]]==1?"":CHINESE_D->chinese_number(my[str[i]]),
			             my[str[i]]==1?str[i][2..]:str[i]);
	}
	w_p = (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance();
	if (w_p < 30) col_p = HIB;
	else if(w_p < 70) col_p = HIY;
	else col_p = HIR;
	printf("\n%sĿǰЯ����" HIC+sizeof(all_inventory(ob)) +NOR"����Ʒ""(���� "+col_p+"%d%%"NOR")��\n"+"%s\n",(ob==me)? "��": ob->name(),w_p,arg);

	return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: inventory
 
���г���Ŀǰ������Я����������Ʒ�������ܸ��ء�
 
ע : ��ָ����� " i " ���档
 
HELP
);
        return 1;
}
