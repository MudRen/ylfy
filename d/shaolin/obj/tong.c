// tong.c  ��ˮͰ
inherit ITEM;
inherit F_LIQUID;
void create()
{
    set_name("��ˮͰ", ({"shuitong", "tong"}));
    set_weight(80000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ������װˮ�Ĵ�ˮͰ������ʯͷ�Ƴɵģ����������ǿյġ�\n");
        set("unit", "��");
        set("value", 0);
        set("max_liquid", 15);
    }
}
