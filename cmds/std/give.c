// give.c

inherit F_CLEAN_UP;
int do_give(object me, object obj, object who,int amount);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	string target, item,str;
	object obj, who, *inv, obj2;
	int i, amount;
	if(!arg) return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");
	if( sscanf(arg, "%s to %s", str, target)==2 || sscanf(arg, "%s %s", target, str)==2 );
	else return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");
	if(!objectp(who = present(target, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if (who==me) return notify_fail("���Լ������������⣬����û�ã�\n");
    if(me->is_busy())
        return notify_fail("�����Ƚ������ϵ������������ٸ���!\n");
         
    if( !who->is_character() || who->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

    if (!living(who)) 
		return notify_fail("��!����Ȼ,"+who->name()+"����������,�������������������������!\n");
	if (who->query("env/no_accept")) 
		return notify_fail(who->query("name")+"���ڲ�������ܱ��˵�������\n");
// if (objectp(obj=present("thousand-gold",me))&&query_ip_name(me)==query_ip_name(who)&&str=="thousand-gold")      	
// return notify_fail("���뽫��Ʊ�����ˣ��������������е��᲻��!��\n");            	
	if(sscanf(str, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
			
if( ( obj->query("no_give") || obj->query("no_drop") ) && !wizardp(me) )                                   	
//   if( obj->query("no_give") && obj->query("no_drop") && !wizardp(me) )                                        	
			return notify_fail("�����������������ˡ�\n");
//   if (query_ip_name(me)==query_ip_name(who)&&obj->query("id")=="thousand-gold")           	
//   return notify_fail("�ٺ٣������ʲô?��\n");    	
		if( amount < 1 )	return notify_fail("����������������һ����\n");
		if(obj->query_amount() ){
			if( amount > obj->query_amount() ) return notify_fail("��û��������" + obj->name() + "��\n");
			else if( amount == (int)obj->query_amount() )	return do_give(me, obj, who,1);
			else {
				
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (!do_give(me, obj2, who,1)){
					obj->add_amount(amount );
					return 1;
				}return 1;
			}
		}		
                else return do_give(me, obj, who,amount);
	}
	if(sscanf(str, "all %s",item)==1) {
			
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
         
		return do_give(me, obj, who,1000);
	}
	
	 
	 if(str=="all") {
	 	/*if(objectp(obj = present("thousand-gold",me)) && query_ip_name(me)==query_ip_name(who))
	{write("�ۣ� ����Ʊһ������ǲ��Ǹ���ˣ�!\n");
	 return 1;}*/
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who,1);
		}
		write("Ok.\n");
		return 1;
	}
	if( !objectp(obj = present(str, me)) )
		return notify_fail("������û������������\n");
	return do_give(me, obj, who,1);
}
int do_give(object me, object obj, object who,int amount)
{
	string arg,str;
	int i=1;
    if( obj->query("no_drop") && (!wizardp(me)) && interactive(who)) 	
		return notify_fail("�����������������ˡ�\n");
//   if( who->query("id",1) != "zhu danchen" && obj->query("no_give") && (!wizardp(me)) )                            	
    if(userp(who) && obj->query("no_give") && (!wizardp(me)) )                            	
        return notify_fail("�����������������ˡ�\n");   

//temp���ã���ʦ���ܸ���Ҷ���
    if(userp(who) && !wizardp(who) && wizardp(me) && wizhood(me) != "(boss)")
	    return notify_fail("��ʦ���������˶�����\n");
    if ( playerp(me) && me->query_condition("killer") )
		return notify_fail("��Ŀǰ����ͨ���ţ��Ҹ��˶���С�����°ѱ���\n");

	arg=obj->query("id");
	str=obj->query("unit")+obj->name();
	if( !interactive(who) && !who->accept_object(me, obj) )
	if (QUEST->quest_give (me, who, obj)) {
                     message_vision("$N��$nһ"+obj->query("unit")+obj->name()+"��\n",me,who);
                        message_vision("$N���Ե���$n��л��\n",who,me);
                        destruct(obj);
                        return 1;
                } else
		return notify_fail("��ֻ�ܰѶ����͸�������Ҳ��ݵ����\n");
	    
	if (obj){
		for (i=0;i<amount;i++){
			if (!userp(who) && !who->query("accept"))	
				destruct(obj);
			else if(! obj->move(who)) { return obj->move(who);}
			if( !objectp(obj = present(arg, me)) ){i++;break;}
		}
		
	}
	message_vision(sprintf("$N��$n%s%s��\n",CHINESE_D->chinese_number(i),str),me,who);
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}
