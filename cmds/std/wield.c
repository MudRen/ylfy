
// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
   object ob, *inv;
   int i, count;

   if( !arg ) return notify_fail("你要装备什么武器？\n");
   if ( me->query_condition("no_equip") )		
        return notify_fail("你双手酸麻，暂时不能抓握穿戴装备。\n");

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
     return notify_fail("你身上没有这样东西。\n");

   if( ob->query("equipped") )
     return notify_fail("你已经装备着了。\n");
 
    if((int)me->query("str") < (int)ob->query("wield_str"))
		return notify_fail("你想举起"+ob->name()+"，怎奈力量不够，只好作罢。\n");

   return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
   string str;

    if( ob->query("weapon/id_name") && ob->query("weapon/id_name")!=getuid(me) )
	{
	    return notify_fail("别人的自练装备你怎么可能使用呢？？\n");//针对 对自练武器进行限制，不是自己的武器别人无法使用
	}
    if( !ob->query("xyzx_save_item") && ob->query("owner_id") && ob->query("owner_id") != getuid(me) )
	{
		destruct(ob);
		return notify_fail("下次别乱偷别人的东西。\n");
	}

   if( ob->wield() ) {
     if( !stringp(str = ob->query("wield_msg")) )
        str = "$N装备$n作武器。\n";
     message_vision(str, me, ob);
     return 1;
   } else
     return 0;
}

int help(object me)
{
   write(@HELP
指令格式：wield|zhuangbei <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP
    );
    return 1;
}
