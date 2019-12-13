// masteryue.c
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����Ⱥ", ({ "yue buqun", "master", "yue" }) );
        set("title", "��ɽ����������");
        set("nickname", "���ӽ�");        
        set("gender", "����");
        set("age", 40);
        set("long",
 "�����ǻ�ɽ�ɵ����������ˣ��������˳ơ����ӽ���������Ⱥ��������ȥ\n"
 "�Ǹ����Ƶ������ˣ��������Ǳ�����񣬺���һ����ʦ�ķ緶��\n" );
        set("inquiry", ([
                "��ϼ�ؼ�": "�Բ����������ˣ���ϼ�ؼ������������\n",
        "��а����": "���ʱ�а����,��������а�����书��������ʲô��\n",
                "����": "���������ҵ��鷿͵������ץ������"
]) );        
        set("attitude", "peaceful");
    set("str", 40);
    set("neili",5000000);
    set("max_qi",902000);
	set("max_jing",902000);
    set("int", 65);
    set("con", 60);
    set("per", 28);
    set("dex", 130);
    set("max_neili", 400000);
    set("jiali", 18200);
    set("rank_info/respect", "������");        
    set("combat_exp",1562500);
	set("xyzx_sys/level", 1500);
    set("shen",15000);
    set_skill("force", 2250);
    set_skill("dodge", 2250);
    set_skill("parry", 2250);
    set_skill("sword", 2250);
    set_skill("blade", 2250);
    set_skill("zixia-shengong", 1250);
    set_skill("huashan-jianfa", 1250);
    set_skill("huashan-zhangfa", 1250);
    set_skill("huashan-shenfa", 1250);
    set_skill("hunyuan-zhang", 1250);
    set_skill("pixie-jian", 1250);
    set_skill("poyu-quan", 1250);
    set_skill("fanliangyi-dao", 1250);
    set_skill("literate", 2250);
    set_skill("unarmed", 2250);
    
    map_skill("dodge", "pixie-jian");
    map_skill("force", "zixia-shengong");
    map_skill("parry", "pixie-jian");
    map_skill("sword", "pixie-jian");
    map_skill("unarmed", "hunyuan-zhang");
    map_skill("blade", "fanliangyi-dao");
    create_family("��ɽ��", 13, "������");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") == "Ů��" )
                command("say �Ҳ���Ů���ӵģ����ﻹ�������ʦ�ɡ�");
        else {
                command("nod");
                command("say " + RANK_D->query_respect(ob) + "�պ�سɴ��� ��\n");                
				command("recruit " + ob->query("id") );
             }
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
