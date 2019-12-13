// box.c 功德箱

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT"募捐箱"NOR, ({ "mujuan xiang", "xiang", "box" }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个常见的纸糊的募捐箱，专门用来接受大款的捐款。\n");
                set("value", 1000);
                set("material", "paper");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();
}

int is_container() { return 1; }

void init()
{
        add_action("do_put", "put");
}

int do_put(string arg)
{
        object me, obj;
        string item, target; 
        int amount;

        me = this_player();

        if(!arg) return notify_fail("你要将什么东西放进哪里？\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 
        ||  sscanf(item, "%d %s", amount, item)!=2
        ||  !objectp(obj = present(item, me)) )

        return notify_fail("你要给谁什么东西？\n");

        if( obj->query("money_id") == "silver" 
        &&  obj->query_amount() >= 5 && amount >= 5 ) 
        {
                if( me->query("begger") > 0) {
                        message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                                obj->query("unit"), obj->name(), 
                                this_object()->name()),me );
                        obj->set_amount(obj->query_amount() - amount);;
                        me->add("begger", (-1)*(amount/5));
                        if( me->query("begger") < 0) me->set("begger", 0);
                        this_object()->add("amount", amount);
                        return 1;
                }
        }

        return 0;
}

