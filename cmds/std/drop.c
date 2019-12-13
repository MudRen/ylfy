
// drop.c
//sophos
//	add busy state checking for 1 sec at critical code

 
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if(!arg) return notify_fail("��Ҫ����ʲ�ᶫ����\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û��������" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			//add busy checking here.   - sophos
			if( me->is_busy() )
				return notify_fail("����һ��������û����ɣ�\n");
			me->start_busy(1);
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;

	if( !wizardp(me) && no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
	
	if( file_name(environment(me)) == "/d/city/wumiao" || file_name(environment(me)) == "/d/wizard/fightroom2" )
		return notify_fail("����Ҳ��������Ӷ�����");
	if ( playerp(me) && me->query_condition("killer") )
		return notify_fail("��Ŀǰ����ͨ���ţ����ǲ�Ҫ��������Ϊ�á�\n");

	if (obj->move(environment(me))) {
		if( obj->is_character() )
			message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
		else {

            if ( wizardp(me) && wizhood(me) != "(boss)" ) {
                write(HIG"һֻ��ɫС����ܿ���ܳ�������ס�㶪�µĶ�����Ȼ����ʧ�����ˣ�����\n"NOR);
                destruct(obj); 
                return 1;
            }  
			message_vision( sprintf("$N����һ%s$n��\n",	obj->query("unit")),
				me, obj );
			if (obj->id("illicit salt"))	me->delete_temp("illicit");
		if( !obj->query("value") && !obj->value() ) {
					if (obj->id("biao yin"))
						write("��Ϊ��������ֵ̫Ǯ�����Ժܿ����ǾͰ������Ϸ��ˡ�\n");
					else
						write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
					destruct(obj);
				}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : drop <��Ʒ����>
 
���ָ��������㶪������Я������Ʒ.
 
HELP
    );
    return 1;
}
 
