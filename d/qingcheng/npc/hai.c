// yu.c

inherit NPC;
//inherit F_SKILL;

void create()
{
        set_name("��׺�", ({ "yu canghai", "yu", "canghai" }));
        set("gender", "����");
        set("age", 52);
        set("long", "�����ΰ�С�������������أ�ٲȻһ�ɴ���ʦ����\n");
        set("class", "taoist");

set("combat_exp", 150000000);	
        set("shen_type", -1);

set_skill("sword", 1300);	
set_skill("pixie-sword", 1300);	
set_skill("unarmed", 1300);	
set_skill("dodge", 1300);	
set_skill("parry", 1300);	
set_skill("wuxue-shenfa", 1300);       	
set("jiali",30000);
set("max_neili",500);	
set("max_qi",300000);
set("max_jing",150000);
set("max_jingli",50000);
set("jingli",50000);
set("neili",10000000);
        map_skill("parry", "pixie-sword");
        map_skill("sword", "pixie-sword");
map_skill("dodge", "wuxue-shenfa");	
        create_family("�����", 7, "����");
set("chat_chance_combat", 300);	
set("chat_msg_combat", ({	
(: perform_action, "sword.cimu" :),	
(: perform_action, "sword.sanlianci" :),	
}) );	
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}


void attempt_apprentice(object ob)	
{
if((int)ob->query_skill("pixie-jian",1) < 450)	
{
command("say ��ı�а�����������ߣ��Ժ��������Ұɡ�");	
return 0;       
}
if((int)ob->query_skill("kuihua-xinfa",1) < 100)	
{
command("say ��Ŀ����ķ��������ߣ��Ժ��������Ұɡ�");	
return 0;       
}
command("say �ðɣ��Ҿ�������������.........!");	
command("chat ������ֶ�������������!�ٺ�...����.....");	
command("recruit " + ob->query("id"));	
ob->set("class","taoism");		
}
