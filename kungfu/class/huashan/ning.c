// ning.c ������
inherit NPC;
inherit F_MASTER;
int ask_book(string str);
void create()
{
    set_name("������", ({ "ning zhongze", "ning", "zhongze", "shiniang" }));
        set("long",   @LONG
�����ǻ�ɽ�ɵ����������ˡ��������ӽ�������Ⱥ�ķ��ˡ���Ϊ�˺Ͱ��� 
�ף����ܻ�ɽ���е��Ӿ�������Ȼ������ʮ��ͷ�ˣ�����ȴ�����ȴ档һ
����֪������ǰ�ض��Ǹ����ˡ� 
LONG );
        set("inquiry", ([
                "��ɽ����": (: ask_book :),
        ]) );
    set("gender", "Ů��");
    set("age", 38);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 20);
    set("int", 35);
    set("con", 30);
    set("per", 28);
    set("dex", 30);
    
    set("qi", 2200000);
    set("max_qi", 2200000);
    set("jing", 1600000);
    set("max_jing", 1060000);
    set("neili", 5000000);
    set("max_neili", 500000);
    set("jiali", 18230);
    set("combat_exp", 1060000);
    set("xyzx_sys/level", 1100);
    set_skill("force", 2220);
    set_skill("dodge", 2220);
    set_skill("parry", 2220);
    set_skill("sword", 2220);
    set_skill("unarmed", 2220);
    set_skill("blade", 2220);
    set_skill("zixia-shengong", 1220);
    set_skill("huashan-jianfa", 1220);
    set_skill("huashan-shenfa", 1220);
    set_skill("hunyuan-zhang", 1220);
    set_skill("poyu-quan", 1220);
    set_skill("fanliangyi-dao", 1220);
    set_skill("literate", 3220);
    map_skill("dodge", "huashan-shenfa");
    map_skill("force", "zixia-shengong");
    map_skill("parry", "huashan-jianfa");
    map_skill("sword", "huashan-jianfa");
    map_skill("unarmed", "poyu-quan");
    map_skill("blade", "fanliangyi-dao");

    create_family("��ɽ��", 13, "����");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "sword.jianzhang" :),
        (: perform_action, "sword.wushuang" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("//clone/cloth/pink_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
    if ((string)ob->query("gender") != "Ů��") {
        command("say ���¿�ʲô��Ц������ô�ܹ�������Ϊͽ�أ����������વġ�");
                command("say ��ֻ��Ů���ӣ��㻹��ȥ�����ɷ�ɡ�");
        return;
    }
    if ((int)ob->query("shen") < 0) {
        command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if ((int)ob->query_dex() < 20) {
        command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�һ�ɽ���书��");
        return;
    }
    command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
}
int ask_book(string arg)
{
        object me;
        object ning;
        object book;
        ning=this_object();
        me=this_player();
        if (me->query("class")!="swordsman")  
                {
                  command("say �Բ��𣬻�ɽ���ײ����Ը��㡣");
                  return 1;
                }
        else {
                if (ning->query_temp("sign"))  
                        {
                        command("say ������������ɽ�����类����������");
                        return 1;
                        }
                else {
                        message_vision(CYN "������΢Ц�Ŵӻ���ȡ����ɽ���ף����˸�$N \n" NOR,me);
                        book=new("/d/huashan/obj/sword-book");
                        book->move(me);
                        ning->set_temp("sign",1);
                        return 1;
                        }
                }
}
