// baiyunwan.c �����ܵ���
inherit ITEM;
void setup()
{}
void init()
{
    add_action("do_eat", "eat");
}
void create()
{
    set_name("�����ܵ���", ({"baiyunxiudan wan", "wan"}));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ��������ʿ�������������ʥҩ��\n");
        set("value", 50000);
    }
    setup();
}
int do_eat(string arg)
{
    if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
    this_player()->set("qi",(int)this_player()->query("max_qi"));
    this_player()->set("jing",(int)this_player()->query("max_jing"));
    message_vision("$N����һ�Ű����ܵ��裬ֻ��������������ɫ��á�\n", this_player());
    if (this_player()->query_condition("ss_poison")){
        this_player()->apply_condition("ss_poison",0);
        tell_object(this_player(),"���е������������ܽ��ˡ�\n");
    }
    destruct(this_object());
    return 1;
    
}
int query_autoload() { return 1; }