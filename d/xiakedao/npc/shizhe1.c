// shizhe1.c

inherit NPC;

void create()
{
        set_name("����", ({ "waiter","zhe"}) );
        set("gender", "����" );
        set("age", 14);
        set("long", "һ�����Ż��µĺ��ӡ�\n");
        set("shen_type", 1);
        set("combat_exp", 300000);
        set("str", 200);
        set("dex", 25);
        set("con", 20);
        set("int", 250);
   
        create_family("���͵�", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}


