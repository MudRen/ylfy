// sword_book.c
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC "华山剑谱" NOR, ({ "sword book", "book" }));
    set_weight(600);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "本");
        set("long","封面上写著「华山剑法 -- 卷二（进阶）」\n");
        set("value", 0);
        set("material", "paper");
        set("skill", ([
            "name":         "huashan-jianfa",        // name of the skill
            "exp_required": 10000,          // minimum combat experience required
                                            // to learn this skill.
            "jing_cost":        20,             // jing cost every time study this
            "difficulty":   20,             // the base int to learn this skill
                                            // modify is jing_cost's (difficulty - int)*5%
            "max_skill":    50             // the maximum level you can learn
                                            // from this object.
        ]) );
    }
}
int query_autoload() { return 1; }