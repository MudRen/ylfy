// feng.c ������
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
    set("nickname", "������ʦ");
    set("long", "�����ǻ�ɽ���ڵĳ��Ϸ����������ݳ���ü���һֱ������һ�ɵ���������\n"
                "��ɫ����Ȼ�Ե���Ľ�������֮��һֱ����������\n");
    set("gender", "����");
    set("age", 68);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 60);
    set("int", 80);
    set("con", 80);
    set("dex", 230); 
	set("xyzx_sys/level", 2000);
	
    set("qi", 4158000);
    set("max_qi", 4158000);
    set("jing", 1560000);
    set("max_jing", 1560000);
    set("neili", 3000000);
    set("max_neili", 600000);
    set("jiali", 13000);
    set("combat_exp", 11059200);
    set_skill("force", 2400);
    set_skill("blade", 2400);
    set_skill("dodge", 2480);
    set_skill("parry", 2400);
    set_skill("sword", 2400);
    set_skill("unarmed", 2400);
    set_skill("zixia-shengong", 1450);
    set_skill("poyu-quan", 1470);
    set_skill("fanliangyi-dao", 1480);
    set_skill("huashan-jianfa", 1400);
    set_skill("hunyuan-zhang", 2470);
    set_skill("dugu-jiujian", 3550);	
    set_skill("huashan-shenfa",1460);
    set_skill("literate", 1200);
    map_skill("force", "zixia-shengong");
    map_skill("dodge", "huashan-shenfa");
    map_skill("parry", "dugu-jiujian");
    map_skill("sword", "dugu-jiujian");
    map_skill("blade", "fanliangyi-dao");
    map_skill("unarmed", "hunyuan-zhang");
    create_family("��ɽ��", 12, "����");
set("chat_chance_combat", 100);	
    set("chat_msg_combat", ({
(: perform_action, "sword.dugu" :),	
        (: perform_action, "sword.poqi" :),
        (: perform_action, "sword.pozhang" :),
        (: perform_action, "sword.pojian" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/clone/cloth/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
    if (mapp(ob->query("family"))  &&   (string)ob->query("family/family_name") != "��ɽ��")
    {
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������������أ�");
        return;
    }
    if (((int)ob->query_skill("sword",1) < 150) || ((int)ob->query_skill("huashan-jianfa",1) < 150))
    {
        command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ļ�ɽ������ûѧ���Ұɡ�");
        return;
    }
    if (((int)ob->query_skill("force",1) < 150) || ((int)ob->query_skill("zixia-shengong",1) < 130))
    {
        command("say �ҿ�" + RANK_D->query_respect(ob) + "����ϼ�񹦻�ûѧ���Ұɡ�");
        return;
    }
    if (((int)ob->query_skill("dodge",1) < 150) || ((int)ob->query_skill("huashan-shenfa",1) < 150))
    {
        command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ļ�ɽ����ûѧ���Ұɡ�");
        return;
    }
    if ( (int)ob->query_skill("literate",1) < 160)
    {
        command("say �ҿ�" + RANK_D->query_respect(ob) + "�Ķ���ʶ�ֻ�ûѧ���Ұɡ�");
        return;
    }
    if ((int)ob->query("shen") < 100000)
    {
        command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if ((int)ob->query_int() < 41) {
        command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�Ҷ��¾Ž���");
        return;
    }
    command("say �ðɣ��Ҿ��������ˡ�");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
}
