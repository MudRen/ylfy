inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("������", ({"hua", "wuming"}));
        set("unit", "��");
        set("long", "����һ������С��,������С,ȴʮ��������\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
    message_vision(BOLD "$N����һ��"+this_object()->name()+"��Ȼ��ֻ��һ������ֱ���ķ�...\n" NOR, this_player());
    this_player()->add("max_neili",4);
    this_player()->add("kar",11);
    this_player()->unconcious();
       this_object()->move(VOID_OB);
    destruct(this_object());
    return 1;
}
int query_autoload() { return 1; }
