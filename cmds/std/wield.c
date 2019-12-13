
// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
   object ob, *inv;
   int i, count;

   if( !arg ) return notify_fail("��Ҫװ��ʲô������\n");
   if ( me->query_condition("no_equip") )		
        return notify_fail("��˫�����飬��ʱ����ץ�մ���װ����\n");

   if(arg=="all") {
     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
        if( inv[i]->query("equipped") ) continue;
		if((int)me->query("str") < (int)inv[i]->query("wield_str")) continue;
        if(do_wield(me, inv[i]) ) count ++;
     }
     write("Ok.\n");
     return 1;
   }
   
   if( !objectp(ob = present(arg, me)) )
     return notify_fail("������û������������\n");

   if( ob->query("equipped") )
     return notify_fail("���Ѿ�װ�����ˡ�\n");
 
    if((int)me->query("str") < (int)ob->query("wield_str"))
		return notify_fail("�������"+ob->name()+"����������������ֻ�����ա�\n");

   return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
   string str;

    if( ob->query("weapon/id_name") && ob->query("weapon/id_name")!=getuid(me) )
	{
	    return notify_fail("���˵�����װ������ô����ʹ���أ���\n");//��� �����������������ƣ������Լ������������޷�ʹ��
	}
    if( !ob->query("xyzx_save_item") && ob->query("owner_id") && ob->query("owner_id") != getuid(me) )
	{
		destruct(ob);
		return notify_fail("�´α���͵���˵Ķ�����\n");
	}

   if( ob->wield() ) {
     if( !stringp(str = ob->query("wield_msg")) )
        str = "$Nװ��$n��������\n";
     message_vision(str, me, ob);
     return 1;
   } else
     return 0;
}

int help(object me)
{
   write(@HELP
ָ���ʽ��wield|zhuangbei <װ������>
 
���ָ������װ��ĳ����Ʒ������, �����Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}