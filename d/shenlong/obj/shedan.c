inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name("���ߵ�", ({"dan"}));
        set("unit", "ö");
    set("long", "����һö���ĸ��ߵ���\n");
    set("value", 500);
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
    message_vision(RED"$N������,����ææһ�ڰ�"+this_object()->name()+RED+"����!\n" NOR,this_player());
    this_player()->unconcious();
    return 1;
}
int query_autoload() { return 1; }