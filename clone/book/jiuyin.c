inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("九阴真经", ({ "jiuyin zhenjing","zhenjing", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
             set("long",
        "这是一本用薄绢写成的书。上书：“九阴真经”。\n"
        "书皮泛黄，看来已经保存很久了。\n",
        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "jiuyin-zhenjing",
        "exp_required":100000,
                        "jing_cost":  40,
                        "difficulty": 20,
                        "max_skill":  2000
                ]) );
        }
}
int query_autoload() { return 1; }      