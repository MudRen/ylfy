// book4.c
inherit ITEM;

void create()
{
    set_name("ʯ��", ({ "stone", "shu", "book" }));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
            "                   �׽ȭ��ƪ\n\n"
            "����һ��԰԰��ʯ�壬�ƺ�����ָ�̻�������ָӡ��\n");
        set("value", 500);
        set("material", "stone");
        set("no_sell",1);
        set("skill", ([
            "name": "unarmed",  // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    10, // jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    49  // the maximum level you can learn
        ]) );
    }
}
int query_autoload() { return 1; }
