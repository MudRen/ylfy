// bye enter

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("����Һ", ({"wuliangye", "wu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һƿ�ոմ򿪵�����Һ�������˱ǣ����˴������ߡ�\n");
                set("unit", "ƿ");
                set("value", 100);
                set("max_liquid", 15);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": "����Һ",
                "remaining": 15,
                "drunk_apply": 3,
        ]));
}
int query_autoload() { return 1; }
