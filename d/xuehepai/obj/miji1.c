//longmenmiji.c

inherit ITEM;

void create()
{
        set_name("�����ؼ�", ({ "longmen miji", "miji","shu","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"������д��:�����ؼ���\n");
                set("value", 100);
                 set("no_drop",1);
                set("no_sell",1);
                set("no_give",1);
                set("material", "paper");
                set("skill", ([
                        "name":         "longmen-shengong",      // name of the skill
                        "exp_required": 100000,         // minimum combat experience required
                                                        // to learn this skill.
                        "jingli_cost":  50,             // jing cost every time study this
                        "difficulty":   32,             // the base int to learn this skill
                                                        // modify is jing_cost's (difficulty - int)*5%
                        "max_skill":    31,             // the maximum level you can learn
                ]) );
        }
}
