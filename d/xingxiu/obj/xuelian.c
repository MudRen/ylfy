// medicine: xuelian.c
// Jay 3/18/96
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("��ɽѩ��", ({"xuelian", "lian", "lotus"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һֻ֧���ں���ĵط�����������ѩ����\n");
                set("value", 100);
        }
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
    this_player()->set("eff_qi", this_player()->query("max_qi"));
    this_player()->set("eff_jing", this_player()->query("max_jing"));
        message_vision("$N����һ��ѩ��,�پ������ٱ�!\n", this_player());
    destruct(this_object());
    return 1;
}

int query_autoload() { return 1; }