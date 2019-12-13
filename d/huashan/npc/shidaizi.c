// shidaizi.c 
inherit NPC;
void create()
{
    set_name("ʩ����", ({ "shi daizi", "shi", "daizi" }));
    set("long", 
"ʩ������ĸ�������������ͨͨ����˫�۾�����������\n"
"ͬ�������е��ģ��ǻ�ɽ������һ���еĺ��֡�\n");
    set("gender", "����");
    set("age", 28);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 23);
    set("int", 23);
    set("con", 24);
    set("dex", 28);
    
    set("max_qi", 850);
    set("max_jing", 650);
    set("neili", 850);
    set("max_neili", 850);
    set("jiali", 20);
    set("combat_exp", 60000);

    set_skill("force", 50);
    set_skill("dodge", 50);
    set_skill("parry", 60);
    set_skill("sword", 65);
    set_skill("blade", 65);
    set_skill("unarmed", 60);
    set_skill("zixia-shengong", 50);
    set_skill("hunyuan-zhang", 60);
    set_skill("fanliangyi-dao", 60);
    set_skill("huashan-jianfa", 65);
    set_skill("huashan-shenfa", 50);
    map_skill("force", "zixia-shengong");
    map_skill("parry", "huashan-jianfa");
    map_skill("dodge", "huashan-shenfa");
    map_skill("sword", "huashan-jianfa");
    map_skill("blade", "fanliangyi-dao");
    map_skill("unarmed", "hunyuan-zhang");

    create_family("��ɽ��", 14, "����");
    setup();
    carry_object("/clone/cloth/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
