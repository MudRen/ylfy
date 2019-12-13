// hong.c ���߹�
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
    set("nickname", HIW "��ָ��ؤ" NOR);
    set("gender", "����");
    set("age", 75);
    set("long", 
        "������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
    set("attitude", "peaceful");
    
    set("str", 100);
    set("int", 84);
    set("con", 60);
    set("dex", 184);
   
	set("xyzx_sys/level", 1500);
    set("qi", 2000000);
    set("max_qi", 2000000);
    set("neili", 6000000);
    set("max_neili", 500000);
    set("jing", 1500000);
    set("max_jing", 1500000);
    set("jiali", 13000);
    set("combat_exp", 30000000+random(70000000));	
    set_temp("apply/damage",500);
     
    set_skill("force", 2800);
    set_skill("huntian-qigong",1800);
    set_skill("unarmed", 2850);
    set_skill("xianglong-zhang", 1850);
    set_skill("dodge", 1900);
    set_skill("xiaoyaoyou", 1950);
    set_skill("parry", 2900);
    set_skill("club", 2850);
    set_skill("dagou-bang", 1850);
    set_skill("begging", 1500);
    set_skill("checking", 1420);          // ����;˵
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    map_skill("parry", "xianglong-zhang");
    map_skill("club", "dagou-bang");
    
    create_family("ؤ��", 17, "����");
	 set("chat_chance", 1);
    set("chat_msg", ({
        "���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
        "���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
        "���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
    }));
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
         (: command("unwield yuzhu zhang") :),
    }) );
    set("inquiry", ([
        "������" : "����������������\n",
        "ؤ��" : "����������������\n",
        "��ʦ" : "�����ȥ���������Ұ��ܶ��³�нţ�����Ϊʦ��\n",
    ]));
    set("chat_chance_combat", 100);  	
    set("chat_msg_combat", ({	
(: perform_action, "unarmed.jingtian" :),	
(: perform_action, "club.chan" :),	
(: perform_action, "club.lian" :),	
}));	
    setup();
    
    carry_object(__DIR__"yuzhu_zhang")->wield();
    carry_object("//clone/cloth/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query_str() < 20 || (int)ob->query_con() < 25) {
        command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
        return;
    }
    if (mapp(ob->query("family")) &&
        (string)ob->query("family/family_name") != "ؤ��") {
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
        return;
    }
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
    
}
int accept_object(object who, object ob)
{
    object ob_yzz, me = this_object();
    if (ob->query("food_supply") <= 0)
        return 0;
    if ((string)ob->query("name") != "�л���") {
        command("say �Ͻл���" + (string)ob->query("name") + "ûʲô��Ȥ����");
        return 0;
    }
    if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
        command("say �Ͻл����ڱ��úܡ�");
        return 0;
    }
    command("say ����������������ԵĽл���ѽ��");
    command("eat ji");
    command("say �벻����СС��ͣ���˼ȴ��ϸ���͸�������ض�һ����");
    if ((string)ob->query("family/family_name") != "" &&
        (string)ob->query("family/family_name") != "ؤ��") {
        command("say " + RANK_D->query_respect(ob) + "�㻹���������ʲô��");
        return 1;
    }
    if( ob_yzz = present("yuzhu_zhang", me) )
    {
        ob_yzz->move(who);
        write("������ȸ����Ҷ����ˣ����͸�����������ɡ�");
        return 1;
    }
    else
    {
        write("���������ò���ʱ���������Ѿ��������ˡ�");
        return 1;
    }
    return 1;
}
