// medicine: hanyu.c
// by mei 
inherit ITEM;
void setup()
{}
void create()
{
        set_name(HIG "����" NOR, ({ "han yu", "yu" }));
        set_weight(100000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ֻ���ڼ�����ĵط����ܳ��ɵġ�ͨ�徧Ө���̵�ǧ��"+HIG+"����"+NOR+"��\n");
                set("value", 1000000);
        }
        setup();
}
int move(mixed dest, int silently)
{
    if (objectp(dest)){
        if (userp(dest))
         dest->apply_condition("xuecan_poison", 100);
    }
    return ::move(dest,silently);
}

int query_autoload() { return 1; }