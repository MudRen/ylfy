// jianlun.c

inherit ITEM;

void create()
{
        set_name("����", ({ "sword book" ,"book"}));
        set_weight(600);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ������ǰ���������������������һЩģ����ͼ���ƺ�\n"
                        "�ǻ���һЩ������С���Ρ�\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                        "name":               "sword",     
                       "exp_required":  100,                                                                                                          "jing_cost":   20,                             
                        "difficulty":   25,                                                                                                                "max_skill":   60,  ]));                                                                                
        }
}

