// yangpi.c ��Ƥ
inherit ITEM;

void create()
{
        set_name("��Ƥ", ({"yang pi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ƥ�Ƴɵĺ�ͼ������̻���һЩ��˹���֡�\n");
                set("unit", "��");
                set("value", 100);
        }
}

int query_autoload() { return 1; }