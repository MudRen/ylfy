//LUCAS 2000-6-18
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������",({"bai zizai","bai"}));
        set("nickname", HIC"��������"NOR);
        set("gender", "����");
        set("age", 55);
        set("long", 
             "������ѩɽ���ɵ������ˣ�ϰ����ԣ�����Ϊ�����书��һ,\n"
             "����Լ��ʮ���꣬�����ܸɣ�������������һ�\n");
        set("attitude", "peaceful");
        set("str", 35);
        set("con", 35);
        set("int", 30);
        set("dex", 30);
        set("per", 25);
        set("neili", 2400000);
        set("max_neili", 1900000);	
        set("jing", 800000);
        set("max_jing", 800000);
        set("qi", 1800000);
        set("max_qi", 1800000);
        set("jiali", 8000);
        set("xyzx_sys/level", 1500);
        set("combat_exp", 3000000);
        set("shen_type", 1);
        set("score", 100000);

        set_skill("unarmed", 2500);
        set_skill("sword", 3000);
        set_skill("force", 3000);
        set_skill("parry", 2500);
        set_skill("dodge", 2500);
        set_skill("literate", 2000);

        set_skill("xueshan-jianfa", 1300);	
        set_skill("bingxue-xinfa", 1300);
        set_skill("snow-zhang", 1300);
        set_skill("snowstep", 1300);

        map_skill("sword", "xueshan-jianfa");	
        map_skill("parry", "xueshan-jianfa");	
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 5, "����");
		set("inquiry", ([
            "ʯ����"   : "������Ҵ������С���˵�,�ҷǰ�������Ƥ���ɡ�",
        ]) );

        setup();
		
        carry_object("/d/lingxiao/obj/icesword")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say ����������,Ҳ����˼�����ң�");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 80 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
    } 
    if ((int)ob->query("shen") < 50000 ) {
         command("say �������������������˾��ӣ��������㡣"); 
                return;
    } 
    if ((int)ob->query("max_neili") < 800 ) {
         command("say ���������㣬�����������񹦵ľ��"); 
                return;
    }
if ((int)ob->query_skill("xueshan-jianfa",1) < 150 ) { 	
        command("say ��ı��Ž���̫����,����������ԭ����ʦ����߰�!"); 
                return;
    }
    if ((int)ob->query_skill("sword",1) < 100 ) {  
        command("say ��Ļ�������̫����,��������߻�������!"); 
                return; 
    }
    command("say �ܺã��ܺ�,���ӽ��������,��������ɡ�");
    command("say ���������û������ˣ�����Ȱ��ҹ��Űɡ�");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", HIW"�����ǳ���"NOR); 
}

