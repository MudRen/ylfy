// laodenuo.c 
inherit NPC;
void create()
{
    set_name("�͵�ŵ", ({ "lao denuo", "lao", "denuo" }));
    set("nickname", "�Ϻ���");
    set("long", "�͵�ŵ��İ��֣������⣬����Ц���еģ�����\n"
"ͬ�������еڶ����ǻ�ɽ������һ����Ψһ����Ͷʦ�ġ�\n");
    set("gender", "����");
    set("age", 54);
    set("attitude", "peaceful");
    set("shen", -1000);
    set("str", 18);
    set("int", 25);
    set("con", 20);
    set("dex", 20);
    
    set("max_qi", 1200);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 20);
    set("combat_exp", 90000);

    set_skill("force", 60);
    set_skill("zixia-shengong", 60);
    set_skill("dodge", 60);
    set_skill("parry", 70);
    set_skill("sword", 80);
    set_skill("unarmed", 80);
    set_skill("hunyuan-zhang", 80);
    set_skill("huashan-jianfa", 80);
    set_skill("huashan-shenfa", 60);
    set_skill("poyu-quan", 60);
    map_skill("dodge", "huashan-shenfa");
    map_skill("force", "zixia-shengong");
    map_skill("parry", "huashan-jianfa");
    map_skill("sword", "huashan-jianfa");
    map_skill("unarmed", "poyu-quan");
    set("chat_chance_combat", 40);  
    set("chat_msg_combat", ({
    (: command("unwield sword") :),
    (: command("enable unarmed hunyuan-zhang") :),
    (: command("enable unarmed poyu-quan") :),
    (: command("wield sword") :),
}));
    create_family("��ɽ��", 14, "����");
    setup();
    carry_object("/clone/cloth/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
