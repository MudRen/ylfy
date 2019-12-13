#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_miao","miao");
        add_action("do_wakeup","xin");
        add_action("do_shoot","shoot");
}

void create()
{
        set_name(HIY BLK"AK47"NOR, ({ "AK 47", "ak","47", "gun" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("bullet", 1000);
                set("value", 50000);
                set("material", "steel");
                set("long", "�ػ�������ǹ������\n");
                set("wield_msg", "$N����һ��"HIY BLK"AK47"NOR"�����꡹һ�����ӵ������š�\n");
                set("unwield_msg", "$N�������"HIY BLK"AK47"NOR"����������\n");
        }
        init_blade(100);
        setup();
}

int do_miao(string arg)
{
        object me, obj;
        
        me = this_player();

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if( this_object()->query("bullet") <=0)
                return notify_fail("���ӵ��Ѿ�����ˡ�\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj == me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

        message_vision(HIY "\n$N����"BLK"AK47"HIY"��ԶԶ����׼$n�����š��ˡ���һ�������ӵ�ѹ�����š�\n\n" NOR, 
                        me, obj);

        this_object()->set_temp("target", arg);

        return 1;
}

int do_wakeup (string str)
{
        object who;

        if (!str) return notify_fail ("[MYST]: wakeup error, wakeup <someone>\n");

        if (!(who = present(lower_case(str), environment(this_player()))) )
                return notify_fail ("[MYST]: wakeup error, û��" + str + "\n"); 
        who->remove_call_out("revive");
        who->revive();
        who->reincarnate();
        return 1;
}

int do_shoot()
{
        object me, obj;
        string arg;

        me = this_player();

        if( !(arg = this_object()->query_temp("target")) ) 
                return notify_fail("�㻹û����׼������Ŀ�꣡\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("��Ҫ����Ķ����Ѿ��뿪�ˡ�\n");

        message_vision(HIR "\n$N��׼$n�۶��˰��������\nֻ���������һ����죬$n�ҽ�һ�����������͵���Ѫ���\n\n" NOR,
                        me, obj);

        this_object()->add("bullet", -1);
        obj->unconcious();

        return 1;
}


