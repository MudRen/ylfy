// mabudai.c �鲼��
inherit ITEM;
void create()
{
        set_name( RED "��  ��" NOR, ({ "red bag", "bag" }));
        set_weight(500);
        set_max_encumbrance(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һֻ����װ���ĺ����\n");
                set("value", 100);
        }
}
int is_container() { return 1; }


int query_autoload() { return 1; }