// jiuyang2.c

inherit ITEM;

void create()
{
          set_name("�����ؼ�", ({ "jiuyang miji" ,"miji"}));
        set_weight(600);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ����Ƥֽ�Ĳо�������һЩ��µ��־䣬�ƺ�\n"
                        "�ᵽһЩ��������ʲ��ġ�ֽ������ԼԼ��д�˸�����\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                 "name":   "jiuyang-force",  // name of the skill
               "exp_required": 10000,     // minimum combat experience                                      // required to learn this skill.
               "jing_cost": 35,           // gin cost every time study this
               "difficulty":   40,        // the base int to learn this skill
                                 // modify is gin_cost's (difficulty - int)*5%
               "max_skill":    101,       // the maximum level you can learn
                                          // from this object.
                ]) );
        }
}

