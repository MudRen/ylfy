// huolong-bian.c

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIR "��" NOR HIY "��" NOR HIB "��" NOR, ({ "huolong bian", "bian" }) );
        set_weight(150000);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ɻ������ѩ��˿�ʳɵĳ��ޣ��ѱ�Ϊǧ�꺮����Զ��ɡ�\n");
                set("material", "leather");
                set("wield_msg", HIY "����к�Ȼ����������Խ�������ͼ���Ĺ�Х֮��............\n"
HIC "һ" HIR "��" HIC "һ" HIW"��" HIC "���������໥��Ť����أ����$N������,һ����������������һ�����ޡ�\n" NOR);
                set("unwield_msg", HIC "һ������֮������$N���е�$n" HIC "��Ȼ�����ˡ�\n" NOR);
        }
    set("no_get",1);
    set("no_drop",1);
    set("rigidity",1000);
    init_whip(1000,2);
    setup();
}
void init()
{
     if (this_player()!=environment()) return;
     add_action("do_hui","hui");
}
int do_hui(string weapon)
{   
    object me;
    me=this_player();
    if( !weapon || weapon!="huolong bian")
        return notify_fail("��Ҫ�ݻ�ʲô?\n");
    message_vision(HIR "����һ����һ����ޣ�һ���͵�һ�������ž��һ������"
            +this_object()->name()+HIR+"��Ϊ����!\n" NOR,me);
    me->save();
    destruct( this_object() );
    return 1;
}
//string query_autoload() { return query("name"); }
void autoload(string param) { }

int hit_ob(object me,object victim,int damage_bonus)
{
    victim->apply_condition("fire_poison", 200);
    victim->apply_condition("xuecan_poison", 200);
    victim->start_busy(1);
    return damage_bonus;
}

void owner_is_killed() { destruct(this_object()); }
int query_autoload() { return 1; }	
