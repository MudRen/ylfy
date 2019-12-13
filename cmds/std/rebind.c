// rebind.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string equip, topic;
        object ob, target;
        seteuid(getuid());
        if( !arg || sscanf(arg, "%s to %s", equip, topic)!=2 )
                return notify_fail("你要解绑赠送什么东西？\n");
        if( !objectp(target = present(topic, environment(me))) )
                return notify_fail("这里没有这个人。\n");
        if( !objectp(ob = present(equip, me)) )
                return notify_fail("你身上没有这样东西。\n");
        if ( me->is_busy() ) 
                return notify_fail("你上一个动作还没有完成。\n");
        if (!playerp(target) )
                return notify_fail("对方不是人。\n");
        if (target==me) 
                return notify_fail("解绑赠送给自己没有意义。\n");
        if (sizeof(all_inventory(target)) > 50) 
                return notify_fail("对方身上的东西已经太多了。\n");
        if ( !ob->query("xyzx_sys/bind_type") )
                return notify_fail("这样东西不需要解绑赠送。\n");
        //if ( ob->query("xyzx_item/pinji") == 3)
                //return notify_fail("会员武器不能解绑。\n");
		if ( !ob->query("armor_prop/armor") && !ob->query("weapon_prop/damage") )
		    return notify_fail(HIR"你只能解绑赠送武器或者防具!笨蛋!!。\n");		
        if ( ob->query("equipped") )
                return notify_fail("穿在身上或者拿在手上的装备无法解绑赠送。\n");
        if( (int)target->query_encumbrance() + (int)ob->weight() > (int)target->query_max_encumbrance() )
                return notify_fail("对方拿不动这么重的东西。\n");
        if (me->query("more_money") < 1)  
                return notify_fail("解绑赠送需要一万两黄金，你没这么多存款。\n");

        me->add("more_money", -1);

        ob->delete("bind_master_level");
        ob->move(target);
        
        message("channel:chat", HIY"\n【奇珍异宝】"+HIM"："+me->query("name")+"将绝世异宝"+ob->query("name")+HIM"赠送给"+target->query("name")+"。\n"NOR,users());


        return 1;
}
int help(object me)
{
   write( @HELP
指令格式: rebind 装备 to 玩家
将绑定装备赠送给其他玩家，每次消耗一万两黄金存款。
HELP
   );
   return 1;
}

