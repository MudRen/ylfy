// xihuazic by wyz
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "xihua zi", "zi", "xihua" }) );
        set("gender", "����");
        set("age", 29);
        set("long",
         "�����������ɵĴ�ʦ�֣�Ϊ�˺ô򱧲�ƽ���������
�����ð������ֵġ�\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("shen",20000);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",3000);
        set("max_jingli",2000);
        set("neili", 5500);
        set("max_neili", 3500);
        set("jiali",200);
        set("rank_info/respect", "��ʦ��");        
        set("combat_exp",685900);
 
           set_skill("force", 190);
           set_skill("dodge", 190);
           set_skill("parry", 190);
           set_skill("xuantian-wuji", 190);
           set_skill("sword", 190);
           set_skill("literate",190);
           set_skill("liangyi-jian", 190);
           set_skill("yaoming-dodge", 190);
           set_skill("kunlun-zhang",190);
           set_skill("unarmed",190);
           
           map_skill("dodge", "yaoming-dodge");
           map_skill("force", "xuantian-wuji");
           map_skill("parry", "liangyi-jian");
           map_skill("sword", "liangyi-jian");
           map_skill("unarmed","kunlun-zhang");   
 

    create_family("������", 15, "��ʦ��");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
    command("say �ðɣ��Ҿ��������ˣ��Ժ�Ҫ��Ϊ�����ɳ�������");
    command("recruit " + ob->query("id"));
 }
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
