// daodejing.c
inherit ITEM;
void create()
{
set_name( "̫��ȭ��",({
 "shu","book"}));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
set("long","����һ��̫��ȭ�ס�\n");
        set("value", 500);
        set("no_sell",1);
        set("material", "paper");
        set("skill", ([
  "name": "taiji-quan",  //name of the skill
 "exp_required": 10000 , //minimum combat experience required
            "jing_cost": 20+random(20),// jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    100 // the maximum level you can learn
        ]) );
    }
}
int query_autoload() { return 1; }