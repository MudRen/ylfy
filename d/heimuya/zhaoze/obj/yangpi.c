// yangpi.c 羊皮
inherit ITEM;

void create()
{
        set_name("羊皮", ({"yang pi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一卷羊皮制成的海图，上面刻画着一些波斯文字。\n");
                set("unit", "个");
                set("value", 100);
        }
}

int query_autoload() { return 1; }