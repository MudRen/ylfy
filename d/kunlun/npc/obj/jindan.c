// by mei
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("����ߵ�", ({"jin dan", "dan"}));
        set("unit", "��");
        set("long", "����һ�ź춬���Ľ���ߵ���\n");
        set("value", 100);
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
    this_player()->set("eff_qi", this_player()->query("max_qi"));
    this_player()->set("eff_jing", this_player()->query("max_jing"));
        message_vision("$N����һ�Ž���ߵ�,�پ������ٱ�!\n", this_player());
    destruct(this_object());
    return 1;
}
int query_autoload() { return 1; }