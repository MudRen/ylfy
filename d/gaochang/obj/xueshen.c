//xueshen.c
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "use");
}
void create()
{
        set_name(HIW "ѩ��" NOR, ({ "xue shen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����С���㣬ѩ�׵�ǧ��ѩ�Σ���˵���ƻ𶾡�\n");
                set("value", 2000);
        }
        setup();
}
int do_eat(string arg)
{
        object me = this_player();
        if (!arg|| !this_object()->id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->query_condition("fire_poison")){
                message_vision( "$N����һ��ǧ��ѩ�Σ��پ�����һ�ɺ�����ӿ���������˸���ս��\n" , me);
                me->apply_condition("fire_poison",0);
                destruct(this_object());
                return 1;
        }
        if ((int)this_player()->query("eff_qi") >= 
            (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ��ǧ��ѩ�Ρ�\n");

         me->add("qi",30);
         me->add("eff_qi",20);
        message_vision( "$N����һ��ǧ��ѩ�Σ��پ�����һ�ɺ�����ӿ���������˸���ս��������ú���Щ��\n" , me);
        destruct(this_object());
        return 1;
}
int query_autoload() { return 1; }
