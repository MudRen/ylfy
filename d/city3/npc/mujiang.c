//bye enter

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("��ľ��", ({ "zhang mujiang", "mujiang" }));
        set("str", 20);
        set("gender", "����");
        set("age", 43);
        set("long", "���Ǹ����ո߳���ľ������˵����Ϊ�������¡�\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");
        set("inquiry", ([
                "name": "С�����ţ��ڳɶ�Ҳ��һ���������ˡ�",
                "ľ��": "˵��ľ����ǿ��Ǵ�����о��ĳɹ�Ŷ��",
                "������": "��....�Ұ���������뱲�ӣ�����.......",
           ]));
//        set("vendor_goods", ({
//                "/d/chengdu/npc/obj/mu-ren",
//        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

//void init()
//{
//        add_action("do_list", "list");
//        add_action("do_buy", "buy");
//}

